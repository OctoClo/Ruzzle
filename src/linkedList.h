#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "letter.h"

typedef struct LetterList{
    Letter letter;
    struct LetterList* nextLetter;
}LetterList;




#endif // LINKEDLIST_H_INCLUDED
