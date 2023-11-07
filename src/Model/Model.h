#ifndef S21_CCP7_MLP_MODEL_MODEL_H
#define S21_CCP7_MLP_MODEL_MODEL_H
#include "neuron.h" 
#include "Input.h"
#include <algorithm>
#include <chrono>
namespace s21 {


class Model { 
    public:
    Model() = delete; 
    Model(const size_t&,const size_t& = 1);
    void set_path_file(const std::string&);
    void write_to_file_weights();
    void read_from_file_weights();
    void set_training_sample_share(const double&) noexcept;
    void train_graph_network();
    void test_graph_network();
    vector_ predict_graph_network(vector_ data);
    private:
    size_t count_hidden_layers; 
    GraphPreceptron graph_network;
    Input input;
    double average_accuracy = 0;
    double precision = 0;
    double recall = 0;
    double f_measure = 0;
    double training_sample_share = 1;
    std::chrono::duration<double> time;
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    size_t epochs;
    bool is_right_letter(const vector_& result,const vector_& expect) const noexcept;
    bool is_right_letter(const vector_& result,const vector_& expect,const double& elem) const; 
    size_t count_of_true_result(const vector_& vec) const noexcept; 
    void collection_data_of_metrics(const vector_&, const vector_& ,size_t&,size_t&,size_t&,size_t&) const noexcept; 

};

}
#endif // S21_CCP7_MLP_MODEL_MODEL_H