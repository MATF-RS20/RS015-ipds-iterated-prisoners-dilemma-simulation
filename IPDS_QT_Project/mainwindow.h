#include "graphicSim.h"
#include "graphics.h"
#include "strategiesheaders.h"
#include "ui_mainwindow.h"
#include "help.h"
#include <iostream>
#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

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

    void addDefaultScene(void);



    void refreshUI();


    std::vector<unsigned> m_specimenNoInfo{0,0,0,0,0,0,0};
    int m_currentStratNo;
private slots:
    void updateUI();
    void plot();

    void on_pushButtonPlay_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonPause_clicked();

    void on_updateButton_clicked();

    void on_newWindowButton_clicked();

private:

    QTimer m_timer;
    GraphicSim* m_gs;
    Ui::MainWindow ui;
    Help* m_secondWindow;

    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    bool m_playing = false;
    bool paused = false;
    QString m_currentSpecimenDescriptionText;
    QPixmap m_currentSpecimenPhoto;

    void setPlotColors();
    void setCurrentSpecimenDescription();
    QString getCurrentSpecimenDescription();
    QPixmap getCurrentSpecimenPhoto();
    void setCurrentSpecimenPhoto();
    std::vector<QString> stratNames;
};
#endif // MAINWINDOW_H
