#include "mm.h"

namespace s21 {

void Perceptron::GetData(const std::string& file_name_) {
  std::ifstream input;
  input.open(file_name_);

  if (!input.is_open()) return;

  while (input) {
    std::string line;
    if (getline(input, line)) {
      std::istringstream lineStream(line);
      std::string value;
      bool firstValue = true;

      while (getline(lineStream, value, ',')) {
        double number = std::stod(value);

        if (firstValue) {
          std::vector<double> ans_(26,0);
          ans_[number - 1] = 1;
          answer.push_back(ans_);
          firstValue = false;
        } else {
          one_tests_.push_back(number/255.0f);
        }
      }
      all_neurons_tests_.push_back(one_tests_);
      one_tests_.clear();
    }
  }
}
}  // namespace s21

