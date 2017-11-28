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

Letter* initLetter(char);

int scoreLetter(Letter*);



#endif // LETTER_H_INCLUDED
