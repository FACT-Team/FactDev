#ifndef COMBOBOXMODELWIDGET_H
#define COMBOBOXMODELWIDGET_H

#include <QWidget>

#include "database/customerdatabase.h"

namespace Ui {
class ComboBoxModelWidget;
}

namespace Gui {
/**
 * @brief Contains Widgets classes
 */
namespace Widgets {
/**
 * @brief The ComboBoxModelWidget class
 */
class ComboBoxModelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ComboBoxModelWidget(QWidget *parent = 0);
    ~ComboBoxModelWidget();

private:
    //CustomerDatabase customerData;
    Ui::ComboBoxModelWidget *ui;
};
}
}
#endif // COMBOBOXMODELWIDGET_H
