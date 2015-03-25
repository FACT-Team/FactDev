#ifndef CHOSEFILEWIDGET_H
#define CHOSEFILEWIDGET_H

#include <QFileDialog>
#include "chosepathwidget.h"

namespace Gui {
namespace Widgets {
namespace Path {

class ChoseFileWidget : public ChosePathWidget
{
    Q_OBJECT
public:
    explicit ChoseFileWidget(QWidget *parent = 0);

    QString getypeFiles() const;
    void setTypeFiles(const QString &getypeFiles);

public slots:
    void fillField();

private:
    QString _typeFiles;
};
}
}
}
#endif // CHOSEFILEWIDGET_H
