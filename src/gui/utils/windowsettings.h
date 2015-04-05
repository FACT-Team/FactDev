#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H
#include <QDesktopWidget>

namespace Gui {
namespace Utils {
/**
 * @author Florent Berbie
 * @brief The WindowSettings class Utils function on windows
 */
class WindowSettings
{
public:
    /**
     * @brief WindowSettings::setMaximumSize Adapt the resolution of the window
     * <i>w</i>  to take all screen
     * @param w Current Window
     */
    static void setMaximumSize(QWidget &w);

    /**
     * @brief WindowSettings::setPositionToCenter Place the current window
     * <i>w</i> to the center of the screen
     * @param w Current Window
     */
    static void setPositionToCenter(QWidget &w);
};

}
}
#endif // WINDOWSETTINGS_H
