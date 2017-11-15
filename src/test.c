#include <stdio.h>
#include <stdlib.h>
#include "letter.h"


int main(int argc, char** argv)
{


    printf("OUI\n");
    Letter l;
    initLetter(&l, 'q');
    printf("%c = %d pts", l.character, calculScoreLetter(&l));



}
