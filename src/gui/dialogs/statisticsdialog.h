#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>

namespace Ui {
class StatisticsDialog;
}

namespace Gui {
namespace Dialogs {

class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsDialog(QWidget *parent = 0);
    ~StatisticsDialog();

private:
    Ui::StatisticsDialog *ui;
};

}
}

#endif // STATISTICSDIALOG_H
