#ifndef S21_CCP7_MLP_MODEL_MODEL_H
#define S21_CCP7_MLP_MODEL_MODEL_H
#include "Graph.h"
#include "Input.h"
#include "Network.h"
enum class NetworkType { kGraphNetwork = 0, kMatrixNetwork };

namespace s21 {
class Model {
 public:
  Model(const NetworkType& = NetworkType::kGraphNetwork, const size_t& = 2,
        const size_t& = 4);
  ~Model() = default;
  void set_path_file_test(const std::string&);
  void set_path_file_train(const std::string&);
  void set_training_sample_share(const double&) noexcept;
  void set_epochs(const size_t&) noexcept;
  double get_average_accuracy() const noexcept;
  double get_precision() const noexcept;
  double get_recall() const noexcept;
  double get_f_measure() const noexcept;
  double get_time() const noexcept;
  size_t get_epochs() const noexcept;
  vector_ get_average_accuracy_vec() const noexcept;
  vector_ get_precision_vec() const noexcept;
  vector_ get_recall_vec() const noexcept;
  vector_ get_f_measure_vec() const noexcept;
  vector_ get_time_vec() const noexcept;
  double get_average_accuracy_of_full_train() const noexcept;
  double get_average_precision_of_full_train() const noexcept;
  double get_average_recall_of_full_train() const noexcept;
  double get_average_f_measure_of_full_train() const noexcept;
  double get_full_time_of_full_train() const noexcept;
  vector_ get_vector_epochs() const noexcept;
  // void SwitchModel();
  void Train();
  void TrainOnline();
  void Test();
  void WriteToFileWeights(const std::string&);
  void ReadFromFileWeights(const std::string&);
  void CrossValidation(const size_t&);
  void set_count_hidden_layer(const size_t&);
  char PredictLetter(const vector_&) const noexcept;
  vector_ PredictVector(vector_ data) const;

 private:
  Input input_train;
  Input input_test;
  double average_accuracy;
  double precision;
  double recall;
  double f_measure;
  double training_sample_share;
  vector_ average_accuracy_vec;
  vector_ precision_vec;
  vector_ recall_vec;
  vector_ f_measure_vec;
  vector_ time_vec;
  std::chrono::duration<double> time;
  std::chrono::time_point<std::chrono::steady_clock> start =
      std::chrono::steady_clock::now();
  // Network* model;
  std::unique_ptr<Network> model;
  NetworkType type;
  size_t count_hidden_layers;
  size_t epochs;
  void CollectionDataOfMetrics(const vector_& result, const vector_& expect,
                               size_t& tp, size_t& tn, size_t& fp,
                               size_t& fn) const noexcept;
  bool IsRightLetter(const vector_& result,
                     const vector_& expect) const noexcept;
  bool IsRightLetter(const vector_& result, const vector_& expect,
                     const double& elem) const noexcept;
  size_t CountOfTrueResult(const vector_& vec) const noexcept;
  void ClearData();
};
}  // namespace s21
#endif  // S21_CCP7_MLP_MODEL_MODEL_H