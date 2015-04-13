#ifndef SEARCHDOCK_H
#define SEARCHDOCK_H

#include <QDockWidget>

#include "models/search.h"
namespace Ui {
class SearchDock;
}

namespace Gui {
namespace Docks {
/**
 * @brief The SearchDock class Dock which contains search bar
 */
class SearchDock : public QDockWidget
{
    Q_OBJECT

public:
    /**
     * @brief SearchDock::SearchDock Construct a SearchDock
     * @param parent Widget Parent
     * @param flags Window flag
     */
    explicit SearchDock(QWidget *parent=0, Qt::WindowFlags flags = 0);
    ~SearchDock();

    /**
     * @brief SearchDock::getText Get the current text searched
     * @return Text searched
     */
    QString getText() const;

public slots:
    /**
     * @brief SearchDock::search Search elements in database which correspond
     * to the <i>text</i>
     * @param text Element to search
     */
    void search(QString text);

signals:
    /**
     * @brief SearchDock::textChanged Current text changed by <i>text</i>
     * @param text New text
     */
    void textChanged(QString text);

private:
    Ui::SearchDock *ui; //!< User interface
    QString _text;      //!< Search text

};

}
}
#endif // SEARCHDOCK_H
