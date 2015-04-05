#include "windowsettings.h"

namespace Gui {
namespace Utils {

void WindowSettings::setMaximumSize(QWidget &w)
{
    QDesktopWidget screen;
    w.setMaximumSize(screen.width(), screen.height());
}

void WindowSettings::setPositionToCenter(QWidget &w)
{
    QDesktopWidget desktopScreen;
    QRect surface = desktopScreen.screenGeometry();
    int x = surface.width()/2 - w.width()/2;
    int y = surface.height()/2 - w.height()/2;
    w.move(x,y);
}

}
}
