#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsView>
#include "paintscene.h"
#include "../../Controller/Controller.h"
QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(s21::Controller * controller_,QWidget *parent = nullptr);
    ~View();

private slots:
    void on_pushLoad_clicked();

    void on_pushClear_clicked();
    void on_pushPredict_clicked();

    void on_push_training_data_clicked();

    void on_push_testing_data_clicked();

    void on_push_train_clicked();

    void on_push_check_testing_data_clicked();


    void on_epochs_count_box_valueChanged(int arg1);

    void on_count_3_hidden_layer_clicked();

    void on_count_4_hidden_layer_clicked();

    void on_count_5_hidden_layer_clicked();

private:
    Ui::View *ui;
    PaintScene * scene;
    s21::Controller * controller;

};
#endif // VIEW_H
