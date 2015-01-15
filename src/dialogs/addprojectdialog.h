#ifndef ADDPROJECTDIALOG_H
#define ADDPROJECTDIALOG_H
#include "models/project.h"

#include <QDialog>

namespace Ui {
class AddProjectDialog;
}

class AddProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProjectDialog(int id=0, QWidget *parent = 0);
    ~AddProjectDialog();

    void accept();
    void reject();
    void fillCustomerComboBox();
private:
    Project _project;
    Ui::AddProjectDialog *ui;
};

#endif // ADDPROJECTDIALOG_H
