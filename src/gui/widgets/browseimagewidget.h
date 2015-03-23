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
     * @brief BrowseImageWidget::getImageScaled Modify the current image to a
     * scaled image from the icon specified by it <i>path</i>. The image has a
     * resolution of <i>width</i>*<i>height</i> (default 128*128)
     * @param path Icon path
     * @param width Icon width
     * @param height Icon height
     */
    void setImageScaled(QString path, int width = 128, int height = 128);

    /**
     * @brief BrowseImageWidget::getIcon Return the icon selected
     * @return image
     */
    QPixmap getImage();

public slots:

    /**
     * @brief BrowseImageWidget::browseImagePath() Open a new window to define
     * the workspace path of the user
     */
    void browseImagePath();

private:
    Ui::BrowseImageWidget *ui;  //!< User interface
    QPixmap _img;               //!< image
};

}
}

#endif // BROWSEIMAGEWIDGET_H
