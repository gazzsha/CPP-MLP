#ifndef S21_CCP7_MLP_MODEL_GRAPH_H
#define S21_CCP7_MLP_MODEL_GRAPH_H
#include "Network.h"

namespace s21 {

class Graph : public Network {
 public:
  Graph(const size_t& count_hidden_layers_ = 2);
  ~Graph() = default;
  // void set_path_file_test(const std::string&);
  // void set_path_file_train(const std::string&);
  void WriteToFileWeights(const std::string&) override;
  void ReadFromFileWeights(const std::string&) override;
  // void set_training_sample_share(const double&) noexcept;
  void TrainNetwork(Input&, const size_t&) override;
  void TrainWithoutEpochs(Input&) override;
  vector_ PredictVector(vector_ data) override;
  // double get_average_accuracy() const noexcept;
  // double get_precision() const noexcept;
  //  double get_recall() const noexcept;
  //  double get_f_measure() const noexcept;
  // void set_epochs(const size_t&) noexcept;
  //  size_t get_epochs() const noexcept;
  // double get_time() const noexcept;
  void set_count_hidden_layer(const size_t&) override;
  char PredictLetter(const vector_&) const noexcept override;
  // vector_ get_average_accuracy_vec() const noexcept;
  //   vector_ get_precision_vec() const noexcept;
  //   vector_ get_recall_vec() const noexcept;
  //   vector_ get_f_measure_vec() const noexcept;
  //   vector_ get_time_vec() const noexcept;
  //   double get_average_accuracy_of_full_train() const noexcept;
  //   double get_average_precision_of_full_train() const noexcept;
  //   double get_average_recall_of_full_train() const noexcept;
  //   double get_average_f_measure_of_full_train() const noexcept;
  //   double get_full_time_of_full_train() const noexcept;
  // vector_ get_vector_epochs() const noexcept;
  void CrossValidation(Input&, const size_t&) override;
  //   bool IsRightLetter(const vector_& result,
  //                      const vector_& expect) const noexcept override;
  //   bool IsRightLetter(const vector_& result, const vector_& expect,
  //                      const double& elem) const override;
  //   size_t count_of_true_result(const vector_& vec) const noexcept;
  //   void CollectionDataOfMetrics(const vector_&, const vector_&, size_t&,
  //   size_t&,
  //                                size_t&, size_t&) const noexcept;

 private:
  // GraphPreceptron* graph_network;
  std::unique_ptr<GraphPreceptron> graph_network;
};

}  // namespace s21
#endif  // S21_CCP7_MLP_MODEL_GRAPH_H