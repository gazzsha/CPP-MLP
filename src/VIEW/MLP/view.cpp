#include "view.h"
#include "./ui_view.h"
#include <QDebug>
#include <QTransform>
View::View(s21::Controller * controller_,QWidget *parent)
    : controller(controller_),
      QMainWindow(parent),
      ui(new Ui::View)
{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,700,700);
}

View::~View()
{
    delete ui;
}


void View::on_pushLoad_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../..","All Files(*.*);; BMP(*.bmp)");
}


void View::on_pushClear_clicked()
{
    scene->clear();

}



void View::on_pushPredict_clicked()
{
    QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
    image.fill(NULL);
    QPainter painter(&image);
    scene->render(&painter);
    QImage image_scaled = image.scaled(28,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QTransform transform;
    transform.rotate(90);
    image_scaled = image_scaled.transformed(transform);
    QImage mirIm = image_scaled.mirrored(true,false);
    mirIm.save("/Users/antoinco/CPP7_MLP-1/src/Image.jpg");
    QVector<QVector<double>> pixel_matrix;
    std::vector<double> img;
    
    for (int x = 0; x < mirIm.width(); x++) {
        for (int y = 0; y < mirIm.height(); y++) {
            QRgb pixel_color = mirIm.pixel(x, y);
            double val = (double(qRed(pixel_color)) + double(qGreen(pixel_color)) + double(qBlue(pixel_color)))/(3.0f * 255.f);
            img.push_back(val);
        }
    }

    qDebug() << img.size() << "\n";
    for (auto v : img) {
        qDebug() << v << " ";
    }
    std::vector<double> res = controller->predict_graph_network(img);
    std::vector<char> symbols;
    for (auto it = 'a'; it <= 'z'; ++it) {
        symbols.push_back(it);
    }
    auto it = std::max_element(res.begin(),res.end());
    auto index = it - res.begin();
    ui->letter_label->setText(QString(symbols[index]));
 //   qDebug() << symbols[index] << index << "\n";

}


void View::on_push_training_data_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../..../Model/","All Files(*.*);; BMP(*.csv)");
    controller->set_path_file(file_path.toStdString());
}


void View::on_push_testing_data_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../..../Model/","All Files(*.*);; BMP(*.csv)");
    controller->set_path_file(file_path.toStdString());
}


void View::on_push_train_clicked()
{
    controller->train_graph_network();
}


void View::on_push_check_testing_data_clicked()
{
    controller->test_graph_network();
    ui->accuracy_label->setText(QString::number(controller->get_average_accuracy()));
    ui->precision_label->setText(QString::number(controller->get_precision()));
    ui->recall_label->setText(QString::number(controller->get_recall()));
    ui->f_mera_label->setText(QString::number(controller->get_f_measure()));
    ui->time_label->setText(QString::number(controller->get_time()));
}


void View::on_epochs_count_box_valueChanged(int arg1)
{
    controller->set_epochs(static_cast<size_t>(arg1));
}


void View::on_count_3_hidden_layer_clicked()
{
    controller->set_hidden_layers(static_cast<size_t>(3));
}


void View::on_count_4_hidden_layer_clicked()
{
 controller->set_hidden_layers(static_cast<size_t>(4));
}


void View::on_count_5_hidden_layer_clicked()
{
    controller->set_hidden_layers(static_cast<size_t>(5));
}

