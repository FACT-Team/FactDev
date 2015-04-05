#include "image.h"

namespace Gui {
namespace Utils {

QByteArray Image::pixmapToBytes(const QPixmap pix, const QString ext)
{
    return imageToBytes(pixmapToImage(pix),ext);
}

QImage Image::pixmapToImage(const QPixmap pix)
{
    return QImage(pix.toImage());
}

QPixmap Image::bytesToPixmap(const QByteArray bytes)
{
    return QPixmap::fromImage(QImage::fromData(bytes));
}

QByteArray Image::imageToBytes(QImage image, const QString ext) {
    QByteArray bytesArray;
    QByteArray extArray = ext.toLocal8Bit();
    QBuffer buffer(&bytesArray);
    buffer.open(QIODevice::WriteOnly);

    image.save(&buffer, extArray.data());

    return bytesArray;
}

}
}
