#ifndef S21_CCP7_MLP_CONTROLLER_CONTROLLER_H
#define S21_CCP7_MLP_CONTROLLER_CONTROLLER_H
#include "../Model/Model.h"

namespace s21 {
class Controller {
 public:
  Controller() = delete;
  Controller(Model* model_);
  void set_path_file(const std::string& file_path);
  void write_to_file_weights_graph();
  void set_traininh_sample_share(const double& shape) noexcept;
  void train_graph_network();
  void test_graph_network();
  vector_ predict_graph_network(vector_ data);
  double get_average_accuracy() const noexcept;
  double get_precision() const noexcept;
  double get_recall() const noexcept;
  double get_f_measure() const noexcept;
  double get_time() const noexcept;
  void set_epochs(const size_t& val) noexcept;
  void set_hidden_layers(const size_t&);

 private:
  Model* model;
};
}  // namespace s21

#endif  // S21_CCP7_MLP_CONTROLLER_CONTROLLER_H