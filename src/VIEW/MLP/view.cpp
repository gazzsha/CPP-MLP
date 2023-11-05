#include "view.h"
#include "./ui_view.h"
#include <QDebug>
View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,28,28);
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
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    scene->render(&painter);
    QVector<QVector<double>> pixel_matrix;
    
    for (int x = 0; x < image.width(); x++) {
        QVector<double> row;
        for (int y = 0; y < image.height(); y++) {
            QRgb pixel_color = image.pixel(x, y);
            row.append((double(qRed(pixel_color)) + double(qGreen(pixel_color)) + double(qBlue(pixel_color)))/3.0f);
        }
        pixel_matrix.append(row);
    }
}

