#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  s21::Model model;
  s21::Controller controller(&model);
  QApplication a(argc, argv);
  View w(&controller);
  w.show();
  return a.exec();
}
