#ifndef PROJECTCOMBODELEGATE_H
#define PROJECTCOMBODELEGATE_H

#include "models/project.h"
#include "gui/widgets/delegates/comboboxdelegate.h"
namespace Gui {
namespace Widgets {
namespace Delegates {

class ProjectComboDelegate : public ComboBoxDelegate
{
Q_OBJECT
public:
    ProjectComboDelegate(QSharedPointer<Models::Customer> c, QObject* parent=0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void removeInCombo(QList<int>&);

    QMap<int, Models::Project> getProjects() const;

    bool getLocked() const;
    void setLocked(bool getLlocked);

private:
    QMap<int, Models::Project> _projects;
    QList<int> _removeInCombo;
    bool _locked;
};
}
}
}
#endif // PROJECTCOMBODELEGATE_H
