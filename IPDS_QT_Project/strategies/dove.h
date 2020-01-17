#include "specimen.h"

#ifndef DOVE_H
#define DOVE_H

/* Dove always cooperates with the enemy no matter what.
 * It does not take into account previous encounters. */

class Dove : public Specimen
{
public:
    Dove();
    bool isCooperating(int enemyID) override;

    QColor getColor() override;
    std::string getPathBase() override;
    static const QColor COLOR;
    static const QColor GRAPHCOLOR;
    static const std::string IMG_PATH;

private:
    void performUpdate(outcome o, int enemyID) override;
};

#endif // DOVE_H
