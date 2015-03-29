#ifndef USER_H
#define USER_H
#include <QString>
#include <QDir>
#include <QStandardPaths>

#include "models/imodel.h"
#include "models/project.h"
#include "models/customer.h"
#include "models/people.h"

#include "utils/log.h"
#include "utils/directories.h"

namespace Models {
/**
 * @author Florent Berbie
 * @brief The User class <b>User</b> of it application
 */
class User : public People, public IModel
{
public:
    /**
     * @brief User::User. Contruct an User
     */
    User();

    /**
     * @brief User::User. Construct a User with the identify <i>id</i>
     * @param id User id
     */
    User(int id);

    /**
     * @brief User::commit Update user data in User table on the database
     */
    void commit();

    /**
     * @brief User::hydrat Get data of the user who is specified by <i>id</i>
     * from the database
     * @param id User identify
     */
    void hydrat(int id=1);

    /**
     * @brief remove Remove the current User
     */
    void remove();

    /**
     * @brief getDataMap Get all data of model with a HashMap key/value
     * @return Model's data
     */
    QVariantHash getDataMap();


    /**
     * @brief MainWindow::updateFolders Make directories which contain quotes
     * and billings. Directories are the same than theirs of the Tree
     * organisation (without Projects).
     *
     * Organisation of folders are formed like this:
     *  + COMPANY CustomerLastname CustomerFirstname/
     *      + Quotes/
     *          - quote1
     *          ...
     *      + Billings/
     *          - billing1
     *          ...
     */
    void updateFolders(void);

    /**
     * @brief User::getTitle Return a short description of User (company)
     *  activity
     * @return a short description of user (company) activity
     */
    QString getTitle() const;
    /**
     * @brief User::setTitle Modify the user/company activities
     *  <i>description</i>
     * @param title Short description on activity(ies) of User company
     */
    void setTitle(const QString &title);

    /**
     * @brief User::getNoSiret Return the SIRET number (company registration
     *  number)
     * @return SIRET number
     */
    QString getNoSiret() const;
    /**
     * @brief User::setNoSiret Modify the SIRET number (company registration
     *  number) <i>noSiret</i>
     * @param noSiret SIRET number
     */
    void setNoSiret(const QString &noSiret);

    /**
     * @brief User::getWorkspaceName Return the name of the workspace user
     * @return workspace name
     */
    QString getWorkspaceName() const;
    /**
     * @brief User::setWorkspaceName Change the current workspace name by the
     * new <i>workspaceName</i>
     * @param workspaceName
     */
    void setWorkspaceName(const QString &workspaceName);

    /**
     * @brief User::getWorkspacePath Return the path of the workspace user
     * @return workspace path
     */
    QString getWorkspacePath() const;
    /**
     * @brief User::setWorkspacePath Change the current workspace path by the
     * new <i>workspacePath</i>
     * @param workspacePath
     */
    void setWorkspacePath(const QString &workspacePath);

    /** @brief User::operator == Re-define the operator "==" to compare if
     * the current User is the same to the other <b>User</b> <i>c</i>
     * Return TRUE if both Users are the same, else FALSE
     * @param u User to compare
     * @return boolean
     */
    bool operator ==(const User &u);
    /**
     * @brief User::operator == Re-define the operator "!=" to compare if
     * the current User is differnt to the other <b>User</b> <i>c</i>
     * Return TRUE if both Users are different, else FALSE
     * @param u User to compare
     * @return boolean
     */
    bool operator !=(const User &u);

    /**
     * @brief getPdflatexPath The path of pdflatex
     * @return The pdflatex path
     */
    QString getPdflatexPath() const;

    /**
     * @brief setPdflatexPath Change the pdflatex command path.
     * @param getPdflatexPath The new command
     */
    void setPdflatexPath(const QString &getPdflatexPath);

    /**
     * @brief nbHoursPerDays The number of hours per days who the user work⋅
     * @return The number of hours per days
     */
    int getNbHoursPerDays();

    /**
     * @brief getNbDaysPerMonths The number of days per months who the user work⋅
     * @return The number of days per months
     */
    int getNbDaysPerMonths();
private:
    QString _title;         //!< User/Company description on it activity
    QString _noSiret;       //!< SIRET number (company registration number)
    QString _workspaceName; //!< Workspace name
    QString _workspacePath; //!< Workspace directory path
    QString _pdflatexPath; //!< Path to pdflatex command
};
}
#endif // USER_H
