#include "glwidget.h"
#include <iostream>

QColor purple = QColor::fromCmykF(0.99, 0.39, 0.0, 0.0);

//コンストラクタ
GLWidget::GLWidget() : QGLWidget(QGLFormat(QGL::SampleBuffers), 0)
{
    setFixedSize(500,500);
    //setAutoFillBackground(false);

    connect(&timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer.setSingleShot(false);
    timer.start(25);

    color1.setRgb(255, 0, 0, 0);


}

void GLWidget::initializeGL()
{
    glEnable(GL_MULTISAMPLE);
    qglClearColor(purple);

}
void GLWidget::paintEvent(QPaintEvent *event){
    makeCurrent();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    qglClearColor(purple);
    //std::cout<<"p="<<purple.red()<<"c1="<<color1.red();

    /*
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    setupViewport(width(), height());

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
*/

    /*
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    */
   // logo->draw();

    /*
//! [7]

//! [8]
    glShadeModel(GL_FLAT);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
//! [8]
*/


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    /*
    foreach (Bubble *bubble, bubbles) {
        if (bubble->rect().intersects(event->rect()))
            bubble->drawBubble(&painter);
    }
    */
    drawInstructions(&painter);
    painter.end();

}

void GLWidget::loop()
{
    //repaint();
    //update();
}



void GLWidget::setupViewport(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, +0.5, -0.5, 0.5, 4.0, 15.0); //=GLESではglOrthofと書く
    glMatrixMode(GL_MODELVIEW);
}



void GLWidget::drawInstructions(QPainter *painter)
{
    QString text = "Click and drag with the left mouse button to rotate" "the Qt logo.";
    //QString text2 = std::to_string(11111111111111);//purple.red();

    QFontMetrics metrics = QFontMetrics(font());
    int border = qMax(4, metrics.leading());

    QRect rect = metrics.boundingRect(0, 0, width() - 2*border, int(height()*0.125), Qt::AlignCenter | Qt::TextWordWrap, text);
    painter->setRenderHint(QPainter::TextAntialiasing);
    painter->fillRect(QRect(0, 0, width(), rect.height() + 2*border), QColor(0, 0, 0, 127));
    painter->setPen(Qt::white);
    painter->fillRect(QRect(0, 0, width(), rect.height() + 2*border), QColor(0, 0, 0, 127));
    painter->drawText((width() - rect.width())/2, border, rect.width(), rect.height(), Qt::AlignCenter | Qt::TextWordWrap, text);
    //painter->drawText(30,30,text2);

}
