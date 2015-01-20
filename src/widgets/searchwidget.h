#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>

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
     * @brief searchWidget Construct a search widget
     * @param parent The QWidget parent
     */
    explicit searchWidget(QWidget *parent = 0);

    ~searchWidget();

    /**
     * @brief getCurrentCustomerId
     * Return the id of the customer selected in the table
     * @return id of the current customer
     */
    int getCurrentCustomerId();

public slots:
    /**
     * @brief launch a search
     * @param toSearch The value to search
     */
    void search(QString toSearch);
private:
    Ui::searchWidget *ui;
    void updateTable(QString text="");
};

#endif // SEARCHWIDGET_H
