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
          answer.push_back(number/255.0f);
          firstValue = false;
        } else {
          one_tests_.push_back(number/255.f);
        }
      }
      all_neurons_tests_.push_back(one_tests_);
      one_tests_.clear();
    }
  }
}
}  // namespace s21

// int main() {
//     s21::Perceptron p;
//     p.GetData("1.txt");
//     for (auto i = 0; i < p.all_neurons_tests_.size(); ++i) {
//         for (auto j = 0; j < p.all_neurons_tests_[i].size(); ++j) {
//             std::cout << p.all_neurons_tests_[i][j] << " ";
//         }
//         std::cout << "\n";
//     }

//     std::cout << '\n';

//     for (auto i = 0; i < p.answer.size(); ++i) {

//         std::cout << p.answer[i] << '\n';
//     }
// }