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

signals:
    void fileContent(QByteArray array);
};

#endif // MENUBAR_H
