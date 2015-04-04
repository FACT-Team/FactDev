#ifndef IMAGE_H
#define IMAGE_H

#include <QPixmap>
#include <QBuffer>

namespace Gui {
namespace Utils {

/**
 * @author
 * @brief The Image class Contains generic methods on image formats
 */
class Image
{
public:
    /**
     * @brief Image::imageToBytes Return a QByteArray of the QImage <i>image</i>
     * @param image An image
     * @param ext Extension file of the image (PNG as default value)
     * @return array of bytes from an <b>QImage</b> image
     */
    static QByteArray imageToBytes(QImage image, const QString ext="PNG");

    /**
     * @brief Image::pixmapToBytes Return a QByteArray of the QPixmap
     * <i>image</i>
     * @param pix An image
     * @param ext Extension file of the image (PNG as default value)
     * @return array of bytes from an <b>QPixmap</b> image
     */
    static QByteArray pixmapToBytes(const QPixmap pix, const QString ext="PNG");

    /**
     * @brief Image::pixmapToImage Return a QImage of QPixmap <i>image</i>
     * @param pix An image
     * @return QImage of pix
     */
    static QImage pixmapToImage(const QPixmap pix);

    /**
     * @brief Image::BytesToPixmap Return QPixmap from an array of bytes
     * @param bytes Array of bytes
     * @return QPixmap from bytes
     */
    static QPixmap bytesToPixmap(const QByteArray bytes);
};

}
}
#endif // IMAGE_H
