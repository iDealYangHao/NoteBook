#include "mainwindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QTextEdit(this))
    , myMenuBar(new MenuBar(this))
    , myToolBar(new ToolBar(this))
{
    setMenuBar(myMenuBar);
    addToolBar(myToolBar);
    auto action1 = myMenuBar->fileMenu->actions().at(0);
    myToolBar->addAction(action1);
    resize(800,600);
    setCentralWidget(centralWidget);
    connect(myMenuBar, &MenuBar::fileContent, this, [=](const QByteArray &content)
    {
        centralWidget->setText(content.toStdString().data());
    });
}

MainWindow::~MainWindow()
{
}

