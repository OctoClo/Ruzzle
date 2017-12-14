#ifndef LINKEDLETTER_H_INCLUDED
#define LINKEDLETTER_H_INCLUDED

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "Letter.h"

typedef struct LinkedLetter LinkedLetter;

struct LinkedLetter
{
    struct Letter* lett;
    LinkedLetter* next;
};

typedef struct Liste
{
    LinkedLetter* first;
} Liste;

Liste* listeInitialisation();

void listeInsertionBeginning(Liste*, struct Letter*);

void listeInsertionEnd(Liste*, struct Letter*);

void deleteFirstOfListe(Liste*);

void displayListe(Liste*);

int sizeListe(Liste*);

struct Letter* getLetterAtRank(Liste*, int);


#endif // LINKEDLETTER_H_INCLUDED
