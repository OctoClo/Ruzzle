#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
#include "LinkedLetter.h"

typedef struct Word{
    Liste* word;
}Word;


Word* initWord(void);

Word* initWordNotEmpty(char*);

void addLetterInWord(Word*, Letter*);

void displayWord(Word*);

char* getWord(Word*);

int scoreWord(Word*);

int sizeWord(Word*);

Letter* getLetter(Word*, int);





#endif // WORD_H_INCLUDED
