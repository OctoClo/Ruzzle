#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED
typedef enum Modifier Modifier;
typedef struct Letter Letter;

enum Modifier{
    DOUBLE_LETTER, TRIPLE_LETTER, DOUBLE_WORD, TRIPLE_WORD, NONE
};

struct Letter{
    int weight;
    Modifier modif;
    int row, column;
    char character;

};

void initLetter(Letter* letter, char c);

int calculScoreLetter(Letter* l);



#endif // LETTER_H_INCLUDED
