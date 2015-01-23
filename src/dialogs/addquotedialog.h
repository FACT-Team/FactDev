#ifndef ADDQUOTEDIALOG_H
#define ADDQUOTEDIALOG_H

#include <QDialog>

namespace Ui {
class AddQuoteDialog;
}

class AddQuoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddQuoteDialog(QWidget *parent = 0);
    ~AddQuoteDialog();

private:
    Ui::AddQuoteDialog *ui;
};

#endif // ADDQUOTEDIALOG_H
