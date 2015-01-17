#ifndef ADDCONTRIBUTORYDIALOG_H
#define ADDCONTRIBUTORYDIALOG_H

#include <QDialog>

namespace Ui {
class AddContributoryDialog;
}

/**
 * @brief The AddContributoryDialog class Windows to add a new Contributory
 */
class AddContributoryDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddContributoryDialog Construct a new windows AddContributory
     * @param parent QWidget
     */
    explicit AddContributoryDialog(QWidget *parent = 0);
    ~AddContributoryDialog();

private:
    Ui::AddContributoryDialog *ui;
};

#endif // ADDCONTRIBUTORYDIALOG_H
