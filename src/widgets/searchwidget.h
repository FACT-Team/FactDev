#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>

namespace Ui {
class searchWidget;
}

class searchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchWidget(QWidget *parent = 0);
    ~searchWidget();

    /**
     * @brief getCurrentCustomerId
     * Return the id of the customer selected in the table
     * @return id of the current customer
     */
    int getCurrentCustomerId();

public slots:
    void search(QString);
private:
    Ui::searchWidget *ui;
    void updateTable(QString text="");
};

#endif // SEARCHWIDGET_H
