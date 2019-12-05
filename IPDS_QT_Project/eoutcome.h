#ifndef EOUTCOME_H
#define EOUTCOME_H

/* A quick way to describe possible outcomes
 * of a round of prisoner's dilemma:
 ** R - Reward
 **     Both parties cooperated and get rewarded.
 ** T - Temptation Reward
 **     A deflected and B cooperated, so A gets
 **     a temptation reward.
 ** S - Sucker's Punishment
 **     A deflected and B cooperated, so B gets
 **     sucker's punishment.
 ** P - Punishment
 **     Both parties deflected and get punished. */

enum outcome {
    R, // Reward
    T, // Temptation Reward
    S, // Sucker's Punishment
    P  // Punishment
};

#endif // EOUTCOME_H
