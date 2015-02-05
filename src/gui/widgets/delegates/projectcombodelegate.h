#ifndef PROJECTCOMBODELEGATE_H
#define PROJECTCOMBODELEGATE_H
#include <QItemDelegate>
#include <QComboBox>
#include <QApplication>

#include "models/project.h"

namespace Gui {
namespace Widgets {
namespace Delegates {

class ProjectComboDelegate : public QItemDelegate
{
Q_OBJECT
public:
    ProjectComboDelegate(QSharedPointer<Models::Customer> c, QObject* parent=0);
    ~ProjectComboDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;


private:
  QMap<int, Models::Project> _projects;
};
}
}
}
#endif // PROJECTCOMBODELEGATE_H
