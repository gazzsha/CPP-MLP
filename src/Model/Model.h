#ifndef S21_CCP7_MLP_MODEL_MODEL_H
#define S21_CCP7_MLP_MODEL_MODEL_H
#include <algorithm>
#include <chrono>

#include "Input.h"
#include "neuron.h"
namespace s21 {

class Model {
 public:
  Model();
  ~Model();
  void set_path_file_test(const std::string&);
  void set_path_file_train(const std::string&);
  void write_to_file_weights(const std::string&);
  void read_from_file_weights(const std::string&);
  void set_training_sample_share(const double&) noexcept;
  void train_graph_network();
  void TrainWithoutEpochs();
  void test_graph_network();
  vector_ predict_graph_network(vector_ data);
  double get_average_accuracy() const noexcept;
  double get_precision() const noexcept;
  double get_recall() const noexcept;
  double get_f_measure() const noexcept;
  void set_epochs(const size_t&) noexcept;
  size_t get_epochs() const noexcept;
  double get_time() const noexcept;
  void set_count_hidden_layer(const size_t&);
  char predict_letter(const vector_&) const noexcept;
  vector_ get_average_accuracy_vec() const noexcept;
  vector_ get_precision_vec() const noexcept;
  vector_ get_recall_vec() const noexcept;
  vector_ get_f_measure_vec() const noexcept;
  vector_ get_time_vec() const noexcept;

 private:
  size_t count_hidden_layers = 3;
  GraphPreceptron* graph_network;
  Input input_train;
  Input input_test;
  double average_accuracy = 0;
  double precision = 0;
  double recall = 0;
  double f_measure = 0;
  double training_sample_share = 1;
  std::chrono::duration<double> time;
  std::chrono::time_point<std::chrono::steady_clock> start =
      std::chrono::steady_clock::now();
  size_t epochs = 2;
  vector_ average_accuracy_vec;
  vector_ precision_vec;
  vector_ recall_vec;
  vector_ f_measure_vec;
  vector_ time_vec;
  bool is_right_letter(const vector_& result,
                       const vector_& expect) const noexcept;
  bool is_right_letter(const vector_& result, const vector_& expect,
                       const double& elem) const;
  size_t count_of_true_result(const vector_& vec) const noexcept;
  void collection_data_of_metrics(const vector_&, const vector_&, size_t&,
                                  size_t&, size_t&, size_t&) const noexcept;
};

}  // namespace s21
#endif  // S21_CCP7_MLP_MODEL_MODEL_H