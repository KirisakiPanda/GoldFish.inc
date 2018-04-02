#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Own
#include "glwidget.h"

//Qt
#include <QMainWindow>
#include <QtOpenGL>
#include <QGLWidget>

class MainWindow : public QMainWindow
{
    //Qtのオブジェクトだと指定。(SIGNALS,SLOT構文を使う時に使用。とりあえずつけとけばOK)
Q_OBJECT
    
public:
    MainWindow();
    GLWidget *widget;
    //QGraphicsView *view;

private:



signals:

public slots:
    void open();





};


#endif // MAINWINDOW_H
