#include "neuron.h"

int main() {
  // std::vector<double> v {1,2,3,4,5};
  // std::vector<double> o
  // {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0};
  s21::GraphPreceptron gp(3, 2);
  //  gp.print();
  //    gp.sh_paint();
  //    //gp.DirectPassage();
  //    gp.forward();
  //     //gp.print();
  //     gp.train(o);
  //     gp.TrainAll();
  //       gp.forward();
  std::vector<std::vector<double>> m{{0, 0, 0}, {0, 0, 1}, {0, 1, 0},
                                     {0, 1, 1}, {1, 0, 0}, {1, 0, 1},
                                     {1, 1, 0}, {1, 1, 1}};
  //    gp.paint();
  std::vector<std::vector<double>> ex{{0}, {1}, {0}, {0}, {1}, {1}, {0}, {0}};
  for (int i = 0; i < 5000; i++) {
    for (size_t i = 0; i < m.size(); ++i) {
      gp.train(m[i], ex[i]);
      gp.Predict(m[i]);
    }
  }

  std::vector<double> a = {0, 0, 1};
  //  std::vector<double> b = {14};
  gp.Predict(a);
  std::vector<double> vec = gp.get_output_vector();
  for (auto v : vec) {
    std::cout << v;
  }
  gp.paint();
  //     // gp.print();
}