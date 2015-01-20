#ifndef CUSTOMERCONTEXTUALMENU_H
#define CUSTOMERCONTEXTUALMENU_H

#include <QMenu>

/**
 * @brief Display contextual menu on a customer
 * @author Antoine de Roquemaurel
 */
class CustomerContextualMenu : public QMenu
{
public:
    CustomerContextualMenu(QWidget* w=0);
    ~CustomerContextualMenu();

private:
    QAction* _removeAction; //!< Remove a customer
    QAction* _editAction;   //!< Edit a customer
    QAction* _openAction;   //!< Open a customer
};

#endif // CUSTOMERCONTEXTUALMENU_H
