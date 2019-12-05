#ifndef ESTRATEGY_H
#define ESTRATEGY_H

/* Each strategy (type of specimen) has its own int
 * that it's recognized by.
 * COUNT is used as a number of different strategies.
 * COUNT must always be the last in enum. */

enum strategy {
    Random,
    Dove,
    Hawk,
    TitForTat,
    TitForTwoTats,
    TwoTitsForTat,
    Pavlov,
    COUNT
};


#endif // ESTRATEGY_H
