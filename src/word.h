#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Letter.h"
#include "LinkedLetter.h"

typedef struct _word
{
    Liste* word;
} Word;

Word* initWord(void);

void addLetterInWord(Word*, Letter*);
void displayWord(Word*);
int scoreWord(Word*);
int sizeWord(Word*);
int isEmptyWord(Word*);
void deleteLastLetter(Word*);
void unSelectWord(Word*);

char* getWord(Word*);
Letter* getLetter(Word*, int);

#endif // WORD_H_INCLUDED
