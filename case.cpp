//
// Created by Imane & Ranim;
//

#include "case.h"

char showElement(Case &bloc) {
    switch (bloc.state) {

        case VISIBLE:
            if (bloc.content > 8) return 'm';
            if (bloc.content == 0) return ' ';
            return (char) (48 + bloc.content);
        case HIDDEN:
            return '.';
        case MARKED:
            return 'x';
    }
}

void markMine(Case &bloc) {
    bloc.state = STATE::MARKED;
}