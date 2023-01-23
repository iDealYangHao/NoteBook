#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    MenuBar(QWidget *parent = nullptr);

    QMenu *fileMenu;
    QMenu *settingMenu;
    QMenu *aboutMenu;
    QString fileName;

signals:
    void fileContent(QByteArray array);
    void saveFile(QString fileName);

private slots:
    void on_openAction_triggered();
    void on_saveAction_triggered();
//    void on_deleteAction_triggered();
//    void on_createAction_triggered();
    void on_copyRightAction_triggered();
    void on_privacyAction_triggered();
};

#endif // MENUBAR_H
