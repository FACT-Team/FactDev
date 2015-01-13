#ifndef CONNEXIONDIALOG_H
#define CONNEXIONDIALOG_H

#include <QDialog>

namespace Ui {
class connexiondialog;
}

class connexiondialog : public QDialog
{
    Q_OBJECT

public:
    explicit connexiondialog(QWidget *parent = 0);
    ~connexiondialog();

private:
    Ui::connexiondialog *ui;
};

#endif // CONNEXIONDIALOG_H
