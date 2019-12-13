#include "specimen.h"

#ifndef RANDOM_H
#define RANDOM_H

/* AllRandom always chooses whether to cooperate or deflect
 * randomly. It does not take into account previous encounters. */

class AllRandom : public Specimen
{
public:
    AllRandom();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;
    QColor getColor() override;
    std::string getPathBase() override;

    static const QColor color;
    static const std::string imgPath;
};

#endif // RANDOM_H
