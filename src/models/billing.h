#ifndef BILLING_H
#define BILLING_H
#include <QString>
#include <QDate>
#include <QMap>
#include <QList>

#include "models/idatabasemodel.h"
#include "models/project.h"
#include "models/contributory.h"

/**
 * @brief The Billing class : Billing of a Customer
 *
 */
class Billing : public IDatabaseModel
{
public:
    /**
     * @brief Billing::Billing. Construct a Billing.
     */
    Billing();

    /**
     * @brief Billing::commit. Insert a modification
     * in Billing table on the database.
     */
    void commit();

    /**
     * @brief Billing::hydrat. Update of the Billing which is specified
     * by <i>getId</i>
     * @param getId
     */
    void hydrat(int getId);

    /**
     * @brief Billing::remove. Remove a Billing.
     */
    void remove();

    /**
     * @brief Billing::getContributories. Return a map of <b>Contributory</b>
     * for each <b>Project</b> of the <b>Billing</b>
     * @return QMap<Project, QList<Contributory>>
     */
    QMap<Project, QList<Contributory> > getContributories() const;
    void setContributories(const QMap<Project, QList<Contributory> > &getContributories);

    /**
     * @brief Billing::getTitle. return title of <b>Billing</b>
     * @return title of Billing
     */
    QString getTitle() const;

    /**
     * @brief Billing::setTitle. Modify the title of <b>Billing</b>
     * @param getTitle Modify the title with <i>getTitle</i>
     */
    void setTitle(const QString &getTitle);

    /**
     * @brief Billing::getNumber. Return number of the <b>Billing</b>.
     * @return _number of Billing
     */
    int getNumber() const;

    /**
     * @brief Billing::setNumber. Modify <i>_number</i> of Billing.
     * @param getNumber the new number of the Billing
     */
    void setNumber(int getNumber);

    /**
     * @brief Billing::isBilling. Return if it's a billing or a quote.
     * @return if it's billing or a quote
     */
    bool isBilling() const;

    /**
     * @brief Billing::setIsBilling. Modify <i>isBilling</i>
     * of <b>Billing</b>.
     * @param isBilling
     */
    void setIsBilling(bool isBilling);

    /**
     * @brief Billing::getDate. return date of the <b>Billing</b>
     * @return date of Billing
     */
    QDate getDate() const;

    /**
     * @brief Billing::setDate. Modify <i>date</i> of the <b>Billing</b>
     * @param getDate the new date of the Billing
     */
    void setDate(const QDate &getDate);

private:
    QMap<Project,QList<Contributory> > _contributories; //!<
    QString _title;     //!<
    int _number;        //!<
    bool _isBilling;    //!<
    QDate _date;        //!<


};

#endif // BILLING_H
