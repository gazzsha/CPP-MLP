#include "Graph.h"

namespace s21 {
Graph::Graph(const size_t &count_hidden_layers_)
    : graph_network(std::make_unique<GraphPreceptron>(count_hidden_layers_)) {}

void Graph::TrainNetwork(Input &input_train, const size_t &epochs) {
  input_train.GetData();
  for (size_t i = 0; i < epochs; ++i) {
    for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
      graph_network->train(input_train.all_neurons_tests_[j],
                           input_train.answer[j]);
    }
  }
}

void Graph::TrainWithoutEpochs(Input &input_train) {
  input_train.GetData();
  for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
    graph_network->train(input_train.all_neurons_tests_[j],
                         input_train.answer[j]);
  }
}

vector_ Graph::PredictVector(vector_ input_stat) {
  graph_network->Predict(input_stat);
  return graph_network->get_output_vector();
}

void Graph::set_count_hidden_layer(const size_t &count_) {
  graph_network.reset(std::make_unique<GraphPreceptron>(count_).release());
}

void Graph::WriteToFileWeights(const std::string &path) {
  graph_network->write_to_file_weights(path);
}
void Graph::ReadFromFileWeights(const std::string &path) {
  graph_network->read_from_file_weights(path);
}

char Graph::PredictLetter(const vector_ &input) const noexcept {
  graph_network->Predict(input);
  auto res = graph_network->get_output_vector();
  auto it = std::max_element(res.begin(), res.end());
  auto index = it - res.begin();
  return index + 65;
}

void Graph::CrossValidation(Input &input_train, const size_t &k) {
  input_train.GetData();
  std::vector<std::pair<size_t, size_t>> part;
  size_t part_of_k = input_train.all_neurons_tests_.size() / k;
  for (size_t i = 0; i < k; ++i) {
    part.push_back(
        std::make_pair<size_t, size_t>(i * part_of_k, part_of_k * (i + 1) - 1));
  }
  auto index_predict = k - 1;
  for (size_t l = 0; l < k; ++l) {
    for (size_t j = 0; j < k; ++j) {
      if (j != index_predict) {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          graph_network->train(input_train.all_neurons_tests_[i],
                               input_train.answer[i]);
        }
      } else {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          graph_network->Predict(input_train.all_neurons_tests_[i]);
        }
      }
    }
    --index_predict;
  }
}
}  // namespace s21