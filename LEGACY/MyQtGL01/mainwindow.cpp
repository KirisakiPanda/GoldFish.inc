
//Own
#include "mainwindow.h"

//Qt
#include <QGraphicsView>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>
#include <QSound>

#ifndef QT_NO_OPENGL
# include <QtOpenGL/QtOpenGL>
#endif


//コンストラクタ
MainWindow::MainWindow() : QMainWindow(0)
{
    setWindowTitle("GAME WINDOW");
    setMinimumSize(500,500);
    setMaximumSize(500,500);

    //上部メニュー作成
    //メンバ関数*menuBar()はQMainWindowが最初から保持しているので、作った変数(file,newAction,quitAction)にアドレスを当てればOK。
    //[newAction,quitAction]<<<[file]<<<[menuBar]
    QMenu *file = menuBar()->addMenu("&menu");
    QAction *newAction = file->addAction("New Game");
    QAction *quitAction = file->addAction("Quit");

    newAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    quitAction->setShortcut(QKeySequence(Qt::Key_Escape));

    connect(newAction, SIGNAL(triggered()), this, SLOT(open()));

    /*
    //コマンド引数に-fullscreenが含まれた場合にフルスクリーンにする
    if (QApplication::arguments().contains("-fullscreen")) {
        scene = new GraphicsScene(0, 0, 750, 400, GraphicsScene::Small);
        setWindowState(Qt::WindowFullScreen); //QMainWindowのメンバ関数。画面をフルスクリーンにする。
    }
    */
    /*
    //scene = new GraphicsScene(0, 0, 880, 630);
    //layout()->setSizeConstraint(QLayout::SetFixedSize);//*QWidget MainWindow::layout(). メインウインドウの大きさを調整出来る。
    //GraphicsViewを作成。view(大きい画面パーツ)にQGLWidget(小さい画面パーツ)を貼り付ける。
    //view->setAlignment(Qt::AlignLeft | Qt::AlignTop);//viewをメインウインドウのどこに貼り付けるか。
    //scene->setupScene(newAction, quitAction);
    //view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
    //widget = new QGLWidget(QGLFormat(QGL::SampleBuffers),this);
    */

    //OpenGL画面を貼り付け
    widget = new GLWidget();
    setCentralWidget(widget);

}

//メニューバーの反応
void MainWindow::open()
{
    QSound::play("sounds/dmg.wav");
    printf("opened!");
}
