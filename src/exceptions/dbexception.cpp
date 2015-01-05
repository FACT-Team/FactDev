#include "dbexception.h"
#include "log.h"
#include <QMessageBox>

/**
 * @brief DbException::popupMessage. Display a popup message with the message error.
 * @param parent
 */
void DbException::popupMessage(QWidget* parent)
{
    QMessageBox::critical(parent, "Erreur innatendue", _userError, "OK");
}

/**
 * @brief DbException::DbException. Construct an DbException.
 * @param userError ClassName of error
 * @param fctName Function name
 * @param logError Message error
 * @param errorCode Code of error
 */
DbException::DbException(const QString userError, const QString fctName, const QString logError, float errorCode) {
    Log::getInstance(ERREUR) << "["+QString::number(errorCode)+"] Erreur dans la fonction " + fctName;
    Log::getInstance(ERREUR) << logError;

    _userError = "<span style=\"font-size:10pt\">"+userError+"</span>";
    _userError += "<br/><br/><span style=\"font-size:7.3pt\">Nous vous conseillons de vous rapprocher auprès de l'association avec le code d'erreur inscrit ci-dessous<br/>"
            "Vous pouvez envoyer un e-mail à <a href=\"mailto:maintenance@afmck.fr\">maintenance@afmck.fr</a><br/><br/>";
    _userError += "<b>Erreur n°"+QString::number(errorCode)+"</b></span>";
}
