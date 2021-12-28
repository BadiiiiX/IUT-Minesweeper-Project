//
// Created by BadiiiX on 28/12/2021.
//

#include <iostream>
#include <random>

enum STATE {
    VISIBlLE, HIDDEN, MARKED
};

enum {
    MINE = 9
};

struct Case {
    STATE state;
    unsigned content; //9 == MINE
};

struct Move {
    char action;
    unsigned pos;
};


struct Movements {
    unsigned moves;
    Move *moveList;
};

struct Problem {
    unsigned lines, columns, mines;
    unsigned *minePos;
};

struct Grid {
    Movements mo;
    Problem pb;
    Case **ms; //ms like minesweeper
};

void getCoords(Problem &pb, unsigned pos, unsigned &x, unsigned &y) {
    x = pos / pb.columns;
    y = pos % pb.columns;
}

bool validCoords(Grid &grid, unsigned x, unsigned y) {
    return x < grid.pb.lines && y < grid.pb.columns;
}

void setProblem(Problem *pb) {
    unsigned lines, columns, mines;
    std::cin >> lines >> columns >> mines;
    pb->lines = lines;
    pb->columns = columns;
    pb->mines = mines;
    pb->minePos = new unsigned[pb->mines];
}

void generateMines(Problem &pb) {
    unsigned limit = pb.lines * pb.columns - 1;
    for (unsigned i = 0; i < pb.mines; i++) {
        unsigned minePos = rand() % limit;
        pb.minePos[i] = minePos;
    }
}

void printProblem(Problem &pb) {
    std::cout << pb.lines << " "
              << pb.columns << " "
              << pb.mines << " ";
    for (unsigned i = 0; i < pb.mines; i++) {
        std::cout << pb.minePos[i] << " ";
    }
    std::cout << '\n';
}

void deleteProblem(Problem &pb) {
    delete[] pb.minePos;
}

void setMines(Grid &grid) {
    unsigned limit = grid.pb.lines * grid.pb.columns - 1;
    for (unsigned i = 0; i < grid.pb.mines; i++) {
        unsigned mP;
        std::cin >> mP;
        grid.pb.minePos[i] = mP;
    }
}

void generateMS(Grid &grid) {
    grid.ms = new Case *[grid.pb.lines];
    for (unsigned x = 0; x < grid.pb.lines; x++) {
        grid.ms[x] = new Case[grid.pb.columns];
        for (unsigned y = 0; y < grid.pb.columns; y++) {
            grid.ms[x][y].content = 0;
            grid.ms[x][y].state = STATE::HIDDEN;
        }
    }
}

void placeMines(Grid &grid) {
    for (unsigned m = 0; m < grid.pb.mines; m++) {
        unsigned x, y;
        getCoords(grid.pb, grid.pb.minePos[m], x, y);
        grid.ms[x][y].content = MINE;
    }
}

void addMineAdj(Grid &grid, unsigned &x, unsigned &y) {
    enum {
        COUNT_TEST = 8
    };
    unsigned int coords[COUNT_TEST][2] =
            {
                    {x,     y + 1},
                    {x,     y - 1},
                    {x + 1, y},
                    {x + 1, y + 1},
                    {x + 1, y - 1},
                    {x - 1, y},
                    {x - 1, y + 1},
                    {x - 1, y - 1},
            };

    for (unsigned t = 0; t < COUNT_TEST; t++) {
        if (validCoords(grid, coords[t][0], coords[t][1])) {
            if (grid.ms[coords[t][0]][coords[t][1]].content < 8) grid.ms[coords[t][0]][coords[t][1]].content += 1;
        }
    }
}

void fillMS(Grid &grid) {
    for (unsigned x = 0; x < grid.pb.lines; x++) {
        for (unsigned y = 0; y < grid.pb.columns; y++) {
            if (grid.ms[x][y].content == MINE) {
                addMineAdj(grid, x, y);
            }
        }
    }
}

char showElement(Case &bloc) {
    switch (bloc.state) {

        case VISIBlLE:
            if (bloc.content > 8) return 'm';
            if (bloc.content == 0) return ' ';
            return (char) (48 + bloc.content);
        case HIDDEN:
            return '.';
        case MARKED:
            return 'x';
    }
}

void maskMine(Case &bloc) {
    bloc.state = STATE::MARKED;
}

void unmaskMine(Grid &grid, unsigned x, unsigned y) {
    enum {
        COUNT_TEST = 8
    };
    unsigned int coords[COUNT_TEST][2] =
            {
                    {x + 0, y + 1},
                    {x + 0, y - 1},
                    {x + 1, y + 0},
                    {x + 1, y + 1},
                    {x + 1, y - 1},
                    {x - 1, y + 0},
                    {x - 1, y + 1},
                    {x - 1, y - 1},
            };

    if(!validCoords(grid, x, y)) return;
    Case &c = grid.ms[x][y];

    if(c.state == STATE::VISIBlLE) return;
    c.state = STATE::VISIBlLE;

    if (c.content != 0) return;

    for (unsigned t = 0; t < COUNT_TEST; t++) {
        unmaskMine(grid, coords[t][0], coords[t][1]);
    }
}

void setMoves(Grid &grid) {
    std::cin >> grid.mo.moves;
    grid.mo.moveList = new Move[grid.mo.moves];
    for (unsigned m = 0; m < grid.mo.moves; m++) {
        std::cin >> grid.mo.moveList[m].action;
        std::cin >> grid.mo.moveList[m].pos;
    }
}

void executeMoves(Grid &grid) {
    for (unsigned m = 0; m < grid.mo.moves; m++) {
        unsigned x, y;
        getCoords(grid.pb, grid.mo.moveList[m].pos, x, y);
        if(grid.mo.moveList[m].action == 'D') {
            unmaskMine(grid, x, y);
        }

        if(grid.mo.moveList[m].action == 'M') {
            maskMine(grid.ms[x][y]);
        }
    }
}

void showGrid(Grid &grid) {

    std::cout << grid.pb.lines << " " << grid.pb.columns << '\n';
    for (unsigned int x = 0; x < grid.pb.lines; x++) {
        for (unsigned line = 0; line < grid.pb.columns; line++) {
            std::cout << " ___";
        }
        std::cout << "\n";
        for (unsigned int y = 0; y < grid.pb.columns; y++) {

            if (y == 0) std::cout << "| ";
            else std::cout << ' ';

            std::cout << showElement(grid.ms[x][y])
                      << " |";
        }
        std::cout << '\n';
    }
    for (unsigned line = 0; line < grid.pb.columns; line++) {
        std::cout << " ___";
    }
    std::cout << '\n';
}

void deleteGrid(Grid &grid) {
    delete[] grid.pb.minePos;
    for (unsigned i = 0; i < grid.pb.lines; i++) {
        delete[] grid.ms[i];
    }
    delete[] grid.ms;
}


void createProblem() {
    Problem pb{};
    setProblem(&pb);

    generateMines(pb);

    printProblem(pb);

    deleteProblem(pb);
}

void createGrid() {
    Grid grid{};
    setProblem(&grid.pb);

    setMines(grid);

    generateMS(grid);

    placeMines(grid);

    fillMS(grid);

    setMoves(grid);

    executeMoves(grid);

    showGrid(grid);

    deleteGrid(grid);
}

int main() {
    srand((unsigned) time(nullptr));

    unsigned command;
    bool launch = true;
    while (launch) {
        std::cin >> command;
        switch (command) {
            case 1:
                createProblem();
                break;
            case 2:
                createGrid();
                break;
            case 3:
            case 4:
            case 5:
                std::cout << "Commande inconnue...";
                break;
            case 6:
                launch = false;
                break;
            default:
                std::cout << "Commande inconnue...";
                break;
        }
    }
}