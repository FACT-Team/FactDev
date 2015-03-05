#ifndef SEARCHDOCK_H
#define SEARCHDOCK_H

#include <QDockWidget>

#include "models/search.h"
namespace Ui {
class SearchDock;
}

namespace Gui {
namespace Docks {

class SearchDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit SearchDock(QWidget *parent=0, Qt::WindowFlags flags = 0);
    ~SearchDock();

public slots:
    void search(QString text);

signals:
    void textChanged(QString text);

private:
    Ui::SearchDock *ui;

};

}
}
#endif // SEARCHDOCK_H
