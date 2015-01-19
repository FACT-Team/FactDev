#ifndef ADDPROJECTDIALOG_H
#define ADDPROJECTDIALOG_H

#include <QDialog>
#include "database/customerdatabase.h"
#include "models/project.h"
#include "models/customer.h"

namespace Ui {
class AddProjectDialog;
}

/**
 * @author Florent Berbie
 * @brief The AddProjectDialog class Windows to add a new Project
 * @see Project
 */
class AddProjectDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddProjectDialog Construct a windows AddProjectDialog
     * @param id Project identity
     * @param parent QWidget of the current windows
     */
    explicit AddProjectDialog(int id=0, QWidget *parent = 0);

    ~AddProjectDialog();


    /**
     * @brief accept Valid data inputed by user and add these data in Database
     */
    void accept();

    /**
     * @brief reject Cancel the operation and close the windows
     */
    void reject();
private:

    Project _project; //!< The new project to add

    Ui::AddProjectDialog *ui;
};

#endif // ADDPROJECTDIALOG_H
