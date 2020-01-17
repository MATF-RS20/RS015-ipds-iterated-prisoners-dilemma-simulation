#include "specimen.h"

#ifndef TITFORTWOTATS_H
#define TITFORTWOTATS_H

/* TitForTwoTats is a more forgiving version of TitForTat.
 * It starts by cooperating and keeps cooperating until the
 * opponent deflects twice in a row. As long as oppontent's
 * last two moves were deflections, it will keep deflecting. */

class TitForTwoTats : public Specimen
{
public:
    TitForTwoTats();

    bool isCooperating(int enemyID) override;

    QColor getColor() override;
    std::string getPathBase() override;
    static const QColor COLOR;
    static const QColor GRAPHCOLOR;
    static const std::string IMG_PATH;

private:
    std::map<int,int> m_mapDeflectionInARow;

    void performUpdate(outcome o, int enemyID) override;
};

#endif // TITFORTWOTATS_H
