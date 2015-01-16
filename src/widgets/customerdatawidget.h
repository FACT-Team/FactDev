#ifndef CUSTOMERDATAWIDGET_H
#define CUSTOMERDATAWIDGET_H

#include <QWidget>

namespace Ui {
class CustomerDataWidget;
}

class CustomerDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerDataWidget(QWidget *parent = 0);
    ~CustomerDataWidget();

    void printInformations(int id);
private:
    Ui::CustomerDataWidget *ui;
};

#endif // CUSTOMERDATAWIDGET_H
