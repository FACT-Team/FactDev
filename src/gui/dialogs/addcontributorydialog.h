#ifndef ADDCONTRIBUTORYDIALOG_H
#define ADDCONTRIBUTORYDIALOG_H

#include <QDialog>

namespace Ui {
class AddContributoryDialog;
}

namespace Gui {
namespace Dialogs {

/**
         * @author Florent Berbie
         * @brief The AddContributoryDialog class Windows to add a new Contributory
         * @see Contributory
         */
class AddContributoryDialog : public QDialog
{
    Q_OBJECT

public:
    /**
             * @brief AddContributoryDialog::AddContributoryDialog Construct a new
             * windows AddContributory
             * @param parent QWidget
             */
    explicit AddContributoryDialog(QWidget *parent = 0);
    ~AddContributoryDialog();

private:
    Ui::AddContributoryDialog *ui;  //!< User interface of <b>AddContributoryDialog</b>
};
}
}
#endif // ADDCONTRIBUTORYDIALOG_H
