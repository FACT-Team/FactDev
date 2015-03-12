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
     * @brief ProjectComboDelegate::createEditor
     * @param parent
     * @param option
     * @param index
     * @return
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    /**
     * @brief ProjectComboDelegate::paint
     * @param painter
     * @param option
     * @param index
     */
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    /**
     * @brief ProjectComboDelegate::removeInCombo
     */
    void removeInCombo(QList<int>&);

    /**
     * @brief ProjectComboDelegate::getProjects
     * @return
     */
    QMap<int, Models::Project> getProjects() const;

    /**
     * @brief ProjectComboDelegate::getLocked
     * @return
     */
    bool getLocked() const;

    /**
     * @brief ProjectComboDelegate::setLocked
     * @param getLlocked
     */
    void setLocked(bool getLlocked);

private:
    QMap<int, Models::Project> _projects;   //!<
    QList<int> _removeInCombo;              //!<
    bool _locked;                           //!<
};
}
}
}
#endif // PROJECTCOMBODELEGATE_H
