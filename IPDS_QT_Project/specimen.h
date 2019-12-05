#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

class Specimen
{
public:
    Specimen();

    virtual ~Specimen() = default;

    Specimen(Specimen& s);

    Specimen& operator=(Specimen& s);

    Specimen(Specimen&& s);

    Specimen& operator=(Specimen&& s);

    /* Checks whether specimen will choose to cooperate
     * with a certain enemy based on the particular specimen's
     * strategy and past experiences. */
    virtual bool isCooperating(int enemyID) = 0;

    /* Unique identifier of a speciman */
    const unsigned specimenID;

    /* Color coding and appearance image
     * for specific strategies */
    //TODO: Maybe static in derived classes rather than here?
    const QColor color;
    const std::string imgPath;

private:
    /* Used to ensure IDs are unique */
    static unsigned ID;
};

#endif // SPECIMEN_H
