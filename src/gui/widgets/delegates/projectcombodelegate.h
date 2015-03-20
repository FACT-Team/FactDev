#ifndef PROJECTCOMBODELEGATE_H
#define PROJECTCOMBODELEGATE_H

#include "models/project.h"
#include "gui/widgets/delegates/comboboxdelegate.h"
namespace Gui {
namespace Widgets {
namespace Delegates {

/**
 * @brief The ProjectComboDelegate class
 */
class ProjectComboDelegate : public ComboBoxDelegate
{
Q_OBJECT
public:
    /**
     * @brief ProjectComboDelegate::ProjectComboDelegate
     * @param c
     * @param parent
     */
    ProjectComboDelegate(QSharedPointer<Models::Customer> c, QObject* parent=0);

    /**
     * @brief ProjectComboDelegate:createEditor Return a ComboBox specified by
     * <i>index</i> item defined by the <i>parent</i> widget and style
     * <i>option</i> which are used to control how the editor widgets appears
     * @param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     * @return ComboBox
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    /**
     * @brief ProjectComboDelegate::paint Renders the delegate using the given
     * <i>painter</i> and style <i>option</i> for the item specified by
     * <i>index</i>
     *@param parent Widget parent
     * @param option Option style
     * @param index Index for editing
     */
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    /**
     * @brief ProjectComboDelegate::removeInCombo Remove the items contained in
     * the list <i>l</i> into the current ComboBox
     */
    void removeInCombo(QList<int>&l);

    /**
     * @brief ProjectComboDelegate::getProjects  Return a list of projects
     * linked to a Customer ID
     * @return Projets of a Customer
     */
    QMap<int, Models::Project> getProjects() const;

    /**
     * @brief ProjectComboDelegate::isLocked Return TRUE if is locked else
     * FALSE
     * @return boolean
     */
    bool isLocked() const;

    /**
     * @brief ProjectComboDelegate::setLocked Change the state of the lock by a
     * new value <i>locked</i>
     * @param locked
     */
    void setLocked(bool locked);

private:
    QMap<int, Models::Project> _projects;   /** List of projects linked to an
                                            Customer ID */
    QList<int> _removeInCombo;  //!< Items to remove in the current ComboBox
    bool _locked;               //!< element is locked
};
}
}
}
#endif // PROJECTCOMBODELEGATE_H
