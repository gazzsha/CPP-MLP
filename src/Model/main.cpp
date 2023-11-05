#include "neuron.h"
#include "../mm.h"
int main() {
  // std::vector<double> v {1,2,3,4,5};
  // std::vector<double> o
  // {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0};
  // s21::GraphPreceptron gp(3, 2);
  // //  gp.print();
  // //    gp.sh_paint();
  // //    //gp.DirectPassage();
  // //    gp.forward();
  // //     //gp.print();
  // //     gp.train(o);
  // //     gp.TrainAll();
  // //       gp.forward();
  // std::vector<std::vector<double>> m{{0, 0, 0}, {0, 0, 1}, {0, 1, 0},
  //                                    {0, 1, 1}, {1, 0, 0}, {1, 0, 1},
  //                                    {1, 1, 0}, {1, 1, 1}};
  // //    gp.paint();
  // std::vector<std::vector<double>> ex{{0}, {1}, {0}, {0}, {1}, {1}, {0}, {0}};
  // for (int i = 0; i < 5000; i++) {
  //   for (size_t i = 0; i < m.size(); ++i) {
  //     gp.train(m[i], ex[i]);
  //     gp.Predict(m[i]);
  //   }
  // }

  // std::vector<double> a = {0, 0, 1};
  // //  std::vector<double> b = {14};
  // gp.Predict(a);
  // std::vector<double> vec = gp.get_output_vector();
  // for (auto v : vec) {
  //   std::cout << v;
  // }
  // gp.paint();
  //     // gp.print();
  s21::Perceptron pr;
  std::vector<double> ans;
  pr.GetData("../emnist-letters-train.csv");
    for (auto v : pr.answer) {
     ans.push_back(v);
  }
  s21::GraphPreceptron gp(784,64);
    for (int i = 0; i <  2;i++) {
    for (size_t j = 0; j < pr.all_neurons_tests_.size(); ++j) {
      gp.train(pr.all_neurons_tests_[j], ans);
      gp.Predict(pr.all_neurons_tests_[j]);
    }
  }
   s21::Perceptron pr_;
  pr_.GetData("../emnist-letters-test.csv");
  gp.Predict(pr_.all_neurons_tests_[0]);
   std::vector<double> vec = gp.get_output_vector();
  for (auto v : vec) {
    std::cout << v << "\n";
  }
  gp.paint();

}