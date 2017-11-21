#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED

typedef enum Modifier{
    DOUBLE_LETTER, TRIPLE_LETTER, DOUBLE_WORD, TRIPLE_WORD, NONE
}Modifier;

typedef struct Letter{
    int weight;
    Modifier modif;
    int row, column;
    char character;

}Letter;

void initLetter(Letter* letter, char c);

int calculScoreLetter(Letter* l);



#endif // LETTER_H_INCLUDED
