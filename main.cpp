//
// Created by Imane & Ranim;
//

#include <iostream>
#include <random>
#include "grid.h"

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
                getResult(command);
                break;
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