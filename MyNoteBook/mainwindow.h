#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

#include "menubar.h"
#include "toolbar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTextEdit *centralWidget;
    MenuBar *myMenuBar;
    ToolBar *myToolBar;
};
#endif // MAINWINDOW_H
