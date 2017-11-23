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

void listeInsertionBeginning(Liste *liste, char c);

void listeInsertionEnd(Liste *liste, char c);

void deleteFirstOfListe(Liste *liste);

void displayListe(Liste *liste);


#endif // LINKEDLETTER_H_INCLUDED
