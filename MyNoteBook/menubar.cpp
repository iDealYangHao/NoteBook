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
    , aboutMenu(new QMenu("About", this))
{
    addMenu(fileMenu);
    addMenu(settingMenu);
    addMenu(aboutMenu);

    fileMenu->addAction("Open File", QKeySequence("Ctrl+O"));
    fileMenu->addAction("Save File", QKeySequence("Ctrl+S"));
    fileMenu->addAction("Delete File", QKeySequence("Ctrl+D"));
    fileMenu->addAction("Recent File");

    settingMenu->addAction("Text Color");

    aboutMenu->addAction("CopyRight");
    aboutMenu->addAction("Privacy");

    auto actions = fileMenu->actions();
    auto action1 = actions.at(0);
    connect(action1, &QAction::triggered, this, &MenuBar::on_openAction_triggered);
    connect(actions.at(1), &QAction::triggered, this, &MenuBar::on_saveAction_triggered);

    auto aboutAction = aboutMenu->actions();
    connect(aboutAction.at(0), &QAction::triggered, this, &MenuBar::on_copyRightAction_triggered);
    connect(aboutAction.at(1), &QAction::triggered, this, &MenuBar::on_privacyAction_triggered);
}

void MenuBar::on_openAction_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, "Open file",QDir::homePath());
    QFile selectFile(fileName);
    if (!selectFile.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QByteArray array = selectFile.readAll();
    emit fileContent(array);
}

void MenuBar::on_saveAction_triggered()
{
    emit saveFile(fileName);
}

void MenuBar::on_copyRightAction_triggered()
{
    QDialog *copyRightDialog = new QDialog();
    copyRightDialog->setAttribute(Qt::WA_DeleteOnClose);
    copyRightDialog->setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    copyRightDialog->setFixedSize(400,300);
    copyRightDialog->setModal(true);
    copyRightDialog->exec();
}

void MenuBar::on_privacyAction_triggered()
{
    QDialog privacyDialog(this);
    privacyDialog.exec();
}

