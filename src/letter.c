#include <stdlib.h>
#include "letter.h"


void initLetter(Letter* letter, char c){
    switch (c){
    case 'a':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'b':
        letter->weight = 3;
        letter->character = c;
        break;
    case 'c':
        letter->weight = 3;
        letter->character = c;
        break;
    case 'd':
        letter->weight = 2;
        letter->character = c;
        break;
    case 'e':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'f':
        letter->weight = 4;
        letter->character = c;
        break;
    case 'g':
        letter->weight = 2;
        letter->character = c;
        break;
    case 'h':
        letter->weight = 4;
        letter->character = c;
    case 'i':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'j':
        letter->weight = 8;
        letter->character = c;
        break;
    case 'k':
        letter->weight = 10;
        letter->character = c;
        break;
    case 'l':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'm':
        letter->weight = 2;
        letter->character = c;
        break;
    case 'n':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'o':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'p':
        letter->weight = 3;
        letter->character = c;
        break;
    case 'q':
        letter->weight = 8;
        letter->character = c;
        break;
    case 'r':
        letter->weight = 1;
        letter->character = c;
        break;
    case 's':
        letter->weight = 1;
        letter->character = c;
        break;
    case 't':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'u':
        letter->weight = 1;
        letter->character = c;
        break;
    case 'v':
        letter->weight = 4;
        letter->character = c;
        break;
    case 'w':
        letter->weight = 10;
        letter->character = c;
        break;
    case 'x':
        letter->weight = 10;
        letter->character = c;
        break;
    case 'y':
        letter->weight = 10;
        letter->character = c;
        break;
    case 'z':
        letter->weight = 10;
        letter->character = c;
        break;
    default:
        letter->weight = 1;
        letter->character = 'a';
        break;
    }


}


int calculScoreLetter(Letter* l){
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
