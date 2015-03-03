#ifndef ADDPROJECTDIALOG_H
#define ADDPROJECTDIALOG_H

#include <QDialog>
#include "database/customerdatabase.h"

#include "models/project.h"
#include "models/customer.h"

#include "gui/mainwindow.h"

namespace Ui {
class AddProjectDialog;
}
namespace Gui {
namespace Dialogs {

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
     * @brief AddProjectDialog::AddProjectDialog Construct a windows
     * AddProjectDialog
     * @param id Project identity
     * @param parent QWidget of the current windows
     */
    explicit AddProjectDialog(int id = 0, QWidget *parent = 0);

    /**
     * @brief AddProjectDialogAddProjectDialog  Construct a windows according an
     *  <i>idCustomer</i> and, optionnaly, an <i>idProject</i>
     * @param noRowCustomer Row number of the Customer
     * @param idProject Project identify
     * @param parent QWidget of the current windows
     */
    explicit AddProjectDialog(int noRowCustomer, int idProject = 0,
        QWidget *parent = 0);
    ~AddProjectDialog();


    /**
     * @brief AddProjectDialog::accept Valid data inputed by user and add these
     * data in Database
     */
    void accept();

    /**
     * @brief AddProjectDialog::reject Cancel the operation and close the
     * windows
     */
    void reject();

    /**
     * @brief AddProjectDialog::fillFields Fill the differents fields of the
     * current windows according the Project data existing
     * As a project requires to be linked to a Customer, the Customer selection
     * part may be disable
     */
    void fillFields();

public slots:
    /**
     * @brief AddProjectDialog::checkFields Check if fields are valid
     */
    void checkFields();

private:

    Project _project;           //!< The new project to add
    Ui::AddProjectDialog *ui;   //!< User interface of <b>AddProjectDialog</b>
};
}
}
#endif // ADDPROJECTDIALOG_H
