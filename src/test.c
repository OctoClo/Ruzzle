#include <stdio.h>
#include <stdlib.h>
#include "letter.h"


int main(int argc, char** argv)
{


    printf("OUI\n");
    Letter l;
    initLetter(&l, 'a');
    printf("%d", calculScoreLetter(&l));



}
