#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QTextEdit(this))
{

}

MainWindow::~MainWindow()
{
}

