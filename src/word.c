#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "linkedList.h"


void initWord(Word* w){
    w->head = NULL;
    initLetter(&w->head->letter, ' ');

}

void addLetter(Word* w, Letter l){
    LetterList* current = w->head;
    if(current->letter.character == NULL){
        current->letter = l;
    }else{
        while(current->nextLetter != NULL){
            current = current->nextLetter;
        }

        current->nextLetter = malloc(sizeof(LetterList));
        current->nextLetter->letter = l;
        current->nextLetter->nextLetter = NULL;
    }
}

void displayWord(Word* w){
    if(w->head != NULL){
        LetterList* current = w->head;

        while(current != NULL){
            printf("%c", current->letter.character);
            current = current->nextLetter;
        }
    }else{
        printf("Rien a afficher, mot vide");
    }

}
