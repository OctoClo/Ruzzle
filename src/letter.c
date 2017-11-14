#include <stdlib.h>
#include "letter.h"


void initLetter(Letter* letter, char c){
    switch (c){
    case 'a':
        letter->weight = 1;
        letter->character = 'a';
        letter->modif = DOUBLE_LETTER;
        break;
    case 'b':
        letter->weight = 3;
        letter->character = 'b';
        break;
    case 'c':

        break;
    case 'd':

        break;
    case 'e':

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
    }

    return score;

}
