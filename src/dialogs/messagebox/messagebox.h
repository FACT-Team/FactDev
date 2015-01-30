#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

namespace Ui {
class MessageBox;
}

class MessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit MessageBox(QWidget *parent = 0);
    ~MessageBox();

    void static aboutFact();

    void test();

    void setImage(QString img, int width = 128, int height = 128);

    void setText(QString txt);
private:
    Ui::MessageBox *ui;
};

#endif // MESSAGEBOX_H
