#ifndef S21_CCP7_MLP_MODEL_INPUT_H
#define S21_CCP7_MLP_MODEL_INPUT_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace s21 {

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

}  // namespace s21
#endif  // S21_CCP7_MLP_MODEL_INPUT_H