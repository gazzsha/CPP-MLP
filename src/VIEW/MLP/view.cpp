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

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,700,700);
    ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis);
 ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis);
ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis);
ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis);
ui->widget->addGraph(ui->widget->xAxis, ui->widget->yAxis2);
ui->widget->plotLayout()->insertRow(0);
ui->widget->plotLayout()->addElement(0, 0, new QCPTextElement(ui->widget, "Metrics report", QFont("Arial", 26, QFont::Bold)));

}

View::~View()
{
    delete ui;
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
    ui->letter_label->setText(QString(controller->PredictLetter(coordinates)));
    
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
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../../../","All Files(*.*);; CSV(*.csv)");
    if (!file_path.isEmpty()) { controller->set_path_file_train(file_path.toStdString());
    QMessageBox::information(this, "Success", "Data downloaded successfully");
    } else {
        QMessageBox::critical(this, "Error", "Something went wrong...");
    }
}


void View::on_push_testing_data_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../../../","All Files(*.*);; CVS(*.csv)");
    controller->set_path_file_test(file_path.toStdString());
     QMessageBox::information(this, "Success", "Data downloaded successfully");
}


void View::on_push_train_clicked()
{
    try {
    controller->Train();
    } catch(...)   { QMessageBox::critical(this, "Error", "Something went wrong..."); }
    QMessageBox::information(this, "Success", "Network trained successfully");
}


void View::on_push_check_testing_data_clicked()
{
    try {
    controller->Test();
    } catch(...)  { QMessageBox::critical(this, "Error", "Something went wrong..."); }
    ui->accuracy_label->setText(QString::number(controller->get_average_accuracy()));
    ui->precision_label->setText(QString::number(controller->get_precision()));
    ui->recall_label->setText(QString::number(controller->get_recall()));
    ui->f_mera_label->setText(QString::number(controller->get_f_measure()));
    ui->time_label->setText(QString::number(controller->get_time()));
    QMessageBox::information(this, "Success", "Network tested successfully");
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
    file_path = QFileDialog::getOpenFileName(this, "Select File","../../../../../Weights/","All Files(*);; TXT(*.txt)");
    try {
        controller->LoadFromFileWeights(file_path.toStdString());
        QMessageBox::information(this, "Success", "Weights loaded successfully");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Something went wrong...");

    }
}


void View::on_push_save_weights_clicked()
{

    QString file_path;
    file_path = QFileDialog::getSaveFileName(this, "Select File","../../../../../Weights/","All Files(*);; TXT(*.txt)");
    try {
    controller->WriteToFileWeights(file_path.toStdString());
    QMessageBox::information(this, "Success", "Weights saved successfully");
    } catch(...) {
        QMessageBox::critical(this, "Error", "Something went wrong...");
    }


}


void View::on_shape_box_valueChanged(double arg1)
{
    controller->set_traininh_sample_share(arg1);
}


void View::on_push_load_bmp_clicked()
{
    QString file_path;
    file_path = QFileDialog::getOpenFileName(this, " Select File","../../../../../BMP-Images/","All Files(*.*);; BMP(*.bmp)");
    QImage img = QImage(file_path);
    if (img.height() > 512 || img.width() > 512 || file_path.isEmpty()) {
        QMessageBox::critical(this, "Error","Something went wrong...");
    } else {
    QImage grayscale_image = img.convertToFormat(QImage::Format_Grayscale8);
    grayscale_image.invertPixels();
    for (int y = 0; y < grayscale_image.height(); ++y) {
        for (int x = 0; x < grayscale_image.width(); ++x) {
            // Получение цвета пикселя
            QColor pixelColor = grayscale_image.pixelColor(x, y);

            // Если цвет не черный, установка его в белый
            if (pixelColor.value() > 100) {
                grayscale_image.setPixelColor(x, y, Qt::white);
            }
        }
    }
    QImage new_image = grayscale_image.scaled(28,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QTransform transform;
    transform.rotate(90);
    new_image = new_image.transformed(transform);
    new_image = new_image.mirrored(true,false);
    std::vector<double> coordinates = ImageToVector(new_image);
    ui->letter_label->setText(QString(controller->PredictLetter(coordinates)));
    grayscale_image.save("../../../../../image.bmp");
    }
}


void View::on_push_train_online_clicked()
{
    ui->tableWidget->setRowCount(controller->get_epochs());
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,200);
    ui->tableWidget->setColumnWidth(3,200);
    ui->tableWidget->setColumnWidth(4,200);
    ui->tableWidget->setColumnWidth(5,200);
    controller->TrainOnline();
    for (size_t i = 0; i < controller->get_epochs(); ++i) {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(controller->get_average_accuracy_vec()[i])));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(controller->get_precision_vec()[i])));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(controller->get_recall_vec()[i])));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(controller->get_f_measure_vec()[i])));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(controller->get_time_vec()[i])));
}
s21::vector_ x_data_std = controller->get_vector_epochs();
s21::vector_ average_accuracy_std = controller->get_average_accuracy_vec();
s21::vector_ precision_std = controller->get_precision_vec();
s21::vector_ recall_std = controller->get_recall_vec();
s21::vector_ f_measure_std = controller->get_f_measure_vec();
s21::vector_ time_std = controller->get_time_vec();


QVector<double> x_data =  QVector<double>(x_data_std.begin(),x_data_std.end());
QVector<double> average_accuracy =  QVector<double>(average_accuracy_std.begin(),average_accuracy_std.end());
QVector<double> precision =  QVector<double>(precision_std.begin(), precision_std.end());
QVector<double> recall = QVector<double>(recall_std.begin(), recall_std.end());
QVector<double> f_measure = QVector<double>(f_measure_std.begin(), f_measure_std.end());
QVector<double> time = QVector<double>(time_std.begin(), time_std.end());


ui->widget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
ui->widget->legend->setVisible(true);
QFont legendFont = font();  // start out with MainWindow's font..
legendFont.setPointSize(16); // and make a bit smaller for legend
ui->widget->legend->setFont(legendFont);
ui->widget->legend->setBrush(QBrush(QColor(255,255,255,230)));
// by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
ui->widget->graph(0)->data()->clear();
    ui->widget->graph(1)->data()->clear();
        ui->widget->graph(2)->data()->clear();
            ui->widget->graph(3)->data()->clear();
                ui->widget->graph(4)->data()->clear();
    QPen blue_pen;
    blue_pen.setColor(Qt::blue);
    blue_pen.setWidthF(3);
        ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
   ui->widget->graph(0)->setPen(blue_pen);
 ui->widget->graph(0)->setName("Average_accuracy");
    ui->widget->graph(0)->addData(x_data,average_accuracy);
        QPen red_pen;
        red_pen.setColor(Qt::red);
        red_pen.setWidthF(3);
         ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
       ui->widget->graph(1)->setPen(red_pen);
     ui->widget->graph(1)->setName("Precision");
     ui->widget->graph(1)->addData(x_data,precision);



     QPen green_pen;
     green_pen.setColor(Qt::green);
     green_pen.setWidthF(3);
      ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
    ui->widget->graph(2)->setPen(green_pen);
  ui->widget->graph(2)->setName("Recall");
  ui->widget->graph(2)->addData(x_data,recall);


  QPen chocolate_pen;
  chocolate_pen.setColor(QColorConstants::Svg::chocolate);
 chocolate_pen.setWidthF(3);
   ui->widget->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
 ui->widget->graph(3)->setPen(chocolate_pen);
ui->widget->graph(3)->setName("f_measure");
ui->widget->graph(3)->addData(x_data,f_measure);
QPen deeppink_pen;
deeppink_pen.setColor(QColorConstants::Svg::deeppink);
deeppink_pen.setWidthF(3);
 ui->widget->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));
ui->widget->graph(4)->setPen(deeppink_pen);
ui->widget->graph(4)->setName("Time");
ui->widget->graph(4)->addData(x_data,time);

        ui->widget->xAxis->setRange(1 - 0.2, controller->get_epochs() + 0.2);
         ui->widget->xAxis2->setRange(1 - 0.2, controller->get_epochs() + 0.2);
        ui->widget->yAxis->setRange(0 - 0.2, 1 + 0.2);
        ui->widget->yAxis2->setRange(0, *(std::max_element(time.begin(),time.end())) + 0.1 * *(std::max_element(time.begin(),time.end())));

        ui->widget->yAxis2->setVisible(true);
        ui->widget->xAxis2->setVisible(true);
        //ui->widget->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
        ui->widget->yAxis2->setTickLength(3, 3);
        ui->widget->yAxis2->setSubTickLength(1, 1);
        ui->widget->xAxis->setTickLength(0, 5);
        ui->widget->xAxis->setSubTickLength(0, 3);
        ui->widget->replot();
        ui->accuracy_label->setText(QString::number(controller->get_average_accuracy_of_full_train()));
        ui->precision_label->setText(QString::number(controller->get_average_precision_of_full_train()));
        ui->recall_label->setText(QString::number(controller->get_average_recall_of_full_train()));
        ui->f_mera_label->setText(QString::number(controller->get_average_f_measure_of_full_train()));
        ui->time_label->setText(QString::number(controller->get_full_time_of_full_train()));

}


void View::on_count_2_hidden_layer_clicked()
{
     controller->set_hidden_layers(static_cast<size_t>(2));
}



void View::on_push_start_cross_validation_clicked()
{
    const size_t k = ui->cross_validation_count->value();
    controller->CrossValidation(k);
}

