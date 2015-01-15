#ifndef DIALOGADDCUSTOMER_H
#define DIALOGADDCUSTOMER_H

#include <QDialog>
#include "models/customer.h"
namespace Ui {
class DialogAddCustomer;
}

class DialogAddCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddCustomer(int id=0, QWidget *parent = 0);
    ~DialogAddCustomer();

    void fillFields();
    void accept();
    void reject();
    Customer *getCustom() const;
    void setCustom(Customer *getCustom);

private:
    int mode;
    Customer* _custom;
    Ui::DialogAddCustomer *ui;
};

#endif // DIALOGADDCUSTOMER_H
