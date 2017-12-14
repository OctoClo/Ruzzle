#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Letter.h"
#include "LinkedLetter.h"

typedef struct Word Word;

struct Word
{
    struct Liste* word;
};

Word* initWord(void);

void addLetterInWord(Word*, struct Letter*);
void displayWord(Word*);
int scoreWord(Word*);
int sizeWord(Word*);

char* getWord(Word*);
struct Letter* getLetter(Word*, int);

#endif // WORD_H_INCLUDED
