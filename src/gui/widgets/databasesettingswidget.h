#ifndef DATABASESETTINGSWIDGET_H
#define DATABASESETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
    class DatabaseSettingsWidget;
}

namespace Gui {
namespace Widgets {

class DatabaseSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseSettingsWidget(QWidget *parent = 0);
    ~DatabaseSettingsWidget();

private:
    Ui::DatabaseSettingsWidget *ui;
};

}
}
#endif // DATABASESETTINGSWIDGET_H
