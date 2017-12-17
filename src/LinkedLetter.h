#ifndef LINKEDLETTER_H_INCLUDED
#define LINKEDLETTER_H_INCLUDED

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "Letter.h"

typedef struct _linkedLetter
{
    Letter* lett;
    struct _linkedLetter* next;
} LinkedLetter;

typedef struct _liste
{
    LinkedLetter* first;
} Liste;

Liste* listeInitialisation();

void listeInsertionBeginning(Liste*, Letter*);

void listeInsertionEnd(Liste*, Letter*);

void deleteFirstOfListe(Liste*);

Liste* deleteLastOfListe(Liste*);

void displayListe(Liste*);

int sizeListe(Liste*);

Letter* getLetterAtRank(Liste*, int);


#endif // LINKEDLETTER_H_INCLUDED
