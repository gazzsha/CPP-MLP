#include "neuron.h"

namespace s21{ 
    double GraphNeuron::get_rand_number() noexcept { 
        return ((double) std::rand() / (RAND_MAX));
    }
    double GraphNeuron::get_value() const noexcept { 
        return value;
    }
    void GraphNeuron::set_value(const double& val) noexcept { 
        value = val;
    }
    void GraphNeuron::set_weght_default(const size_t& sz) { 
       for (size_t i = 0; i < sz; ++i) { 
            weights.push_back(get_rand_number());
       } 
    }  
      std::vector<double>&  GraphNeuron::get_weights() noexcept { 
        return weights;
    }
     void GraphNeuron::PushBackPrev(GraphNeuron* prev_) { 
        prev.push_back(prev_);
     }
     void GraphNeuron::PushBackNext(GraphNeuron* next_) { 
        next.push_back(next_);
     }
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
    std::vector<GraphNeuron>& GraphLayer::get_neurons() noexcept { 
        return neurons;
    }

     std::vector<GraphNeuron*>& GraphNeuron::get_prev() { 
        return prev;
     }

    void GraphPreceptron::InitializingFirstLayer() { 
     for (size_t i = 0; i <  enter_layer.get_neurons().size(); ++i) { 
            for (size_t j = 0; j < shadow_layers[0].get_neurons().size(); ++j) {
            enter_layer.get_neurons()[i].PushBackNext(&shadow_layers[0].get_neurons()[j]);
            }
        }
        for (size_t i = 0; i < shadow_layers[0].get_neurons().size(); ++i) { 
            for (size_t j = 0; j < enter_layer.get_neurons().size(); ++j) { 
                shadow_layers[0].get_neurons()[i].PushBackPrev(&enter_layer.get_neurons()[j]);
            }
        }
    }

     void GraphPreceptron::InitializingShadowLayer() {
            for (size_t i = 0; i < size - 1; ++i ) {
            for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) { 
                for (size_t k = 0; k < shadow_layers[i + 1].get_neurons().size(); ++k) 
                shadow_layers[i].get_neurons()[j].PushBackNext(&shadow_layers[i+1].get_neurons()[k]);
            } 
        }
        for (size_t i = size - 1; i != 0; --i ) {
            for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) { 
                for (size_t k = 0; k < shadow_layers[i - 1].get_neurons().size(); ++k) 
                shadow_layers[i].get_neurons()[j].PushBackPrev(&shadow_layers[i-1].get_neurons()[k]);
            } 
        }
     }

     void GraphPreceptron::InitializingOutputLayer() { 
                for (size_t i = 0; i <output_layer.get_neurons().size(); ++i) { 
            for (size_t j = 0; j < shadow_layers[size - 1].get_neurons().size(); ++j) { 
               output_layer.get_neurons()[i].PushBackPrev(&shadow_layers[size - 1].get_neurons()[j]);
            }
        }
        for (size_t i = 0; i < shadow_layers[size - 1].get_neurons().size(); ++i) { 
            for (size_t j = 0; j <output_layer.get_neurons().size(); ++j) { 
                shadow_layers[size - 1].get_neurons()[i].PushBackNext(&output_layer.get_neurons()[j]);
            }
        }
        for (size_t i = 0; i < output_layer.get_neurons().size(); ++i) { 
            output_layer.get_neurons()[i].set_weght_default(shadow_layers[size - 1].get_neurons().size());
        }
     }

    // sz - кол-во скрытых слоев, N - кол-во нейронов в скрытом слое
    GraphPreceptron::GraphPreceptron(const std::vector<double>& vec,const size_t& n,const size_t& sz,const size_t& output_size): size(sz),enter_layer(vec),output_layer(output_size) {
        for (size_t i = 0; i < sz; ++i) {
        shadow_layers.emplace_back(n);
            for (size_t j = 0; j <  shadow_layers[i].get_neurons().size(); ++j) {
            shadow_layers[i].get_neurons()[j].set_weght_default( !i ? enter_layer.get_neurons().size() : n);
            }
        }
        InitializingFirstLayer();
        InitializingShadowLayer();
        InitializingOutputLayer();
    }

     double GraphPreceptron::get_function_value(const double& val) const noexcept { 
        return 1.0f/(1.0f + std::exp(-val)); 
     }

    void GraphPreceptron::DirectPassage() {
        // for (size_t i = 0; i < shadow_layers[0].get_neurons().size(); ++i) {
        //     double sum = 0; 
        //     for (size_t j = 0; j < shadow_layers[0].get_neurons()[i].get_weights().size(); ++j) {
        //         sum += (shadow_layers[0].get_neurons()[i].get_weights()[j] * enter_layer.get_neurons()[j].get_value());
        //     }
        //     shadow_layers[0].get_neurons()[i].set_value(get_function_value(sum));
        // }
        // for (size_t i = 1; i != size; ++i) {
        //     for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) { 
        //         double sum = 0; 
        //         for (size_t k = 0; k < shadow_layers[i].get_neurons()[j].get_weights().size(); ++k) { 
        //             sum += (shadow_layers[i].get_neurons()[j].get_weights()[k] * shadow_layers[i - 1].get_neurons()[k].get_value());
        //         }
        //         shadow_layers[i].get_neurons()[j].set_value(get_function_value(sum));
        //     }
        // }
        // for (size_t i = 0; i != output_layer.get_neurons().size(); ++i) { 
        //     double sum = 0;
        //     for (size_t j = 0; j != output_layer.get_neurons()[i].get_weights().size(); ++j) { 
        //         sum += output_layer.get_neurons()[i].get_weights()[j] * shadow_layers[size - 1].get_neurons()[j].get_value();
        //     }
        //     output_layer.get_neurons()[i].set_value(get_function_value(sum));
        // }
        for (size_t i = 0; i < shadow_layers[0].get_neurons().size(); ++i) {
            double sum = 0; 
            for (size_t j = 0; j < shadow_layers[0].get_neurons()[i].get_prev().size(); ++j) {
                 sum += (shadow_layers[0].get_neurons()[i].get_prev()[j])->get_value() * shadow_layers[0].get_neurons()[i].get_weights()[j];
            }
            shadow_layers[0].get_neurons()[i].set_value(get_function_value(sum));
        }

          for (size_t i = 1; i != size; ++i) {
            for (size_t j = 0; j < shadow_layers[i].get_neurons().size(); ++j) { 
                double sum = 0; 
                for (size_t k = 0; k < shadow_layers[i].get_neurons()[j].get_weights().size(); ++k) { 
                    sum += (shadow_layers[i].get_neurons()[j].get_weights()[k] * shadow_layers[i - 1].get_neurons()[k].get_value());
                }
                shadow_layers[i].get_neurons()[j].set_value(get_function_value(sum));
            }
        }
        for (size_t i = 0; i != output_layer.get_neurons().size(); ++i) { 
            double sum = 0;
            for (size_t j = 0; j != output_layer.get_neurons()[i].get_weights().size(); ++j) { 
                sum += output_layer.get_neurons()[i].get_weights()[j] * shadow_layers[size - 1].get_neurons()[j].get_value();
            }
            output_layer.get_neurons()[i].set_value(get_function_value(sum));
        }
        
    }
} //namespace s21