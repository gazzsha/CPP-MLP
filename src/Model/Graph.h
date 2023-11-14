#ifndef S21_CCP7_MLP_MODEL_GRAPH_H
#define S21_CCP7_MLP_MODEL_GRAPH_H
#include "Network.h"

namespace s21 {

class Graph : public Network {
 public:
  Graph(const size_t &count_hidden_layers_ = 2);
  ~Graph() = default;
  void TrainNetwork(Input &, const size_t &) override;
  void WriteToFileWeights(const std::string &) override;
  void ReadFromFileWeights(const std::string &) override;
  void TrainWithoutEpochs(Input &) override;
  vector_ PredictVector(vector_ data) override;
  void set_count_hidden_layer(const size_t &) override;
  char PredictLetter(const vector_ &) const noexcept override;
  void CrossValidation(Input &, const size_t &) override;

 private:
  std::unique_ptr<GraphPreceptron> graph_network;
};

}  // namespace s21
#endif  // S21_CCP7_MLP_MODEL_GRAPH_H