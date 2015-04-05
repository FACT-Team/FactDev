#ifndef CHOSEDIRECTORYWIDGET_H
#define CHOSEDIRECTORYWIDGET_H

#include "chosepathwidget.h"
#include <QFileDialog>

namespace Gui {
namespace Widgets {
namespace Path {

/**
 * @brief The ChoseDirectoryWidget class Open a QFileDialog.and display path in textfield
 */
class ChoseDirectoryWidget : public ChosePathWidget
{
    Q_OBJECT

public:
    /**
     * @brief ChoseDirectoryWidget Construct Widget
     * @param parent The parent widget
     */
    explicit ChoseDirectoryWidget(QWidget *parent=0);

public slots:
    /**
     * @brief fillField Fill the textfield with path information
     */
    void fillField();
};
}
}
}
#endif // CHOSEDIRECTORYWIDGET_H
