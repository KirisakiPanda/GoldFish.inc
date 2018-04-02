//Own
#include "mainwindow.h"

//Qt
#include <QApplication>
#include <QtOpenGL>
#include <QtWidgets>
#include <QSound>

int main(int argc, char *argv[])
{
    //アプリケーション生成。
    QApplication app(argc, argv);

    //リソース読み込み
    //Q_INIT_RESOURCE(.qrc_file_name);

    //inherit : QTime.h<<<Time.h
    //rand関数の初期シード設定。QTime生成。secsTo関数呼び出して、現在時刻を秒数(int型)に変換。
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //メインウインドウ生成。
    MainWindow mw;

    //メインウインドウをアプリケーションに適用。
    mw.show();
    
    //アプリケーション実行
    return app.exec();
}
