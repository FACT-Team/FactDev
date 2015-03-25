#include "image.h"

namespace Utils {

Image::Image()
{

}

QByteArray Image::pixmapToBytes(QPixmap pix)
{
    return imageToBytes(pixmapToImage(pix));
}

QImage Image::pixmapToImage(QPixmap pix)
{
    return QImage(pix.toImage());
}

QByteArray Image::imageToBytes(QImage image) {
    QByteArray bytesArray;
    QBuffer buffer(&bytesArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG"); // writes image into ba in PNG format

    return bytesArray;
}

}
