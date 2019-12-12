#include "graphics.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    MainWindow(const MainWindow& mw);

    MainWindow operator=(const MainWindow& mwOther);

    void plot();


private slots:
    void on_pushButtonPlay_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonPause_clicked();


private:

    Ui::MainWindow *ui;
    QVector<double> xs,ys;
};
#endif // MAINWINDOW_H
