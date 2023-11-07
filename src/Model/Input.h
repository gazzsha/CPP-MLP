#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

namespace s21
{

using matrix_ = std::vector<std::vector<double>>;
using vector_ = std::vector<double>;

class Input {
public:
    void clear();
    void GetData();
    matrix_ all_neurons_tests_;
    vector_ one_tests_;
    matrix_ answer;
    std::string file_path; 
};


} // namespace s21
