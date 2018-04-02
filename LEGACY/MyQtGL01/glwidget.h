#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QTime>
#include "qtlogo.h"
class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget();
    QColor color1;
    QTimer timer;

    void initializeGL();
    void paintEvent(QPaintEvent *event);

    void drawInstructions(QPainter *painter);
    void setupViewport(int width, int height);
    QtLogo *logo;

private slots:
    void loop();

/*
    QSize sizeHint();
    int xRotation() { return xRot; }
    int yRotation() { return yRot; }
    int zRotation() { return zRot; }

protected:
    void initializeGL();
    void paintEvent(QPaintEvent *event);
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);


private:
    void createBubbles(int number);
    void drawInstructions(QPainter *painter);
    void setupViewport(int width, int height);

    QColor qtGreen;
    QColor qtPurple;

    GLuint object;
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;

    //QtLogo *logo;
    //QList<Bubble*> bubbles;
    QTimer animationTimer;




public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

private slots:
    void animate();
*/

};

#endif // GLWIDGET_H
