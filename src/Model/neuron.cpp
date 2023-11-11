#include "neuron.h"

namespace s21 {
double GraphNeuron::get_rand_number() noexcept {
  std::random_device
      rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(-1, 1);
  return dist(gen);
}
double GraphNeuron::get_value() const noexcept { return value; }
double GraphNeuron::get_error() const noexcept { return error; }
double GraphNeuron::get_weights_delta() const noexcept { return weights_delta; }
void GraphNeuron::set_value(const double& val) noexcept { value = val; }
void GraphNeuron::set_error(const double& err) noexcept { error = err; }
void GraphNeuron::set_weights_delta(const double& w) noexcept {
  weights_delta = w;
}
double GraphNeuron::get_function_value(const double& val) const noexcept {
  return 1.0f / (1.0f + std::exp(-val));
}
void GraphNeuron::set_weght_default(const size_t& sz) {
  for (size_t i = 0; i < sz; ++i) {
    weights.push_back(get_rand_number());
  }
}
std::vector<double>& GraphNeuron::get_weights() noexcept { return weights; }
void GraphNeuron::PushBackPrev(GraphNeuron* prev_) { prev.push_back(prev_); }
void GraphNeuron::PushBackNext(GraphNeuron* next_) { next.push_back(next_); }
GraphNeuron::GraphNeuron(const double& d) : value(d) {}
GraphLayer::GraphLayer(const std::vector<double>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    neurons.emplace_back(vec[i]);
  }
}
GraphLayer::GraphLayer(const size_t& n) {
  for (size_t i = 0; i < n; ++i) {
    neurons.emplace_back(0);
  }
}
std::vector<GraphNeuron>& GraphLayer::get_neurons() noexcept { return neurons; }

std::vector<GraphNeuron*>& GraphNeuron::get_prev() { return prev; }

void GraphPreceptron::InitializingFirstLayer() {
  for (size_t i = 0; i < enter_layer.get_neurons().size(); ++i) {
    for (size_t j = 0; j < shadow_layers[0].get_neurons().size(); ++j) {
      enter_layer.get_neurons()[i].PushBackNext(
          &shadow_layers[0].get_neurons()[j]);
    }
  }
  for (size_t i = 0; i < shadow_layers[0].get_neurons().size(); ++i) {
    for (size_t j = 0; j < enter_layer.get_neurons().size(); ++j) {
      shadow_layers[0].get_neurons()[i].PushBackPrev(
          &enter_layer.get_neurons()[j]);
    }
  }
}

void GraphPreceptron::InitializingShadowLayer() {
  for (size_t i = 0; i < size - 1; ++i) {
    for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) {
      for (size_t k = 0; k < shadow_layers[i + 1].get_neurons().size(); ++k)
        shadow_layers[i].get_neurons()[j].PushBackNext(
            &shadow_layers[i + 1].get_neurons()[k]);
    }
  }
  for (size_t i = size - 1; i != 0; --i) {
    for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) {
      for (size_t k = 0; k < shadow_layers[i - 1].get_neurons().size(); ++k)
        shadow_layers[i].get_neurons()[j].PushBackPrev(
            &shadow_layers[i - 1].get_neurons()[k]);
    }
  }
}

void GraphPreceptron::InitializingOutputLayer() {
  for (size_t i = 0; i < output_layer.get_neurons().size(); ++i) {
    for (size_t j = 0; j < shadow_layers[size - 1].get_neurons().size(); ++j) {
      output_layer.get_neurons()[i].PushBackPrev(
          &shadow_layers[size - 1].get_neurons()[j]);
    }
  }
  for (size_t i = 0; i < shadow_layers[size - 1].get_neurons().size(); ++i) {
    for (size_t j = 0; j < output_layer.get_neurons().size(); ++j) {
      shadow_layers[size - 1].get_neurons()[i].PushBackNext(
          &output_layer.get_neurons()[j]);
    }
  }
  for (size_t i = 0; i < output_layer.get_neurons().size(); ++i) {
    output_layer.get_neurons()[i].set_weght_default(
        shadow_layers[size - 1].get_neurons().size());
  }
}

// sz - кол-во скрытых слоев, N - кол-во нейронов в скрытом слое
GraphPreceptron::GraphPreceptron(const size_t& sz, const size_t& size_enter,
                                 const size_t& n, const size_t& output_size)
    : size(sz), enter_layer(size_enter), output_layer(output_size) {
  for (size_t i = 0; i < sz; ++i) {
    shadow_layers.emplace_back(n);
    for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) {
      shadow_layers[i].get_neurons()[j].set_weght_default(
          !i ? enter_layer.get_neurons().size() : n);
    }
  }
  InitializingFirstLayer();
  InitializingShadowLayer();
  InitializingOutputLayer();
}

double GraphPreceptron::get_function_value(const double& val) const noexcept {
  return 1.0f / (1.0f + std::exp(-val));
  // return val;
}

// void GraphPreceptron::DirectPassage() {
// for (size_t i = 0; i < shadow_layers[0].get_neurons().size(); ++i) {
//     double sum = 0;
//     for (size_t j = 0; j <
//     shadow_layers[0].get_neurons()[i].get_weights().size(); ++j) {
//         sum += (shadow_layers[0].get_neurons()[i].get_weights()[j] *
//         enter_layer.get_neurons()[j].get_value());
//     }
//     shadow_layers[0].get_neurons()[i].set_value(get_function_value(sum));
// }
// for (size_t i = 1; i != size; ++i) {
//     for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) {
//         double sum = 0;
//         for (size_t k = 0; k <
//         shadow_layers[i].get_neurons()[j].get_weights().size(); ++k) {
//             sum += (shadow_layers[i].get_neurons()[j].get_weights()[k] *
//             shadow_layers[i - 1].get_neurons()[k].get_value());
//         }
//         shadow_layers[i].get_neurons()[j].set_value(get_function_value(sum));
//     }
// }
// for (size_t i = 0; i != output_layer.get_neurons().size(); ++i) {
//     double sum = 0;
//     for (size_t j = 0; j !=
//     output_layer.get_neurons()[i].get_weights().size(); ++j) {
//         sum += output_layer.get_neurons()[i].get_weights()[j] *
//         shadow_layers[size - 1].get_neurons()[j].get_value();
//     }
//     output_layer.get_neurons()[i].set_value(get_function_value(sum));
// }
//     for (size_t i = 0; i < shadow_layers[0].get_neurons().size(); ++i) {
//         double sum = 0;
//         for (size_t j = 0; j <
//         shadow_layers[0].get_neurons()[i].get_prev().size(); ++j) {
//              sum +=
//              (shadow_layers[0].get_neurons()[i].get_prev()[j])->get_value() *
//              shadow_layers[0].get_neurons()[i].get_weights()[j];
//         }
//         shadow_layers[0].get_neurons()[i].set_value(get_function_value(sum));
//     }
//       for (size_t i = 1; i != size; ++i) {
//         for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) {
//             double sum = 0;
//             for (size_t k = 0; k <
//             shadow_layers[i].get_neurons()[j].get_weights().size(); ++k) {
//                 sum += (shadow_layers[i].get_neurons()[j].get_weights()[k] *
//                 shadow_layers[i - 1].get_neurons()[k].get_value());
//             }
//             shadow_layers[i].get_neurons()[j].set_value(get_function_value(sum));
//         }
//     }
//     for (size_t i = 0; i != output_layer.get_neurons().size(); ++i) {
//         double sum = 0;
//         for (size_t j = 0; j !=
//         output_layer.get_neurons()[i].get_weights().size(); ++j) {
//             sum += output_layer.get_neurons()[i].get_weights()[j] *
//             shadow_layers[size - 1].get_neurons()[j].get_value();
//         }
//         output_layer.get_neurons()[i].set_value(get_function_value(sum));
//     }
// }

std::vector<double> GraphPreceptron::get_output_vector() noexcept {
  std::vector<double> temp;
  for (size_t i = 0; i < output_layer.get_neurons().size(); ++i) {
    temp.push_back(output_layer.get_neurons()[i].get_value());
  }
  return temp;
}

void GraphPreceptron::Predict(const std::vector<double>& input_stat) {
  InputEnterLayer(input_stat);
  GraphNeuron* cur = &enter_layer.get_neurons()[0];
  while (!(cur->next).empty()) {
    for (size_t i = 0; i != cur->next.size(); ++i) {
      cur = cur->next[i];
      double sum = 0;
      for (size_t j = 0; j != cur->prev.size(); ++j) {
        sum += cur->prev[j]->get_value() * cur->weights[j];
      }
      cur->set_value(get_function_value(sum));
      cur = cur->prev[0];
    }
    cur = cur->next[0];
  }
}

GraphNeuron* GraphPreceptron::BeginOutputLayer() noexcept {
  return &output_layer.get_neurons()[0];
}

void GraphPreceptron::InputEnterLayer(const std::vector<double>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    enter_layer.get_neurons()[i].set_value(vec[i]);
  }
}

void GraphPreceptron::train(const std::vector<double>& input_stat,
                            const std::vector<double>& expect,
                            const double& learning_rate) {
  Predict(input_stat);
  GraphNeuron* cur = BeginOutputLayer();
  cur = cur->prev[0];
  for (size_t i = 0; i < cur->next.size(); ++i) {
    cur = cur->next[i];
    cur->set_error(cur->get_value() - expect[i]);
    cur->set_weights_delta(cur->get_error() * cur->get_value() *
                           (1.0f - cur->get_value()));
    for (size_t j = 0; j < cur->get_weights().size(); ++j) {
      cur->get_weights()[j] =
          cur->get_weights()[j] -
          cur->prev[j]->get_value() * cur->get_weights_delta() * learning_rate;
    }
    cur = cur->prev[0];
  }
  cur = cur->prev[0];
  for (size_t i = 0; i != cur->next.size(); ++i) {
    cur = cur->next[i];
    double error_ = 0;
    for (size_t j = 0; j != cur->next.size(); ++j) {
      error_ +=
          cur->next[j]->get_weights()[i] * cur->next[j]->get_weights_delta();
    }
    cur->set_error(error_);
    cur = cur->prev[0];
  }
  TrainAll(learning_rate);
}

void GraphPreceptron::TrainAll(const double& learning_rate) {
  GraphNeuron* cur = BeginOutputLayer();
  cur = cur->prev[0];
  while (!cur->prev.empty()) {
    cur = cur->prev[0];
    for (size_t i = 0; i < cur->next.size(); ++i) {
      cur = cur->next[i];
      cur->set_weights_delta(cur->get_error() * cur->get_value() *
                             (1 - cur->get_value()));
      for (size_t j = 0; j < cur->get_weights().size(); ++j) {
        cur->get_weights()[j] = cur->get_weights()[j] -
                                cur->prev[j]->get_value() *
                                    cur->get_weights_delta() * learning_rate;
      }
      cur = cur->prev[0];
    }
    if (!cur->prev.empty()) {
      cur = cur->prev[0];
      for (size_t i = 0; i != cur->next.size(); ++i) {
        cur = cur->next[i];
        double error_ = 0;
        for (size_t j = 0; j != cur->next.size(); ++j) {
          error_ += cur->next[j]->get_weights()[i] *
                    cur->next[j]->get_weights_delta();
        }
        cur->set_error(error_);
        cur = cur->prev[0];
      }
      cur = cur->next[0];
    }
  }
}

void GraphPreceptron::write_to_file_weights(const std::string& path) {
  std::ofstream file(path);
  GraphNeuron* cur = &enter_layer.get_neurons()[0];
  while (!(cur->next).empty()) {
    for (size_t i = 0; i != cur->next.size(); ++i) {
      cur = cur->next[i];
      for (size_t j = 0; j != cur->get_weights().size(); ++j) {
        file << cur->get_weights()[j] << " ";
      }
      file << "\n";
      cur = cur->prev[0];
    }
    cur = cur->next[0];
  }
}

void GraphPreceptron::read_from_file_weights(const std::string& path) {
  std::ifstream istrm(path);
  if (!istrm.is_open()) throw std::runtime_error("Failed to open file");
  GraphNeuron* cur = &enter_layer.get_neurons()[0];
  while (!(cur->next).empty()) {
    for (size_t i = 0; i != cur->next.size(); ++i) {
      cur = cur->next[i];
      for (size_t j = 0; j != cur->get_weights().size(); ++j) {
        istrm >> cur->get_weights()[j];
      }
      cur = cur->prev[0];
    }
    cur = cur->next[0];
  }
  // if (istrm.bad()) {
  //   throw std::runtime_error("I/O error while reading - badbit is true");
  // } else if (istrm.fail())
  //   throw std::runtime_error("Failbit is true");
}

}  // namespace s21