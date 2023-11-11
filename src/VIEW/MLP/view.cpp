#include "view.h"
#include "./ui_view.h"
#include <QDebug>
#include <QTransform>
#include <QFile>
#include <QTextStream>
View::View(s21::Controller * controller_,QWidget *parent)
    : controller(controller_),
      QMainWindow(parent),
      ui(new Ui::View)
{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->epochs_count_box->setValue(2);

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
    image.fill(0);
    QPainter painter(&image);
    scene->render(&painter);
    QImage new_image = image.scaled(28,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QTransform transform;
    transform.rotate(90);
    new_image = new_image.transformed(transform);
    new_image = new_image.mirrored(true,false);
    //new_image.save(".../../../../../image.png");
    new_image.save("../../../../../image.png");
    std::vector<double> coordinates = ImageToVector(new_image);
    ui->letter_label->setText(QString(controller->predict_letter(coordinates)));
    
    //    for (int x = 0; x < 28 ; x++) {
    //        for (int y = 0; y < 28; y++) {
    //            //QRgb pixel_color = mirIm.pixel(x, y);
    //            //double val = static_cast<int>((double(qRed(pixel_color)) + double(qGreen(pixel_color)) + double(qBlue(pixel_color)))/(3.0f));
    //            double val = new_image.pixelColor(y, x).value();
    //            img.push_back(val);
    //        }
    //    }

    //    qDebug() << img.size() << "\n";
    //    QFile fileOut("D:/school_21_projects/CPP7_MLP-1/src/out.txt");
    //    if ( fileOut.open((QIODevice::Append | QIODevice::Text))) {
    //    QTextStream ws(&fileOut);
    //    for (auto v : img) {
    //        ws << v << " ";

    //    }
    //} else qDebug() << "error";
    //    fileOut.close();

//    std::vector<double> res = controller->predict_graph_network(coordinates);
//    std::vector<char> symbols;
//    for (auto it = 'a'; it <= 'z'; ++it) {
//        symbols.push_back(it);
//    }
//    auto it = std::max_element(res.begin(),res.end());
//    auto index = it - res.begin();
 //   qDebug() << symbols[index] << index << "\n";

}


void View::on_push_training_data_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../../../Model/","All Files(*.*);; BMP(*.csv)");
    controller->set_path_file(file_path.toStdString());

     QMessageBox::information(this, "Success", "Image saved successfully");
}


void View::on_push_testing_data_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../../../Model/","All Files(*.*);; BMP(*.csv)");
    controller->set_path_file(file_path.toStdString());
     QMessageBox::information(this, "Success", "Image saved successfully");
}


void View::on_push_train_clicked()
{
    controller->train_graph_network();
     QMessageBox::information(this, "Success", "Image saved successfully");
}


void View::on_push_check_testing_data_clicked()
{
    controller->test_graph_network();
    ui->accuracy_label->setText(QString::number(controller->get_average_accuracy()));
    ui->precision_label->setText(QString::number(controller->get_precision()));
    ui->recall_label->setText(QString::number(controller->get_recall()));
    ui->f_mera_label->setText(QString::number(controller->get_f_measure()));
    ui->time_label->setText(QString::number(controller->get_time()));
    QMessageBox::information(this, "Success", "Image saved successfully");
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

std::vector<double> View::ImageToVector(const QImage& image)
{
    std::vector<double> coordinats;

    for (auto x = 0; x < 28 ; x++) {
        for (auto y = 0; y < 28; y++) {
            //QRgb pixel_color = mirIm.pixel(x, y);
            //double val = static_cast<int>((double(qRed(pixel_color)) + double(qGreen(pixel_color)) + double(qBlue(pixel_color)))/(3.0f));
            double val = image.pixelColor(y, x).value();
            coordinats.push_back(val);
        }
    }
    return coordinats;
}


void View::on_push_load_weights_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, "Select File","../../../../../Model/","All Files(*.*);; TXT(*.txt)");
    try {
        controller->load_from_file_weights_graph(file_path.toStdString());
        QMessageBox::information(this, "Success", "Weights loaded successfully");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Something went wrong...");

    }
}


void View::on_push_save_weights_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, "Select File","../../../../../Model/","All Files(*.*);; TXT(*.txt)");
    controller->write_to_file_weights_graph(file_path.toStdString());
    QMessageBox::information(this, "Success", "Weights saved successfully");


}


void View::on_shape_box_valueChanged(double arg1)
{
    controller->set_traininh_sample_share(arg1);
}

