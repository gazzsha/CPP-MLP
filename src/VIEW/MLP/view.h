#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsView>
#include "paintscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

private slots:
    void on_pushLoad_clicked();

    void on_pushClear_clicked();
    void on_pushPredict_clicked();

private:
    Ui::View *ui;
    PaintScene * scene;

};
#endif // VIEW_H
