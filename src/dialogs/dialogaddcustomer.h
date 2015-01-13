#ifndef DIALOGADDCUSTOMER_H
#define DIALOGADDCUSTOMER_H

#include <QDialog>

namespace Ui {
class DialogAddCustomer;
}

class DialogAddCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddCustomer(int id=0, QWidget *parent = 0);
    ~DialogAddCustomer();

    void accept();
    void reject();
private:
    Ui::DialogAddCustomer *ui;
};

#endif // DIALOGADDCUSTOMER_H
