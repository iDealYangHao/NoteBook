#include "menubar.h"
#include <QKeySequence>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QByteArray>

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
    , fileMenu(new QMenu("File",this))
    , settingMenu(new QMenu("Settings", this))
{
    addMenu(fileMenu);
    addMenu(settingMenu);

    fileMenu->addAction("Open File", QKeySequence("Ctrl+O"));
    fileMenu->addAction("Save File", QKeySequence("Ctrl+S"));
    fileMenu->addAction("Delete File", QKeySequence("Ctrl+D"));
    fileMenu->addAction("Recent File");

    settingMenu->addAction("Text Color");

    auto actions = fileMenu->actions();
    auto action1 = actions.at(0);
    connect(action1, &QAction::triggered, this, [=]()
    {
        auto fileName = QFileDialog::getOpenFileName(this, "Open file",QDir::homePath());
        QFile selectFile(fileName);
        if (!selectFile.open(QIODevice::ReadWrite | QIODevice::Text))
            return;
        QByteArray array = selectFile.readAll();
        emit fileContent(array);
    });
}
