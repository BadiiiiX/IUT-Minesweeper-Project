//
// Created by Imane & Ranim;
//

#ifndef I_MINESWEEPER_GRID_H
#define I_MINESWEEPER_GRID_H

#include "case.h"
#include "problem.h"

struct Grid {
    Problem pb;
    Case **ms; //MineSweeper
};

/**
 * @brief Know if coords(x, y) are exact
 * @param grid[in] grid to get problem values
 * @param x[in] x to verify
 * @param y[in] y to verify
 * @return true if (x, y) are valid, false else
 */
bool validCoords(Grid &grid, unsigned x, unsigned y);

/**
 * @brief set mine from buffer
 * @param grid[in, out] grid to save values
 */
void setMines(Grid &grid);

/**
 * @brief generate minesweeper
 * @param grid[in, out] grid to save minesweeper
 */
void generateMS(Grid &grid);

/**
 * @brief place mines in minesweeper
 * @param grid[in, out] grid to save minesweeper
 */
void placeMines(Grid &grid);

/**
 * @brief add +1 in case where they adjacent from a mine
 * @param grid[in, out] grid to save minesweeper
 * @param x[in] mine x coord
 * @param y[in] mine y coord
 */
void addMineAdj(Grid &grid, unsigned &x, unsigned &y);

/**
 * @brief place values in minesweeper
 * @param grid[in, out] grid to save minesweeper
 */
void fillMS(Grid &grid);

/**
 * @brief Unmask a case
 * @param grid[in, out] grid to save minesweeper
 * @param x[in] case x coord
 * @param y[in] case y coord
 */
void unmaskMine(Grid &grid, unsigned x, unsigned y);

/**
 * @brief execute moves about buffer
 * @param grid[in] grid to get minesweeper
 */
void executeMoves(Grid &grid);

/**
 * @brief show grid
 * @param grid[in] grid to get minesweeper
 */
void showGrid(Grid &grid);

/**
 * Announce if game is won or no
 * @param grid[in] grid to get minesweeper
 * @return true if game is won, false else
 */
bool gameWon(Grid &grid);

/**
 * Announce if game is lost or no
 * @param grid[in] grid to get minesweeper
 * @return true if game is lost, false else
 */
bool gameLost(Grid &grid);

/**
 * Return to buffer if game is win or lost
 * @param grid[in] grid to get minesweeper
 * @param cmd get cmd to execute
 */
void showResult(Grid &grid, unsigned cmd);

/**
 * Return string to play, read buffer
 * @param grid[in] grid to get Problem
 */
void getActionToPlay(Grid &grid);

/**
 * @brief delete all dynamic allocation
 * @param grid grid to delete dynamic allocation
 */
void deleteGrid(Grid &grid);

/**
 * @brief create all grid from buffer
 */
void createGrid();

/**
 * @brief Return game state
 * @param cmd get cmd to execute
 */
void getResult(unsigned cmd);

/**
 * @brief read grid and drop next action to do
 */
void readGrid();

#endif //I_MINESWEEPER_GRID_H
