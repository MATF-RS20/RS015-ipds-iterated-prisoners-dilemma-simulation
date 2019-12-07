#ifndef ESTRATEGY_H
#define ESTRATEGY_H

/* Each strategy (type of specimen) has its own int
 * that it's recognized by.
 * COUNT is used as a number of different strategies.
 * COUNT must always be the last in enum. */

enum strategy {
    E_DOVE,
    E_HAWK,
    E_PAVLOV,
    E_RANDOM,
    E_TITFORTAT,
    E_TITFORTWOTATS,
    E_TWOTITSFORTAT,
    COUNT
};


#endif // ESTRATEGY_H
