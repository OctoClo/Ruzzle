#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
#include "word.h"
#include "linkedList.h"


int main(int argc, char** argv)
{


    Letter l;
    initLetter(&l, 'q');
    printf("%c = %d pts\n", l.character, calculScoreLetter(&l));
    Word w;
    Word* wPtr = &w;
    initWord(wPtr);
    //Letter test = wPtr->head->letter;
//    test = l;
    //printf("%c", test.character);
    /*if(wPtr->head->letter==NULL){
        printf("letter head est NULL");
    }else{
        printf("letter head not NULL");
    }*/
        //addLetter(wPtr, &l);
    /*wPtr->head = NULL;
    wPtr->head = malloc(sizeof(LetterList));
    if(wPtr->head == NULL){
        return 1;
    }

    wPtr->head->letter = &l;
    wPtr->head->nextLetter = NULL;*/
    //displayWord(wPtr);



}
