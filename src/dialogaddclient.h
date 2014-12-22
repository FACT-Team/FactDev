#ifndef DIALOGADDCLIENT_H
#define DIALOGADDCLIENT_H

#include <QDialog>

namespace Ui {
class DialogAddClient;
}

class DialogAddClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddClient(QWidget *parent = 0);
    ~DialogAddClient();

private:
    Ui::DialogAddClient *ui;
};

#endif // DIALOGADDCLIENT_H
