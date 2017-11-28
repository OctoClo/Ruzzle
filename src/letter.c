#include <stdlib.h>
#include <stdio.h>
#include "letter.h"


Letter* initLetter(char c){
    Letter *letter = malloc(sizeof(Letter));
    letter->modif = NONE;
    letter->row = 0;
    letter->column = 0;
    switch (c){
    case 'a':
        letter->weight = 1;
        break;
    case 'b':
        letter->weight = 3;
        break;
    case 'c':
        letter->weight = 3;
        break;
    case 'd':
        letter->weight = 2;
        break;
    case 'e':
        letter->weight = 1;
        break;
    case 'f':
        letter->weight = 4;
        break;
    case 'g':
        letter->weight = 2;
        letter->character = c;
        break;
    case 'h':
        letter->weight = 4;
    case 'i':
        letter->weight = 1;
        break;
    case 'j':
        letter->weight = 8;
        break;
    case 'k':
        letter->weight = 10;
        break;
    case 'l':
        letter->weight = 1;
        break;
    case 'm':
        letter->weight = 2;
        break;
    case 'n':
        letter->weight = 1;
        break;
    case 'o':
        letter->weight = 1;
        break;
    case 'p':
        letter->weight = 3;
        break;
    case 'q':
        letter->weight = 8;
        break;
    case 'r':
        letter->weight = 1;
        break;
    case 's':
        letter->weight = 1;
        break;
    case 't':
        letter->weight = 1;
        break;
    case 'u':
        letter->weight = 1;
        break;
    case 'v':
        letter->weight = 4;
        break;
    case 'w':
        letter->weight = 10;
        break;
    case 'x':
        letter->weight = 10;
        break;
    case 'y':
        letter->weight = 10;
        break;
    case 'z':
        letter->weight = 10;
        break;
    default:
        letter->weight = 0;
        letter->character = ' ';
        break;
    }
    letter->character = c;

    return letter;


}


int scoreLetter(Letter* l){
    int score;
    switch(l->modif){
    case DOUBLE_LETTER:
        score = l->weight*2;
        break;
    case TRIPLE_LETTER:
        score = l->weight*3;
        break;
    case DOUBLE_WORD:
        score = l->weight;
        break;
    case TRIPLE_WORD:
        score = l->weight;
        break;
    case NONE:
        score = l->weight;
        break;
    default:
        score = l->weight;
        break;
    }

    return score;

}
