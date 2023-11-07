#include "Model.h"
int main() {
  // std::vector<double> v {1,2,3,4,5};
  // std::vector<double> o
  // {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0};
  // s21::GraphPreceptron gp(3,2);
  //  gp.print();
  //    gp.sh_paint();
  //    //gp.DirectPassage();
  //    gp.forward();
  //     //gp.print();
  //     gp.train(o);
  //     gp.TrainAll();
  //       gp.forward();
  // std::vector<std::vector<double>> m { {0,0,0},
  // {0,0,1},
  // {0,1,0},
  // {0,1,1},
  // {1,0,0},
  // {1,0,1},
  // {1,1,0},
  // {1,1,1}
  // };
  //  //    gp.paint();
  //    std::vector<std::vector<double>> ex { {0},{1},{0},{0},{1},{1},{0},{0}};
  //   for (int i = 0; i < 5000; i++) {
  //   for (size_t j = 0; j < m.size(); ++j) {
  //   gp.train(m[j],ex[j]);
  //   }
  //  }

  //     std::vector<double> a = {0,0,1};
  //  std::vector<double> b = {14};
  // gp.InputEnterLayer(a);
  //  gp.Predict(a);
  //  gp.paint();
  //    gp.train(a,b);
  //  gp.paint();
  //     // gp.print();

  //  s21::Perceptron pr;
  //   std::vector<double> ans;
  //   pr.GetData("../emnist-letters-train.csv");
  //   //   for (auto v : pr.answer) {
  //   //    ans.push_back(v);
  //   // }
  //   s21::GraphPreceptron gp(2);
  //   //   for (int i = 0; i <  2 ;i++) {
  //   //   for (size_t j = 0; j < pr.all_neurons_tests_.size(); ++j) {
  //   //     gp.train(pr.all_neurons_tests_[j], pr.answer[j]);
  //   //   //  gp.Predict(pr.all_neurons_tests_[j]);
  //   //   }
  //   // }
  //   //  s21::Perceptron pr_;
  //   // pr_.GetData("../emnist-letters-test.csv");
  //   // gp.Predict(pr_.all_neurons_tests_[0]);
  //   std::vector<double> vec = gp.get_output_vector();
  //   for (auto v : vec) {
  //     std::cout << v << "\n";
  //   }
  //   std::cout << "============\n";
  //  //gp.paint();
  // s21::Model model;
  // // model.set_path_file("../emnist-letters-train.csv");
  // // model.train_graph_network();
  // model.set_path_file("../emnist-letters-test.csv");
  // // model.test_graph_network();
  // // model.write_to_file_weights();
  // model.read_from_file_weights();
  // model.test_graph_network();
  std::ifstream istrm("../2.txt");
  if (!istrm.is_open()) throw std::runtime_error("Failed to open file");
  for (auto i = 0; i < 28; i++) {
    for (auto j = 0; j < 28; j++) {
      double val;
      istrm >> val;
      std::cout << (val > 0 ? 1 : 0);
    }
    std::cout << "\n";
  }
}