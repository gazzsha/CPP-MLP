#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

namespace s21
{

using matrix_ = std::vector<std::vector<double>>;
using vector_ = std::vector<double>;

class Perceptron {

private:
    long long count_tests_ = 0;
    //matrix_ neurons;
public:
    Perceptron() {}
    void GetData(const std::string&);
    matrix_ all_neurons_tests_;
    vector_ one_tests_;
    matrix_ answer;
};


} // namespace s21
