#ifndef FILECHOSEWIDGET_H
#define FILECHOSEWIDGET_H

#include <QWidget>

namespace Ui {
class FileChoseWidget;
}

class FileChoseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileChoseWidget(QWidget *parent = 0);
    ~FileChoseWidget();

private:
    Ui::FileChoseWidget *ui;
};

#endif // FILECHOSEWIDGET_H
