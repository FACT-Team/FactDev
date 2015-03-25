#ifndef CHOSEPATHWIDGET_H
#define CHOSEPATHWIDGET_H

#include <QWidget>
#include <QDir>

namespace Ui {
class ChosePathWidget;
}

namespace Gui {
namespace Widgets {
namespace Path {

class ChosePathWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChosePathWidget(QWidget *parent = 0);
    ~ChosePathWidget();

    void setField(QString text);
    QString getField();
    void setText(QString, QString, QString, QString s4);

    virtual QString getDefaultLocation();

public slots:
    virtual void fillField();
    void updateBtn();

signals:
    void textChanged();

protected:
    Ui::ChosePathWidget *ui;
};

}
}
}

#endif // CHOSEPATHWIDGET_H
