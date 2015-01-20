#ifndef COMBOBOXMODELWIDGET_H
#define COMBOBOXMODELWIDGET_H
#include "database/customerdatabase.h"
#include <QWidget>

namespace Ui {
class ComboBoxModelWidget;
}

/**
 * @brief The ComboBoxModelWidget class
 * TODO
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

#endif // COMBOBOXMODELWIDGET_H
