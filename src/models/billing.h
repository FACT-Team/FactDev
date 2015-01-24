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
 * @author Cédric Rohaut @Oxynos for the quote part
 * @brief The Billing class : Billing or Quote of a Customer
 */
class Billing : public IDatabaseModel
{
public:
    /**
     * @brief Billing::Billing. Construct a Billing.
     */
    Billing();

    /**
     * @brief Billing::Billing. Construct a Billing or quote.
     * @param int id
     */
    Billing(int id);

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
    QMap<Project *, QList<Contributory*>*> getContributories() const;

    void setContributories(QMap<Project*, QList<Contributory*>*> contributories);

    /**
     * @brief addContributories Add a new contributory for project p
     * @param p The Project who contain Contributory
     * @param c The new Contributory
     */
    void addContributories(Project *p, Contributory *c);

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
     * @brief Billing::getDescription. return description of <b>Billing</b>
     * @return description of Billing
     */
    QString getDescription() const;

    /**
     * @brief Billing::setDescription. Modify the description of <b>Billing</b>
     * @param getDescription Modify the description with <i>getDescription</i>
     */
    void setDescription(const QString &getDescription);

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
    QMap<Project*,QList<Contributory*>*> _contributories;   //!< List of contributories
    QString _title;                                         //!< Title of billing
    QString _description;
    int _number;                                            //!< Number of billing
    bool _isBilling;                                        //!< Is a billing… Or if a quote
    QDate _date;                                            //!< Date for billing


};

#endif // BILLING_H
