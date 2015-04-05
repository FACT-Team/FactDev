#ifndef CHOSEFILEWIDGET_H
#define CHOSEFILEWIDGET_H

#include <QFileDialog>
#include "chosepathwidget.h"

namespace Gui {
namespace Widgets {
namespace Path {

/**
 * @brief The ChoseFileWidget class Chose a File in computer
 */
class ChoseFileWidget : public ChosePathWidget
{
    Q_OBJECT
public:
    /**
     * @brief ChoseFileWidget Construct a choseFileWidget
     * @param parent The parent widget
     */
    explicit ChoseFileWidget(QWidget *parent = 0);

    /**
     * @brief getypeFiles Return the types of files, by default it's *
     * @return The type of files
     */
    QString getypeFiles() const;

    /**
     * @brief setTypeFiles Change the files types. By default it's *
     * @param getypeFiles The new files types.
     */
    void setTypeFiles(const QString &getypeFiles);

public slots:
    /**
     * @brief fillField Fill the textfield with path information
     */
    void fillField();

private:
    QString _typeFiles; //!< The files types who appear in qfiledialog, default it's *.
};
}
}
}
#endif // CHOSEFILEWIDGET_H
