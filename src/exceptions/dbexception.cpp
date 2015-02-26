#include "dbexception.h"

namespace Exceptions {
DbException::DbException(const QString userError, const QString fctName,
    const QString logError, float errorCode)
{
    Utils::Log::instance(Utils::ERROR) <<
        "["+QString::number(errorCode)+"] Erreur dans la fonction " + fctName;
    Utils::Log::instance(Utils::ERROR) << logError;

    _userError = "<span style=\"font-size:10pt\">"+userError+"</span>";
    _userError +=   "<br/><br/><span style=\"font-size:7.3pt\">"
                    "Nous vous conseillons de vous rapprocher auprès de l'"
                    "association avec le code d'erreur inscrit ci-dessous<br/>"
                    "Vous pouvez envoyer un e-mail à "
                    "<a href=\"mailto:ups.fact@gmail.com\">"
                    "ups.fact@gmail.com</a><br/><br/>";
    _userError += "<b>Erreur n°"+QString::number(errorCode)+"</b></span>";
}

void DbException::popupMessage(QWidget* parent)
{
    QMessageBox::critical(parent, "Erreur innatendue", _userError, "OK");
}
}
