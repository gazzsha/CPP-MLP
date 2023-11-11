#include "Controller.h"

namespace s21 {

Controller::Controller(Model* model_) : model(model_) {}
void Controller::set_path_file_test(const std::string& file_path) {
  model->set_path_file_test(file_path);
}
void Controller::set_path_file_train(const std::string& file_path) {
  model->set_path_file_train(file_path);
}
void Controller::WriteToFileWeights(const std::string& path) {
  model->write_to_file_weights(path);
}
void Controller::LoadFromFileWeights(const std::string& path) {
  model->read_from_file_weights(path);
}
void Controller::set_traininh_sample_share(const double& shape) noexcept {
  model->set_training_sample_share(shape);
}
void Controller::TrainGraphNetwork() { model->train_graph_network(); }
void Controller::TestGraphNetwork() { model->test_graph_network(); }
vector_ Controller::predict_graph_network(vector_ data) {
  return model->predict_graph_network(data);
}
char Controller::PredictLetter(const vector_& input) const noexcept {
  return model->predict_letter(input);
}
double Controller::get_average_accuracy() const noexcept {
  return model->get_average_accuracy();
}
double Controller::get_precision() const noexcept {
  return model->get_precision();
}
double Controller::get_recall() const noexcept { return model->get_recall(); }
double Controller::get_f_measure() const noexcept {
  return model->get_f_measure();
}
void Controller::set_epochs(const size_t& val) noexcept {
  model->set_epochs(val);
}
double Controller::get_time() const noexcept { return model->get_time(); }
void Controller::set_hidden_layers(const size_t& val) {
  model->set_count_hidden_layer(val);
}
size_t Controller::get_epochs() const noexcept { return model->get_epochs(); }
void Controller::TrainWithoutEpochsGraphNetwork() {
  model->TrainWithoutEpochs();
}

vector_ Controller::get_average_accuracy_vec() const noexcept {
  return model->get_average_accuracy_vec();
}
vector_ Controller::get_precision_vec() const noexcept {
  return model->get_precision_vec();
}
vector_ Controller::get_recall_vec() const noexcept {
  return model->get_recall_vec();
}
vector_ Controller::get_f_measure_vec() const noexcept {
  return model->get_f_measure_vec();
}
vector_ Controller::get_time_vec() const noexcept {
  return model->get_time_vec();
}
}  // namespace s21
