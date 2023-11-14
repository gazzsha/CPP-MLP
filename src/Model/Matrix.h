#ifndef S21_CCP7_MLP_MODEL_MATRIX_H
#define S21_CCP7_MLP_MODEL_MATRIX_H
#include "Network.h"

namespace s21 {

class Matrix : public Network {
 public:
  ~Matrix() = default;
  Matrix(const std::size_t &count_of_hidden_layers_ = 2);

  void TrainNetwork(Input &, const size_t &) final;
  void WriteToFileWeights(const std::string &) final;
  void ReadFromFileWeights(const std::string &) final;
  void TrainWithoutEpochs(Input &) final;
  vector_ PredictVector(vector_ data) final;
  void set_count_hidden_layer(const size_t &) final;
  char PredictLetter(const vector_ &) const noexcept final;
  void CrossValidation(Input &, const size_t &) final;

 private:
  std::unique_ptr<PerceptronMatrix> matrix_network;
};
}  // namespace s21

#endif  // S21_CCP7_MLP_MODEL_LUDIK_H
