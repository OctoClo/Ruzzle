#ifndef LINKEDLETTER_H_INCLUDED
#define LINKEDLETTER_H_INCLUDED
#include "letter.h"

typedef struct LinkedLetter LinkedLetter;

struct LinkedLetter{
    Letter *lett;
    LinkedLetter *next;
};

typedef struct Liste{
    LinkedLetter *first;
}Liste;

Liste *listeInitialisation();

void listeInsertionBeginning(Liste*, Letter*);

void listeInsertionEnd(Liste*, Letter*);

void deleteFirstOfListe(Liste*);

void displayListe(Liste*);

int sizeListe(Liste*);

Letter* getLetterAtRank(Liste*, int);


#endif // LINKEDLETTER_H_INCLUDED
