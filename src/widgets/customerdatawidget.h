#ifndef CUSTOMERDATAWIDGET_H
#define CUSTOMERDATAWIDGET_H

#include <QWidget>
#include <QLabel>

#include "models/customer.h"
#include "models/user.h"

namespace Ui {
class CustomerDataWidget;
}

/**
 * @brief Class for display info of a customer
 * @author Cédric Rohaut
 */
class CustomerDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerDataWidget(QWidget *parent = 0);
    ~CustomerDataWidget();

    /**
     * @brief printUserData Print Data of current user
     */
    void printUserData();

    /**
     * @brief printInformations Print Data of customer id
     * @param id of customer to print
     */
    void printInformations(int id);
private:
    inline void setLabel(QLabel *lbValue, QString s, QLabel* lbLabel=0);
    Ui::CustomerDataWidget *ui;
};

#endif // CUSTOMERDATAWIDGET_H
