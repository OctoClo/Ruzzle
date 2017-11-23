#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
#include "LinkedLetter.h"


int main(int argc, char** argv)
{


    Liste *liste = listeInitialisation();
    listeInsertionBeginning(liste, 't');
    listeInsertionBeginning(liste, 'u');
    listeInsertionBeginning(liste, 'l');
    listeInsertionBeginning(liste, 'a');
    listeInsertionBeginning(liste, 's');
    displayListe(liste);

    printf("\n");

    Liste *liste2 = listeInitialisation();
    listeInsertionEnd(liste2, 's');
    listeInsertionEnd(liste2, 'a');
    listeInsertionEnd(liste2, 'l');
    listeInsertionEnd(liste2, 'u');
    listeInsertionEnd(liste2, 't');
    displayListe(liste2);



}
