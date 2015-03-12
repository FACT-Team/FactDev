#ifndef CUSTOMERDATAWIDGET_H
#define CUSTOMERDATAWIDGET_H

#include <QWidget>
#include <QLabel>

#include "models/customer.h"
#include "models/user.h"

using namespace Models;

namespace Ui {
class CustomerDataWidget;
}

namespace Gui {
namespace Widgets {
/**
 * @author @Oxynos
 * @brief Class for display info of a customer
 */
class CustomerDataWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CustomerDataWidget::CustomerDataWidget Contruct a
     * CustomerDataWidget
     * @param parent Widget parent
     */
    explicit CustomerDataWidget(QWidget *parent = 0);
    ~CustomerDataWidget();

    /**
     * @brief CustomerDataWidget::printUserData Print Data of current user
     */
    void printUserData();

    /**
     * @brief CustomerDataWidget::printInformations Print Data of customer id
     * @param id of customer to print
     */
    void printInformations(int id);

private:
    /**
     * @brief ContributoriesWidget::setLabel Change the label by the new
     * <i>lbValue</i> with the text <i>s</i>
     * @param lbValue New label value
     * @param s Text of new label
     * @param lbLabel New Label
     */
    inline void setLabel(QLabel *lbValue, QString s, QLabel* lbLabel=0);

    Ui::CustomerDataWidget *ui; //!< User interface
};
}
}
#endif // CUSTOMERDATAWIDGET_H
