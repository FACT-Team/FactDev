#ifndef CUSTOMERCONTEXTUALMENU_H
#define CUSTOMERCONTEXTUALMENU_H

#include <QMenu>

class CustomerContextualMenu : public QMenu
{
public:
    CustomerContextualMenu(QWidget* w=0);
    ~CustomerContextualMenu();

private:
    QAction* _removeAction;
    QAction* _editAction;
    QAction* _openAction;
};

#endif // CUSTOMERCONTEXTUALMENU_H
