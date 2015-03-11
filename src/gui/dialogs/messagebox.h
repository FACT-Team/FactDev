#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

namespace Ui {
class MessageBox;
}
namespace Gui {
namespace Dialogs {
/**
 * @author Florent Berbie
 * @brief The MessageBox class Information window with message
 */
class MessageBox : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief MessageBox::MessageBox Construt a <b>MessageBox</b>
     * @param parent
     */
    explicit MessageBox(QWidget *parent = 0);
    ~MessageBox();

    /**
     * @brief MessageBox::showAboutFact Shows window about FACT team
     */
    void static showAboutFact();

    /**
     * @brief MessageBox::showAboutFactDev Shows window about FactDev software
     */
    void static showAboutFactDev();

    /**
     * @brief MessageBox::showAboutIcons Shows about icons theme of FactDev
     * software
     */
    void static showAboutIcons();

    /**
     * @brief MessageBox::aboutFact Defines FACT team information
     */
    void aboutFact();

    /**
     * @brief MessageBox::aboutFactDev Defines FactDev software information
     */
    void aboutFactDev();

    /**
     * @brief MessageBox::aboutIcons Defines icons theme information
     */
    void aboutIcons();

    /**
     * @brief MessageBox::setImage Add the icon <i>img</i> to the current window
     * @param img Icon
     * @param width Icon width (default: 128)
     * @param height Icon height (default: 128)
     */
    void setImage(QString img, int width = 128, int height = 128);

    /**
     * @brief MessageBox::setText Add the text <i>txt</i> to the current window
     * @param txt Text inside the current window
     */
    void setText(QString txt);

private:
    Ui::MessageBox *ui; //!< User interface
};
}
}
#endif // MESSAGEBOX_H
