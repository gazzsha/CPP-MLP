#ifndef S21_CCP7_MLP_CONTROLLER_CONTROLLER_H
#define S21_CCP7_MLP_CONTROLLER_CONTROLLER_H
#include "../Model/Model.h"

namespace s21 {
class Controller {
 public:
  Controller() = delete;
  Controller(Model* model_);
  void set_path_file_train(const std::string& file_path);
  void set_path_file_test(const std::string& file_path);
  void WriteToFileWeights(const std::string&);
  void LoadFromFileWeights(const std::string&);
  void set_traininh_sample_share(const double& shape) noexcept;
  void TrainGraphNetwork();
  void TrainWithoutEpochsGraphNetwork();
  void TestGraphNetwork();
  vector_ predict_graph_network(vector_ data);
  double get_average_accuracy() const noexcept;
  double get_precision() const noexcept;
  double get_recall() const noexcept;
  double get_f_measure() const noexcept;
  double get_time() const noexcept;
  void set_epochs(const size_t& val) noexcept;
  void set_hidden_layers(const size_t&);
  char PredictLetter(const vector_&) const noexcept;
  vector_ get_average_accuracy_vec() const noexcept;
  vector_ get_precision_vec() const noexcept;
  vector_ get_recall_vec() const noexcept;
  vector_ get_f_measure_vec() const noexcept;
  vector_ get_time_vec() const noexcept;
  size_t get_epochs() const noexcept;
  double get_average_accuracy_of_full_train() const noexcept;
  double get_average_precision_of_full_train() const noexcept;
  double get_average_recall_of_full_train() const noexcept;
  double get_average_f_measure_of_full_train() const noexcept;
  double get_full_time_of_full_train() const noexcept;
  vector_ get_vector_epochs() const noexcept;
  void CrossValidationGraph(const size_t&);

 private:
  Model* model;
};
}  // namespace s21

#endif  // S21_CCP7_MLP_CONTROLLER_CONTROLLER_H
