#include "graphics.h"
#include "eoutcome.h"
#include <QGraphicsItem>
#ifndef SPECIMEN_H
#define SPECIMEN_H

/* Specimen is an abstract class describing all possible
 * strategies in the game. It forces its derived classes
 * to implement prisoner's dilemma behavior (update info
 * of previous encounters and state their next move), as
 * well as some general graphical info regarding different
 * strategies. */


class Specimen : public QGraphicsItem
{
public:
    Specimen(QColor color, std::string imgPath);

    virtual ~Specimen() = default;

    Specimen(Specimen& s);
    Specimen(std::string imgPath);

    Specimen& operator=(Specimen& s);

    Specimen(Specimen&& s);

    Specimen& operator=(Specimen&& s);

    /* Defines rough boundries for this graphic item */
    QRectF boundingRect() const override;

    /* Defines precise shape for this graphic item */
    QPainterPath shape() const override;

    /* Draws the bloody thing */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    /* Checks whether specimen will choose to cooperate
     * with a certain enemy based on the particular specimen's
     * strategy and past experiences. */
    virtual bool isCooperating(int enemyID) = 0;

    /* Based on the outcome of a round, updates given Specimen's
     * info on the opponent it has encountered. Leave the
     * implementation empty if the strategy doesn't take previous
     * encounters into account. */
    virtual void update(outcome res, int enemyID) = 0;

    /* Unique identifier of a speciman */
    const unsigned specimenID;

    /* Color coding and appearance image
     * for specific strategies */

    const QColor color;
    const std::string imgPath;

protected:
    void advance(int step) override;

private:
    /* Used to ensure IDs are unique */
    static unsigned ID;
};

#endif // SPECIMEN_H
