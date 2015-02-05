#include "popup.h"
namespace Gui {
namespace Widgets {
void Popup::toImplement(QString str, QWidget* w)
{
    QMessageBox::critical
            (w,
             "Non implémenté",
             "La fonction demandée n'est pas encore implémenté.<br/>"+
             str,
             "OK");
    Utils::Log::instance(Utils::WARNING) << "TODO Implement me" << str;

}
}
}
