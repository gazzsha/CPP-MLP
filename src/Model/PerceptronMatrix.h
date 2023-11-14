#ifndef S21_CCP7_MLP_MODEL_PERCEPTRON_MATRIX_H
#define S21_CCP7_MLP_MODEL_PERCEPTRON_MATRIX_H

#define COUNT_OF_NEURONS_OF_THE_INPUT_LAYER 784
#define COUNT_OF_NEURONS_OF_THE_HIDDEN_LAYER 128
#define COUNT_OF_NEURONS_OF_THE_OUTPUT_LAYER 26
#define BIAS 1
#define LEARNING_RATE 0.09
#define EPOCH 4

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#include "Input.h"
namespace s21 {

class Layer {
 private:
 public:
  Layer(std::size_t, std::size_t, std::size_t);
  void SetRandomWeght();

  std::size_t size_;       // count neurons
  std::size_t next_size_;  // count neurons of prev layer
  vector_ neurons;         // vector of neurons
  matrix_ weight_;         // matrix of weight
  vector_ weight_delta_;   // delta at the previous iteration
  vector_ error;
};

class PerceptronMatrix {
 private:
 public:
  PerceptronMatrix(const std::size_t &count_of_hidden_layers = 2);
  void ActivateNeurons();
  double ActivateFunction(const double &);
  double DerivativeActivateFunction(const double &);
  // bool CheckAnswer(const int&);
  void ErrorGradientOutputLayer(vector_ &);
  void BackPropagation(std::size_t, vector_ &);
  void ChangeWeights(std::size_t);
  void Train(vector_ &, vector_ &);

  std::vector<Layer> layers;
};

}  // namespace s21

#endif  // S21_CCP7_MLP_MODEL_PERCEPTRON_MATRIX_H
