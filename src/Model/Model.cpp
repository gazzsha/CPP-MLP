#include "Model.h"

namespace s21 {
Model::Model()
    : graph_network(new GraphPreceptron(count_hidden_layers)),
      input_train(),
      input_test(),
      time() {}
void Model::train_graph_network() {
  start = std::chrono::steady_clock::now();
  input_train.GetData();
  for (size_t i = 0; i < epochs; ++i) {
    for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
      graph_network->train(input_train.all_neurons_tests_[j],
                           input_train.answer[j]);
    }
  }
}

void Model::TrainWithoutEpochs() {
  start = std::chrono::steady_clock::now();
  input_train.GetData();
  for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
    graph_network->train(input_train.all_neurons_tests_[j],
                         input_train.answer[j]);
  }
}

size_t Model::get_epochs() const noexcept { return epochs; }
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
void Model::set_path_file_test(const std::string& path_file) {
  input_test.file_path = path_file;
  average_accuracy_vec.clear();
  precision_vec.clear();
  recall_vec.clear();
  f_measure_vec.clear();
  time_vec.clear();
}
void Model::set_path_file_train(const std::string& path_file) {
  input_train.file_path = path_file;
}
double Model::get_time() const noexcept { return time.count(); }
void Model::test_graph_network() {
  input_test.GetData();
  size_t count_of_true = 0;
  size_t count_of_all = 0;
  size_t true_positiv = 0;
  size_t true_negative = 0;
  size_t false_positive = 0;
  size_t false_negative = 0;
  for (size_t j = 0;
       j < static_cast<size_t>(input_test.all_neurons_tests_.size() *
                               training_sample_share);
       ++j) {
    graph_network->Predict(input_test.all_neurons_tests_[j]);
    vector_ result = graph_network->get_output_vector();
    if (is_right_letter(result, input_test.answer[j])) count_of_true++;
    count_of_all += count_of_true_result(result);
    collection_data_of_metrics(result, input_test.answer[j], true_positiv,
                               true_negative, false_positive, false_negative);
  }

  double accuracy = static_cast<double>(count_of_true) /
                    static_cast<double>(input_test.answer.size());
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
  average_accuracy_vec.push_back(average_accuracy);
  precision_vec.push_back(precision);
  recall_vec.push_back(recall);
  f_measure_vec.push_back(f_measure);
  time_vec.push_back(time.count());

  std::cout << "True: " << count_of_true << "\n"
            << "All: " << input_test.answer.size() << "\n"
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

vector_ Model::get_average_accuracy_vec() const noexcept {
  return average_accuracy_vec;
}
vector_ Model::get_precision_vec() const noexcept { return precision_vec; }
vector_ Model::get_recall_vec() const noexcept { return recall_vec; }
vector_ Model::get_f_measure_vec() const noexcept { return f_measure_vec; }
vector_ Model::get_time_vec() const noexcept { return time_vec; }
double Model::get_average_accuracy_of_full_train() const noexcept {
  double sum = 0;
  for (const auto& v : average_accuracy_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_average_precision_of_full_train() const noexcept {
  double sum = 0;
  for (const auto& v : precision_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_average_recall_of_full_train() const noexcept {
  double sum = 0;
  for (const auto& v : recall_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_average_f_measure_of_full_train() const noexcept {
  double sum = 0;
  for (const auto& v : f_measure_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_full_time_of_full_train() const noexcept {
  double sum = 0;
  for (const auto& v : time_vec) sum += v;
  return sum;
}
vector_ Model::get_vector_epochs() const noexcept {
  vector_ temp;
  for (size_t i = 0; i < epochs; ++i) {
    temp.push_back(i + 1);
  }
  return temp;
}

void Model::cross_validation(const size_t& k) {
  input_train.GetData();
  std::vector<std::pair<size_t, size_t>> part;
  size_t part_of_k = input_train.all_neurons_tests_.size() / k;
  for (size_t i = 0; i < k; ++i) {
    part.push_back(
        std::make_pair<size_t, size_t>(i * part_of_k, part_of_k * (i + 1) - 1));
  }
  auto index_predict = k - 1;
  for (size_t l = 0; l < k; ++l) {
    for (size_t j = 0; j < k; ++j) {
      if (j != index_predict) {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          graph_network->train(input_train.all_neurons_tests_[i],
                               input_train.answer[i]);
        }
      } else {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          graph_network->Predict(input_train.all_neurons_tests_[i]);
        }
      }
    }
    --index_predict;
  }
}
}  // namespace s21