#ifndef POPUP_H
#define POPUP_H

#include <QString>
#include <QWidget>
#include <QMessageBox>

#include "utils/log.h"

namespace Gui {
namespace Widgets {
/**
 * @brief Class for display popup quickly
 * @author Antoine de Roquemaurel
 */
class Popup
{
public:
    /**
     * @brief Popup::toImplement Method to display a critical message : feature
     * is not implemented now.
     */
    static void toImplement(QString, QWidget*);
};
}
}
#endif // POPUP_H
