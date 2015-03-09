#ifndef DATABASESETTINGSWIDGET_H
#define DATABASESETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
    class DatabaseSettingsWidget;
}

namespace Gui {
namespace Widgets {

/**
 * @author
 * @brief The DatabaseSettingsWidget class Windows of database settings
 */
class DatabaseSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief DatabaseSettingsWidget::DatabaseSettingsWidget Construct a
     * DatabaseSettingsWidget
     * @param parent Parent widget of this windows
     */
    explicit DatabaseSettingsWidget(QWidget *parent = 0);
    ~DatabaseSettingsWidget();

    /**
     * @brief DatabaseSettingsWidget::fillFields Complete fields with a default
     * value for field Database name, Username, IP address and port
     */
    void fillFields();

public slots:

    /**
     * @brief DatabaseSettingsWidget::isValid Return TRUE if all fields are
     * correctly inputed else FALSE
     * @return boolean
     */
    bool isValid();

    /**
     * @brief DatabaseSettingsWidget::checkRepeatLogin Check if the second login
     *  field is the same than the first
     */
    void checkRepeatLogin(QString text);

private:
    Ui::DatabaseSettingsWidget *ui; //!< User interface
};

}
}
#endif // DATABASESETTINGSWIDGET_H
