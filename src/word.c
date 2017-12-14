#include "Word.h"

Word* initWord(void)
{
    Word* w = malloc(sizeof(Word));
    w->word = listeInitialisation();
    return w;
}

void addLetterInWord(Word* w, struct Letter* l)
{
    //listeInsertionEnd(w->word, l->character);
    listeInsertionEnd(w->word, l);
}

void displayWord(Word* w)
{
    displayListe(w->word);
}

char* getWord(Word* w)
{
    int word_size = sizeWord(w);
    char* word = malloc(sizeof(*word)*word_size);
    int i;
    for(i = 0 ; i < word_size ; i++)
        word[i] = getLetter(w, i + 1)->character;
    word[i] = '\0';

    return word;
}

int scoreWord(Word* w)
{
    int score = 0;
    int doubleWord = 0;
    int tripleWord = 0;
    int word_size = sizeWord(w);
    int i;
    for(i = 1 ; i <= word_size ; i++){
        Letter* currentLetter = getLetter(w, i);
        switch (currentLetter->modif)
        {
        case DOUBLE_LETTER:
            break;
        case TRIPLE_LETTER:
            break;
        case DOUBLE_WORD:
            doubleWord++;
            break;
        case TRIPLE_WORD:
            tripleWord++;
            break;
        case NONE:
            break;
        }
        score += scoreLetter(currentLetter);
    }
    if (doubleWord > 0)
        score = score * (doubleWord * 2);
    if (tripleWord > 0)
        score = score * (tripleWord * 3);

    return score;
}

int sizeWord(Word* w)
{
    int sizeWord = sizeListe(w->word);
    return sizeWord;
}

Letter* getLetter(Word* w,int rank)
{
    if (rank <= sizeWord(w) && rank > 0)
        return getLetterAtRank(w->word, rank);
    else
    {
        printf("Erreur : le rang doit exister dans le mot");
        exit(EXIT_FAILURE);
    }
}
