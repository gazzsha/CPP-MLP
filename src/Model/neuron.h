#ifndef S21_CCP7_MLP_MODEL_NEURON_H
#define S21_CCP7_MLP_MODEL_NEURON_H
#define SIZE_END 26
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
namespace s21 {

class GraphNeuron {
 public:
  double get_rand_number() noexcept;
  double get_value() const noexcept;
  void set_error(const double&) noexcept;
  double get_error() const noexcept;
  void set_weights_delta(const double&) noexcept;
  double get_weights_delta() const noexcept;
  void set_value(const double&) noexcept;
  GraphNeuron(const double&);
  void set_weght_default(const size_t&);
  void PushBackPrev(GraphNeuron*);
  void PushBackNext(GraphNeuron*);
  std::vector<GraphNeuron*>& get_prev();
  std::vector<double>& get_weights() noexcept;
  std::vector<GraphNeuron*> prev;
  std::vector<GraphNeuron*> next;
  std::vector<double> weights;

 private:
  double value = 0;
  double error = 0;
  double weights_delta = 0;
  double get_function_value(const double& val) const noexcept;
  // friend class GraphLayer;
  // friend class GraphPreceptron;
};

class GraphLayer {
 public:
  GraphLayer(const std::vector<double>&);
  GraphLayer(const size_t&);
  std::vector<GraphNeuron>& get_neurons() noexcept;

 private:
  std::vector<GraphNeuron> neurons;
  //  friend class GraphPreceptron;
};

class GraphPreceptron {
 public:
  GraphPreceptron() = delete;
  GraphPreceptron(const GraphPreceptron&) = delete;
  GraphPreceptron(const size_t& = 3, const size_t& = 768, const size_t& = 128,
                  const size_t& = 26);
  //  void DirectPassage();
  void Predict(const std::vector<double>&);
  void train(const std::vector<double>&, const std::vector<double>&,
             const double& = 0.15);
  void TrainAll(const double& = 0.15);
  std::vector<double> get_output_vector() noexcept;
  void write_to_file_weights(const std::string&);
  void read_from_file_weights(const std::string&);

 private:
  size_t size;
  GraphLayer enter_layer;
  std::vector<GraphLayer> shadow_layers;
  GraphLayer output_layer;
  double get_function_value(const double&) const noexcept;
  void InputEnterLayer(const std::vector<double>&);
  void InitializingFirstLayer();
  void InitializingShadowLayer();
  void InitializingOutputLayer();
  GraphNeuron* BeginOutputLayer() noexcept;
};

}  // namespace s21

#endif  // S21_CCP7_MLP_MODEL_NEURON_H
