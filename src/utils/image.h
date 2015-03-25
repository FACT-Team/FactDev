#ifndef IMAGE_H
#define IMAGE_H

#include <QPixmap>
#include <QBuffer>

namespace Utils {


class Image
{
public:
    Image();
    static QByteArray imageToBytes(QImage image);

    static QByteArray pixmapToBytes(QPixmap pix);

    static QImage pixmapToImage(QPixmap pix);
};

}
#endif // IMAGE_H
