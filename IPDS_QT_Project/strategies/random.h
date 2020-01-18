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

    QColor getColor() override;
    std::string getPathBase() override;
    static const QColor COLOR;
    static const QColor GRAPHCOLOR;
    static const std::string NAME;
    static const std::string IMG_PATH;

private:
    void performUpdate(outcome o, int enemyID) override;
};

#endif // RANDOM_H
