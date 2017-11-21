#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
#include "linkedList.h"

typedef struct Word{
    LetterList* head;

}Word;

void initWord(Word* w);

void addLetter(Word* w, Letter l);

void displayWord(Word* w);



#endif // WORD_H_INCLUDED
