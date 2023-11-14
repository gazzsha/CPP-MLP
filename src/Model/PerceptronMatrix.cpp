#include "PerceptronMatrix.h"

namespace s21 {

Layer::Layer(std::size_t size, std::size_t next_size, std::size_t sigma_size)
    : size_(size), next_size_(next_size) {
  weight_delta_.resize(sigma_size);
  neurons.resize(size);
  SetRandomWeght();
}

void Layer::SetRandomWeght() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> distribution(-1.0, 1.0);
  error.resize(size_);
  weight_.resize(size_);
  for (std::size_t i = 0; i < size_; ++i) {
    weight_[i].resize(next_size_);
    for (std::size_t j = 0; j < next_size_; ++j)
      weight_[i][j] = distribution(gen);
  }
}

PerceptronMatrix::PerceptronMatrix(const std::size_t &count_of_hidden_layers) {
  layers.push_back(Layer(COUNT_OF_NEURONS_OF_THE_INPUT_LAYER,
                         COUNT_OF_NEURONS_OF_THE_HIDDEN_LAYER,
                         COUNT_OF_NEURONS_OF_THE_INPUT_LAYER));

  for (size_t i = 0; i < count_of_hidden_layers; ++i) {
    layers.push_back(Layer(COUNT_OF_NEURONS_OF_THE_HIDDEN_LAYER,
                           (i == count_of_hidden_layers - 1)
                               ? COUNT_OF_NEURONS_OF_THE_OUTPUT_LAYER
                               : COUNT_OF_NEURONS_OF_THE_HIDDEN_LAYER,
                           COUNT_OF_NEURONS_OF_THE_HIDDEN_LAYER));
  }

  layers.push_back(Layer(COUNT_OF_NEURONS_OF_THE_OUTPUT_LAYER, 0,
                         COUNT_OF_NEURONS_OF_THE_OUTPUT_LAYER));
}

void PerceptronMatrix::ActivateNeurons() {
  for (size_t i = 1; i < layers.size(); ++i) {
    for (size_t j = 0; j < layers[i].size_; ++j) {
      double sum = 0.0f;
      for (size_t k = 0; k < layers[i - 1].size_; ++k)
        sum += layers[i - 1].neurons[k] * layers[i - 1].weight_[k][j];
      layers[i].neurons[j] = ActivateFunction(sum);
    }
  }
}

double PerceptronMatrix::ActivateFunction(const double &x) {
  return 1.0f / (1.0f + std::exp(-x));
}

double PerceptronMatrix::DerivativeActivateFunction(const double &x) {
  return x * (1 - x);
}

void PerceptronMatrix::ErrorGradientOutputLayer(vector_ &answer) {
  for (size_t i = 0; i < layers[layers.size() - 1].size_; ++i) {
    layers[layers.size() - 1].error[i] =
        (layers[layers.size() - 1].neurons[i] - answer[i]);
    layers[layers.size() - 1].weight_delta_[i] =
        (layers[layers.size() - 1].error[i]) *
        DerivativeActivateFunction(layers[layers.size() - 1].neurons[i]);
  }
}

void PerceptronMatrix::BackPropagation(std::size_t layer_index_,
                                       vector_ &answer) {
  if (layer_index_ == layers.size() - 1) {
    ErrorGradientOutputLayer(answer);
  } else {
    for (size_t i = 0; i < layers[layer_index_].size_; ++i) {
      for (size_t j = 0; j < layers[layer_index_ + 1].size_; ++j) {
        layers[layer_index_].weight_[i][j] =
            layers[layer_index_].weight_[i][j] -
            layers[layer_index_].neurons[i] *
                layers[layer_index_ + 1].weight_delta_[j] * LEARNING_RATE;
      }
    }
    for (size_t i = 1; i < layers[layer_index_].size_; ++i) {
      double error = 0;
      for (size_t j = 0; j < layers[layer_index_ + 1].size_; ++j)
        error += layers[layer_index_ + 1].weight_delta_[j] *
                 layers[layer_index_].weight_[i][j];
      layers[layer_index_].error[i] = error;
      layers[layer_index_].weight_delta_[i] =
          DerivativeActivateFunction(layers[layer_index_].neurons[i]) *
          layers[layer_index_].error[i];
    }
  }
}

void PerceptronMatrix::Train(vector_ &neurons_train_, vector_ &answer) {
  layers[0].neurons = neurons_train_;
  ActivateNeurons();
  for (int k = layers.size() - 1; k >= 0; --k) BackPropagation(k, answer);
}

}  // namespace s21