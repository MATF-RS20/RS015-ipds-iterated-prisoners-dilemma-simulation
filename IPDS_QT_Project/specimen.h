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
    Specimen();

    virtual ~Specimen() override = default;

    Specimen(Specimen& s);
    Specimen(std::string imgPath);

    Specimen& operator=(Specimen& s);

    Specimen(Specimen&& s);

    Specimen& operator=(Specimen&& s);

    int getTotalFoodEaten(void) const;

    int resetTotalFoodEaten(void);

    /* Checks whether specimen will choose to cooperate
     * with a certain enemy based on the particular specimen's
     * strategy and past experiences. */
    virtual bool isCooperating(int enemyID) = 0;

    /* Based on the outcome of a round, updates given Specimen's
     * info on the opponent it has encountered and food it has
     * eaten.
     */
    void update(outcome res, int enemyID);

    /*  Getters and setters for current x and y coordinates
     */
    double getX();
    double getY();

    void setX(double x);
    void setY(double y);

    /* Method that fetches the color of the specimen,
     * used mostly for plotting
     */
    virtual QColor getColor()=0;

    /* Method that fetches the base of the path for the derived
     * specimen type, used for graphic simulation
     */
    virtual std::string getPathBase()=0;

    /* Defines rough boundries for this graphic item*/
    QRectF boundingRect() const override;

    /* Defines precise shape for this graphic item */
    QPainterPath shape() const override;

    /* Draws the chick in it's starting position */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    /* Unique identifier of a speciman */
    const unsigned SPECIMEN_ID;


protected:
    void advance(int step) override;
    int m_foodEatenLastRound = 0;
    int m_totalFoodEaten = 0;

    void calculateFood(outcome o);

private:
    /*  Current X and Y coordinates of specimen
     *  These coordinates will be updated only inside the graphicSim class,
     *  which will also manually invoke
     */
    double m_x,m_y;

    /* Update calls this with specific implementations
     * of derived classes
     */
    virtual void performUpdate(outcome o, int enemyID) = 0;

    /* Used to ensure IDs are unique */
    static unsigned ID;

    /* Payoffs for each outcome */
    const int R_PAYOFF = 4;
    const int T_PAYOFF = 3;
    const int P_PAYOFF = 1;
    const int S_PAYOFF = 0;
};

#endif // SPECIMEN_H
