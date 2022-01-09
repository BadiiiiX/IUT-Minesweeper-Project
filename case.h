//
// Created by Imane & Ranim;
//

#ifndef I_MINESWEEPER_CASE_H
#define I_MINESWEEPER_CASE_H

enum STATE {
    VISIBLE, HIDDEN, MARKED
};

enum {
    MINE = 9
};

struct Case {
    STATE state;
    unsigned content; //9 == MINE
};

/**
 * Show an element in minesweeper
 * @param bloc[in] Case to show
 * @return char to show.
 */
char showElement(Case &bloc);

/**
 * Mark a mine or a bloc
 * @param bloc[in, out] bloc to mark
 */
void markMine(Case &bloc);

#endif //I_MINESWEEPER_CASE_H
