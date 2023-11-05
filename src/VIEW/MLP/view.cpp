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
    qDebug() << scene->sceneRect().size();

}

