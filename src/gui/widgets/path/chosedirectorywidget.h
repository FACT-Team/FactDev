#ifndef CHOSEDIRECTORYWIDGET_H
#define CHOSEDIRECTORYWIDGET_H

#include "chosepathwidget.h"
#include <QFileDialog>

namespace Gui {
namespace Widgets {
namespace Path {
class ChoseDirectoryWidget : public ChosePathWidget
{
    Q_OBJECT

public:
    explicit ChoseDirectoryWidget(QWidget *parent=0);

public slots:
    void fillField();
};
}
}
}
#endif // CHOSEDIRECTORYWIDGET_H
