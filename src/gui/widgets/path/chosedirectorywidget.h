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
    ChoseDirectoryWidget(QWidget *parent);

public slots:
    void fillField();
};
}
}
}
#endif // CHOSEDIRECTORYWIDGET_H
