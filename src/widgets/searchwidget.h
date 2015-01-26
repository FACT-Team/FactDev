#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include "database/customerdatabase.h"

namespace Ui {
class searchWidget;
}

/**
 * @brief Class for search in database
 * @author Antoine de Roquemaurel
 */
class searchWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief searchWidget::searchWidget Construct a search widget
     * @param parent The QWidget parent
     */
    explicit searchWidget(QWidget *parent = 0);

    ~searchWidget();

    /**
     * @brief searchWidget::getCurrentCustomerId
     * Return the id of the customer selected in the table
     * @return id of the current customer
     */
    int getCurrentCustomerId();


    /**
     * @brief isCustomerSelected Return TRUE if a customer is selected, else
     * FALSE
     * @return boolean
     */
    bool isCustomerSelected() const;


public slots:
    /**
     * @brief searchWidget::launch a search
     * @param toSearch The value to search
     */
    void search(QString toSearch);

    /**
     * @brief searchWidget::getCustomerData Return data on the customer selected
     *  in the QTableView and display this data (Firstname, Lastname, Company)
     */
    void getCustomerData();

signals:
    void selectCustomer();
private:
    Ui::searchWidget *ui;
    void updateTable(QString text="");
    bool _isCustomerSelected;
};

#endif // SEARCHWIDGET_H
