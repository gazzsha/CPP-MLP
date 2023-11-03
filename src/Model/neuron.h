#ifndef S21_CCP7_MLP_MODEL_NEURON_H
#define S21_CCP7_MLP_MODEL_NEURON_H

#include <vector>
#include <iostream> 
#include  <cstdlib>
#include <cmath>


namespace s21 { 

class GraphNeuron { 
  //  GraphNeuron() = delete;
    public:
    double get_rand_number() noexcept;
    double get_value() const noexcept;
    void set_value(const double&) noexcept;
    GraphNeuron(const double&);
    void set_weght_default(const size_t&);
    void PushBackPrev(GraphNeuron*);
    void PushBackNext(GraphNeuron*);
    std::vector<GraphNeuron*>& get_prev(); 
    std::vector<double>& get_weights() noexcept; 
    private:
    double value = 0;
    double error = 0;
    double weights_delta = 0;
    std::vector<GraphNeuron*> prev;
    std::vector<GraphNeuron*> next;
    std::vector <double> weights; 
    friend class GraphLayer;
    friend class GraphPreceptron;
};

class GraphLayer { 
    public:
 //   GraphLayer() = delete;
  //  GraphLayer(const GraphLayer&) = delete;
    GraphLayer(const std::vector<double>&);
    GraphLayer(const size_t&);
    std::vector<GraphNeuron>& get_neurons() noexcept;
    private:
    std::vector<GraphNeuron> neurons;
    friend class GraphPreceptron;
};

class GraphPreceptron{ 
    public:
    GraphPreceptron() = delete;
    GraphPreceptron(const GraphPreceptron&) = delete;
    GraphPreceptron(const std::vector<double>&,const size_t&,const size_t& = 2,const size_t& = 26);
    void InitializingFirstLayer();
    void InitializingShadowLayer();
    void InitializingOutputLayer();
    void DirectPassage();
    void print() { 
        for (int i = 0; i !=  enter_layer.neurons.size(); ++i) 
            std::cout << enter_layer.neurons[i].value;
    } 
    void sh_paint() { 
        for (int i = 0; i < shadow_layers.size(); i++) { 
            for (int j = 0; j != shadow_layers[i].neurons.size(); ++j)
                std::cout << shadow_layers[i].neurons[j].value << shadow_layers[i].neurons[j].weights.size() << "\n";
                 std::cout << "========\n";
        }
       // std::cout << shadow_layers[0].neurons[0].value;
        // for (auto v : shadow_layers[0].get_neurons()[0])
        //   std::cout << v.value << " ";
      
    }
    private: 
    size_t size;
    GraphLayer enter_layer;
    std::vector<GraphLayer> shadow_layers;
    GraphLayer output_layer;
     double get_function_value(const double&) const noexcept;
};


} // namespace s21


#endif // S21_CCP7_MLP_MODEL_NEURON_H