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

/**
 * @brief The ChoseDirectoryWidget class Open a QFileDialog.and display path in textfield
 */
class ChosePathWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ChoseFileWidget Construct a choseFileWidget
     * @param parent The parent widget
     */
    explicit ChosePathWidget(QWidget *parent = 0);
    ~ChosePathWidget();

    /**
     * @brief setField Change the path in textfield
     * @param text The new text
     */
    void setField(QString text);

    /**
     * @brief getField The text in field
     * @return The path text
     */
    QString getField();

    /**
     * @brief getDefaultLocation The default location when we open popup. In default case, it's ~/Documents
     * @return The default location
     */
    virtual QString getDefaultLocation();

public slots:
    /**
     * @brief fillField Fill the textfield with path information
     */
    virtual void fillField();

signals:
    /**
     * @brief textChanged Signal is send when path changed.
     */
    void textChanged();

protected:
    Ui::ChosePathWidget *ui;
};

}
}
}

#endif // CHOSEPATHWIDGET_H
