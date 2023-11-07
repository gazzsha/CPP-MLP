#include "Input.h"
#include <exception>
namespace s21 {

void Input::clear() { 
    one_tests_.clear();
    answer.clear();
    all_neurons_tests_.clear();
}

void Input::GetData() {
    clear();
  std::ifstream input;
  input.open(file_path);
  if (!input.is_open()) throw std::invalid_argument("Wrong File path!");
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

