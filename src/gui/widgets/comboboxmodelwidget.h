#ifndef COMBOBOXMODELWIDGET_H
#define COMBOBOXMODELWIDGET_H

#include <QWidget>

#include "database/customerdatabase.h"

#include "ui_comboboxmodelwidget.h"

namespace Ui {
class ComboBoxModelWidget;
}

namespace Gui {
/**
 * @brief Contains Widgets classes
 */
namespace Widgets {
/**
 * @brief The ComboBoxModelWidget class Model of ComboBox
 */
class ComboBoxModelWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ComboBoxModelWidget::ComboBoxModelWidget Construct a
     * ComboBoxModelWidget
     * @param parent QWidget parent
     */
    explicit ComboBoxModelWidget(QWidget *parent = 0);
    ~ComboBoxModelWidget();

private:
    Ui::ComboBoxModelWidget *ui;    //!< User interface
};
}
}
#endif // COMBOBOXMODELWIDGET_H
