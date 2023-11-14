#include "Model.h"
namespace s21 {
Model::Model(const NetworkType &type_, const size_t &count_of_hidden_layers_,
             const size_t &epochs_)
    : input_train(),
      input_test(),
      average_accuracy(0),
      precision(0),
      recall(0),
      f_measure(0),
      training_sample_share(1),
      average_accuracy_vec(),
      precision_vec(),
      recall_vec(),
      f_measure_vec(),
      time_vec(),
      model(std::make_unique<Graph>(count_of_hidden_layers_)),
      type(type_),
      count_hidden_layers(count_of_hidden_layers_),
      epochs(epochs_) {}
void Model::set_path_file_test(const std::string &path_file) {
  input_test.file_path = path_file;
  average_accuracy_vec.clear();
  precision_vec.clear();
  recall_vec.clear();
  f_measure_vec.clear();
  time_vec.clear();
}
void Model::SwitchModel() {
  type == NetworkType::kGraphNetwork
      ? (type = NetworkType::kMatrixNetwork,
         model.reset(std::make_unique<Matrix>(count_hidden_layers).release()))
      : model.reset(std::make_unique<Graph>(count_hidden_layers).release());
}
void Model::set_path_file_train(const std::string &path_file) {
  input_train.file_path = path_file;
}

void Model::set_training_sample_share(const double &val) noexcept {
  training_sample_share = val;
}

void Model::set_epochs(const size_t &val) noexcept { epochs = val; }

double Model::get_average_accuracy() const noexcept { return average_accuracy; }

vector_ Model::get_average_accuracy_vec() const noexcept {
  return average_accuracy_vec;
}

double Model::get_precision() const noexcept { return precision; }
double Model::get_recall() const noexcept { return recall; }
double Model::get_f_measure() const noexcept { return f_measure; }
double Model::get_time() const noexcept { return time.count(); }
size_t Model::get_epochs() const noexcept { return epochs; }
vector_ Model::get_precision_vec() const noexcept { return precision_vec; }
vector_ Model::get_recall_vec() const noexcept { return recall_vec; }
vector_ Model::get_f_measure_vec() const noexcept { return f_measure_vec; }
vector_ Model::get_time_vec() const noexcept { return time_vec; }
double Model::get_average_accuracy_of_full_train() const noexcept {
  double sum = 0;
  for (const auto &v : average_accuracy_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_average_precision_of_full_train() const noexcept {
  double sum = 0;
  for (const auto &v : precision_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_average_recall_of_full_train() const noexcept {
  double sum = 0;
  for (const auto &v : recall_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_average_f_measure_of_full_train() const noexcept {
  double sum = 0;
  for (const auto &v : f_measure_vec) sum += v;
  return sum / static_cast<double>(get_epochs());
}
double Model::get_full_time_of_full_train() const noexcept {
  double sum = 0;
  for (const auto &v : time_vec) sum += v;
  return sum;
}
vector_ Model::get_vector_epochs() const noexcept {
  vector_ temp;
  for (size_t i = 0; i < epochs; ++i) {
    temp.push_back(i + 1);
  }
  return temp;
}

void Model::ClearData() {
  average_accuracy_vec.clear();
  precision_vec.clear();
  recall_vec.clear();
  f_measure_vec.clear();
  time_vec.clear();
}

void Model::Train() { model->TrainNetwork(input_train, epochs); }
void Model::TrainOnline() {
  ClearData();
  for (size_t i = 0; i < epochs; ++i) {
    start = std::chrono::steady_clock::now();
    model->TrainWithoutEpochs(input_train);
    Test();
  }
}
void Model::Test() {
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
    vector_ result = model->PredictVector(input_test.all_neurons_tests_[j]);
    if (IsRightLetter(result, input_test.answer[j])) count_of_true++;
    count_of_all += CountOfTrueResult(result);
    CollectionDataOfMetrics(result, input_test.answer[j], true_positiv,
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

  // std::cout << "True: " << count_of_true << "\n"
  //           << "All: " << input_test.answer.size() << "\n"
  //           << "average_accuracy: " << accuracy << "\n"
  //           << "All > 0.5: " << count_of_all << "\n"
  //           << "Acuracy" << average_accuracy << "\n"
  //           << "Precision " << precision << "\n"
  //           << "Recall " << recall << "\n"
  //           << "F - mera " << f_measure << "\n"
  //           << "Time: " << time.count() << "\n";
}

bool Model::IsRightLetter(const vector_ &result, const vector_ &expect,
                          const double &elem) const noexcept {
  auto it_result = std::find(result.begin(), result.end(), elem);
  auto index_result = std::distance(result.begin(), it_result);
  return *(expect.begin() + index_result);
}

bool Model::IsRightLetter(const vector_ &result,
                          const vector_ &expect) const noexcept {
  auto it_result = std::max_element(result.begin(), result.end());
  auto it_expect = std::max_element(expect.begin(), expect.end());
  auto index_result = std::distance(result.begin(), it_result);
  auto index_expect = std::distance(expect.begin(), it_expect);
  return (index_result == index_expect);
}

void Model::CollectionDataOfMetrics(const vector_ &result,
                                    const vector_ &expect, size_t &tp,
                                    size_t &tn, size_t &fp,
                                    size_t &fn) const noexcept {
  for (const auto &elem : result) {
    if (elem > 0.5) {
      if (IsRightLetter(result, expect, elem))
        ++tp;
      else
        ++fp;
    } else {
      if (IsRightLetter(result, expect, elem))
        ++fn;
      else
        ++tn;
    }
  }
}
size_t Model::CountOfTrueResult(const vector_ &vec) const noexcept {
  size_t temp_count = 0;
  for (const auto &v : vec)
    if (v > 0.5) temp_count++;
  return temp_count;
}

void Model::WriteToFileWeights(const std::string &file_path) {
  model->WriteToFileWeights(file_path);
}
void Model::ReadFromFileWeights(const std::string &file_path) {
  model->ReadFromFileWeights(file_path);
}
void Model::CrossValidation(const size_t &k) {
  model->CrossValidation(input_train, k);
}
char Model::PredictLetter(const vector_ &input) const noexcept {
  return model->PredictLetter(input);
}

void Model::set_count_hidden_layer(const size_t &count) {
  model->set_count_hidden_layer(count);
}
vector_ Model::PredictVector(vector_ data) const {
  return model->PredictVector(data);
}
}  // namespace s21