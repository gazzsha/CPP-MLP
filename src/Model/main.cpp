#include "neuron.h"

int main() { 
    std::vector<double> v {1,2,3,4,5};
   s21::GraphPreceptron gp(v,2);
   gp.sh_paint();
   gp.DirectPassage();
      gp.sh_paint();
}