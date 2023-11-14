#include "Matrix.h"

namespace s21 {
Matrix::Matrix(const std::size_t &count_of_hidden_layers_)
    : matrix_network(
          std::make_unique<PerceptronMatrix>(count_of_hidden_layers_)) {}

void Matrix::TrainNetwork(Input &input_train, const size_t &epochs) {
  input_train.GetData();
  for (size_t i = 0; i < epochs; ++i) {
    for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
      matrix_network->Train(input_train.all_neurons_tests_[j],
                            input_train.answer[j]);
    }
  }
}

void Matrix::WriteToFileWeights(const std::string &path) {
  std::ofstream file(path);
  for (size_t i = 0; i < matrix_network->layers.size() - 1; ++i) {
    for (size_t j = 0; j < matrix_network->layers[i + 1].size_; ++j) {
      for (size_t k = 0; k < matrix_network->layers[i].size_; ++k) {
        file << matrix_network->layers[i].weight_[k][j] << ' ';
      }
      file << '\n';
    }
  }
}

void Matrix::ReadFromFileWeights(const std::string &path) {
  std::ifstream istrm(path);
  if (!istrm.is_open()) throw std::runtime_error("Failed to open file");

  for (size_t i = 0; i < matrix_network->layers.size() - 1; ++i) {
    for (size_t j = 0; j < matrix_network->layers[i + 1].size_; ++j) {
      for (size_t k = 0; k < matrix_network->layers[i].size_; ++k) {
        istrm >> matrix_network->layers[i].weight_[k][j];
      }
    }
  }
}

void Matrix::TrainWithoutEpochs(Input &input_train) {
  input_train.GetData();
  for (size_t j = 0; j < input_train.all_neurons_tests_.size(); ++j) {
    matrix_network->Train(input_train.all_neurons_tests_[j],
                          input_train.answer[j]);
  }
}

vector_ Matrix::PredictVector(vector_ data) {
  matrix_network->layers[0].neurons = data;
  matrix_network->ActivateNeurons();
  return matrix_network->layers[matrix_network->layers.size() - 1].neurons;
}

void Matrix::set_count_hidden_layer(const size_t &count_) {
  matrix_network.reset(std::make_unique<PerceptronMatrix>(count_).release());
}

char Matrix::PredictLetter(const vector_ &input) const noexcept {
  matrix_network->layers[0].neurons = input;
  matrix_network->ActivateNeurons();
  auto res = matrix_network->layers[matrix_network->layers.size() - 1].neurons;
  auto it = std::max_element(res.begin(), res.end());
  auto index = it - res.begin();
  return index + 65;
}

void Matrix::CrossValidation(Input &input_train, const size_t &k) {
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
          matrix_network->Train(input_train.all_neurons_tests_[i],
                                input_train.answer[i]);
        }
      } else {
        for (auto i = part[j].first; i <= part[j].second; ++i) {
          matrix_network->layers[0].neurons = input_train.all_neurons_tests_[i];
          matrix_network->ActivateNeurons();
        }
      }
    }
    --index_predict;
  }
}

}  // namespace s21