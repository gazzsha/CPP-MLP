#include "Model.h"

namespace s21 {
Model::Model()
    : graph_network(new GraphPreceptron(count_hidden_layers)),
      input(),
      time() {}
void Model::train_graph_network() {
  start = std::chrono::steady_clock::now();
  input.GetData();
  for (size_t i = 0; i < epochs; ++i) {
    for (size_t j = 0; j < input.all_neurons_tests_.size(); ++j) {
      graph_network->train(input.all_neurons_tests_[j], input.answer[j]);
    }
  }
}
void Model::set_training_sample_share(const double& val) noexcept {
  training_sample_share = val;
}
vector_ Model::predict_graph_network(vector_ input_stat) {
  graph_network->Predict(input_stat);
  return graph_network->get_output_vector();
}

void Model::set_count_hidden_layer(const size_t& val) {
  count_hidden_layers = val;
  GraphPreceptron* cur = graph_network;
  GraphPreceptron* new_network = new GraphPreceptron(count_hidden_layers);
  graph_network = new_network;
  delete cur;
}
void Model::set_path_file(const std::string& path_file) {
  input.file_path = path_file;
}
double Model::get_time() const noexcept { return time.count(); }
void Model::test_graph_network() {
  input.GetData();
  size_t count_of_true = 0;
  size_t count_of_all = 0;
  size_t true_positiv = 0;
  size_t true_negative = 0;
  size_t false_positive = 0;
  size_t false_negative = 0;
  for (size_t j = 0; j < static_cast<size_t>(input.all_neurons_tests_.size() *
                                             training_sample_share);
       ++j) {
    graph_network->Predict(input.all_neurons_tests_[j]);
    vector_ result = graph_network->get_output_vector();
    if (is_right_letter(result, input.answer[j])) count_of_true++;
    count_of_all += count_of_true_result(result);
    collection_data_of_metrics(result, input.answer[j], true_positiv,
                               true_negative, false_positive, false_negative);
  }

  double accuracy = static_cast<double>(count_of_true) /
                    static_cast<double>(input.answer.size());
  average_accuracy = (static_cast<double>(true_positiv + true_negative)) /
                     (static_cast<double>(true_positiv + true_negative +
                                          false_positive + false_negative));
  precision =
      static_cast<double>(true_positiv) /
      (static_cast<double>(true_positiv) + static_cast<double>(false_positive));
  recall =
      static_cast<double>(true_positiv) /
      (static_cast<double>(true_positiv) + static_cast<double>(false_negative));
  f_measure = 2 * (recall * precision) / (recall + precision);
  const auto end{std::chrono::steady_clock::now()};
  time = end - start;

  std::cout << "True: " << count_of_true << "\n"
            << "All: " << input.answer.size() << "\n"
            << "average_accuracy: " << accuracy << "\n"
            << "All > 0.5: " << count_of_all << "\n"
            << "Acuracy" << average_accuracy << "\n"
            << "Precision " << precision << "\n"
            << "Recall " << recall << "\n"
            << "F - mera " << f_measure << "\n"
            << "Time: " << time.count() << "\n";
}

void Model::collection_data_of_metrics(const vector_& result,
                                       const vector_& expect, size_t& tp,
                                       size_t& tn, size_t& fp,
                                       size_t& fn) const noexcept {
  for (const auto& elem : result) {
    if (elem > 0.5) {
      if (is_right_letter(result, expect, elem))
        ++tp;
      else
        ++fp;
    } else {
      if (is_right_letter(result, expect, elem))
        ++fn;
      else
        ++tn;
    }
  }
}
Model::~Model() { delete graph_network; }
void Model::write_to_file_weights(const std::string& path) {
  graph_network->write_to_file_weights(path);
}
void Model::read_from_file_weights(const std::string& path) {
  graph_network->read_from_file_weights(path);
}
bool Model::is_right_letter(const vector_& result, const vector_& expect,
                            const double& elem) const {
  auto it_result = std::find(result.begin(), result.end(), elem);
  auto index_result = std::distance(result.begin(), it_result);
  return *(expect.begin() + index_result);
}

bool Model::is_right_letter(const vector_& result,
                            const vector_& expect) const noexcept {
  auto it_result = std::max_element(result.begin(), result.end());
  auto it_expect = std::max_element(expect.begin(), expect.end());
  auto index_result = std::distance(result.begin(), it_result);
  auto index_expect = std::distance(expect.begin(), it_expect);
  return (index_result == index_expect);
}

size_t Model::count_of_true_result(const vector_& vec) const noexcept {
  size_t temp_count = 0;
  for (const auto& v : vec)
    if (v > 0.5) temp_count++;
  return temp_count;
}
double Model::get_average_accuracy() const noexcept { return average_accuracy; }
double Model::get_precision() const noexcept { return precision; }
double Model::get_recall() const noexcept { return recall; }
double Model::get_f_measure() const noexcept { return f_measure; }
void Model::set_epochs(const size_t& val) noexcept { epochs = val; }
char Model::predict_letter(const vector_& input) const noexcept {
  graph_network->Predict(input);
  auto res = graph_network->get_output_vector();
  auto it = std::max_element(res.begin(), res.end());
  auto index = it - res.begin();
  return index + 65;
}
}  // namespace s21