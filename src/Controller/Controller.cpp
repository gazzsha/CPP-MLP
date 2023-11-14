#include "Controller.h"

namespace s21 {

Controller::Controller(Model *model_) : model(model_) {}
void Controller::set_path_file_test(const std::string &file_path) {
  model->set_path_file_test(file_path);
}
void Controller::set_path_file_train(const std::string &file_path) {
  model->set_path_file_train(file_path);
}
void Controller::WriteToFileWeights(const std::string &path) {
  model->WriteToFileWeights(path);
}
void Controller::LoadFromFileWeights(const std::string &path) {
  model->ReadFromFileWeights(path);
}
void Controller::set_traininh_sample_share(const double &shape) noexcept {
  model->set_training_sample_share(shape);
}
void Controller::Train() { model->Train(); }
void Controller::Test() { model->Test(); }
vector_ Controller::PredictVector(vector_ data) {
  return model->PredictVector(data);
}
char Controller::PredictLetter(const vector_ &input) const noexcept {
  return model->PredictLetter(input);
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
void Controller::set_epochs(const size_t &val) noexcept {
  model->set_epochs(val);
}
double Controller::get_time() const noexcept { return model->get_time(); }
void Controller::set_hidden_layers(const size_t &val) {
  model->set_count_hidden_layer(val);
}
size_t Controller::get_epochs() const noexcept { return model->get_epochs(); }
void Controller::TrainOnline() { model->TrainOnline(); }

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
double Controller::get_average_accuracy_of_full_train() const noexcept {
  return model->get_average_accuracy_of_full_train();
}
double Controller::get_average_precision_of_full_train() const noexcept {
  return model->get_average_precision_of_full_train();
}
double Controller::get_average_recall_of_full_train() const noexcept {
  return model->get_average_recall_of_full_train();
}
double Controller::get_average_f_measure_of_full_train() const noexcept {
  return model->get_average_f_measure_of_full_train();
}
double Controller::get_full_time_of_full_train() const noexcept {
  return model->get_full_time_of_full_train();
}
vector_ Controller::get_vector_epochs() const noexcept {
  return model->get_vector_epochs();
}
void Controller::CrossValidation(const size_t &k) { model->CrossValidation(k); }

void Controller::SwitchModel() { model->SwitchModel(); }
}  // namespace s21
