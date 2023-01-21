#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>

class ToolBar : public QToolBar
{
    Q_OBJECT
public:
    ToolBar(QWidget *parent = nullptr);
};

#endif // TOOLBAR_H
