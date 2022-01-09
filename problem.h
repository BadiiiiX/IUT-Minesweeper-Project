//
// Created by Imane & Ranim;
//

#ifndef I_MINESWEEPER_PROBLEM_H
#define I_MINESWEEPER_PROBLEM_H

struct Problem {
    unsigned lines, columns, mines;
    unsigned *minePos;
};

/**
 * @brief Return coord(x, y) about problem
 * @param pb[in] Problem to calc coords
 * @param pos[in] Position to translate
 * @param x[out] coord 'x'
 * @param y[out] coord 'y'
 */
void getCoords(Problem &pb, unsigned pos, unsigned &x, unsigned &y);

/**
 * @brief Setting up problem with lines, columns & mines
 * @param pb[out] problem to save
 */
void setProblem(Problem *pb);

/**
 * @brief Generate mines randomly
 * @param pb[in, out] problem to save mines position
 */
void generateMines(Problem &pb);

/**
 * @brief show problem
 * @param pb[in] problem to show values saved before
 */
void printProblem(Problem &pb);

/**
 * @brief delete all dynamic allocation
 * @param pb[in] problem to remove dynamic allocation
 */
void deleteProblem(Problem &pb);

/**
 * @brief create all problem from buffer
 */
void createProblem();

#endif //I_MINESWEEPER_PROBLEM_H
