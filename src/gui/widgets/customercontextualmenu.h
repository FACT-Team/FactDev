#ifndef CUSTOMERCONTEXTUALMENU_H
#define CUSTOMERCONTEXTUALMENU_H

#include <QMenu>

namespace Gui {
namespace Widgets {
/**
 * @brief Display contextual menu on a customer
 * @author Antoine de Roquemaurel
 */
class CustomerContextualMenu : public QMenu
{
public:
    /**
     * @brief CustomerContextualMenu Construct a new contextual menu
     * @param w Parent
     */
    CustomerContextualMenu(QWidget* w=0);

    /**
      @brief Destruct the contextual menu
      */
    ~CustomerContextualMenu();

private:
    QAction* _removeAction; //!< Remove a customer
    QAction* _editAction;   //!< Edit a customer
    QAction* _openAction;   //!< Open a customer
};
}
}
#endif // CUSTOMERCONTEXTUALMENU_H
