//
// Created by BadiiiX on 28/12/2021.
//

#include <iostream>
#include <random>

enum STATE {
    VISIBlLE, HIDDEN, MARKED
};

struct Case {
    STATE state;
    unsigned content; //9 == MINE
};

struct Problem {
    unsigned lines, columns, mines;
    unsigned *minePos;
};

void setProblem(Problem &pb) {
    unsigned lines, columns, mines;
    std::cin >> lines >> columns >> mines;
    pb.lines = lines;
    pb.columns = columns;
    pb.mines = mines;
    pb.minePos = new unsigned[pb.mines];
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

void createProblem() {
    Problem pb{};
    setProblem(pb);

    generateMines(pb);

    printProblem(pb);

    deleteProblem(pb);
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