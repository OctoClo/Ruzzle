#include <stdio.h>
#include <stdlib.h>
#include "LinkedLetter.h"


Liste *listeInitialisation(){
    Liste *liste = malloc(sizeof(*liste));
    LinkedLetter *linkedLetter = malloc(sizeof(*linkedLetter));

    if(liste == NULL || linkedLetter == NULL){
        exit(EXIT_FAILURE);
    }

    linkedLetter->lett = initLetter(' ');
    linkedLetter->next = NULL;
    liste->first = linkedLetter;

    return liste;

}

void listeInsertionBeginning(Liste *liste, char c){
    LinkedLetter *newLink = malloc(sizeof(*newLink));

    if(liste == NULL || newLink == NULL){
        exit(EXIT_FAILURE);
    }

    newLink->lett = initLetter(c);

    if(liste->first->lett->character == ' '){
        newLink->next = NULL;
    }else{
        newLink->next = liste->first;
    }
    liste->first = newLink;

}

void listeInsertionEnd(Liste *liste, char c){
    LinkedLetter *newLink = malloc(sizeof(*newLink));

    if(liste == NULL || newLink == NULL){
        exit(EXIT_FAILURE);
    }

    newLink->lett = initLetter(c);
    newLink->next = NULL;


    LinkedLetter *current = liste->first;

    if(liste->first->lett->character == ' '){
        liste->first = newLink;
        return;
    }

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newLink;

    return;




}

void deleteFirstOfListe(Liste *liste){
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }

    if(liste->first != NULL){
        LinkedLetter *toDelete = liste->first;
        liste->first = liste->first->next;
        free(toDelete);
    }

}

void displayListe(Liste *liste){
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }

    LinkedLetter *current = liste->first;

    while(current != NULL){
        printf("%c", current->lett->character);
        current = current->next;
    }
}

int sizeListe(Liste *liste){
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }
    int count = 0;

    LinkedLetter *current = liste->first;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}

Letter* getLetterAtRank(Liste *liste, int rank){
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }

    LinkedLetter *current = liste->first;

    for(int i=1; i<rank; i++){
        current = current->next;
    }

    return current->lett;
}
