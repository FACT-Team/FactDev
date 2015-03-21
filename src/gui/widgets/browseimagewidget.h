#ifndef BROWSEIMAGEWIDGET_H
#define BROWSEIMAGEWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QStandardPaths>

namespace Ui {
class BrowseImageWidget;
}
namespace Gui {
namespace Widgets {
/**
 * @author Florent Berbie
 * @brief The BrowseImageWidget class Widget to add a new BrowseImageWidget
 */
class BrowseImageWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief BrowseImageWidget::BrowseImageWidget Cosntruct a BrowseImageWidget
     * @param parent QWidget parent
     */
    explicit BrowseImageWidget(QWidget *parent = 0);
    ~BrowseImageWidget();

    /**
     * @brief BrowseImageWidget::getImage Return a scaled image from the
     * icon specified by it <i>path</i>. The image returned has a resolution of
     * <i>width</i>*<i>height</i> (default 128*128)
     * @param path Icon path
     * @param width Icon width
     * @param height Icon height
     * @return Scaled image
     */
    QPixmap getImage(QString path, int width = 128, int height = 128);

public slots:

    /**
     * @brief BrowseImageWidget::browseImagePath() Open a new window to define
     * the workspace path of the user
     */
    void browseImagePath();

private:
    Ui::BrowseImageWidget *ui;  //!< Usqer interface
};

}
}

#endif // BROWSEIMAGEWIDGET_H
