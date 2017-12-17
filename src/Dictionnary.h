#ifndef DICTIONNARY_H_INCLUDED

#define DICTIONNARY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "GridModel.h"

#include "Word.h"
#include "Letter.h"
#include "Interface.h"

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int) 'a')



typedef struct TrieNode TrieNode;

struct TrieNode{
    TrieNode* children[ALPHABET_SIZE];

    bool endOfWord;

};

TrieNode* initNode(void);
void insertNode(TrieNode*, const char*);
bool searchNode(TrieNode*, const char*);

bool checkIfLetterIsPossible(TrieNode*, Word*, Letter*);

TrieNode* possibleWordInGrid();
Word* checkWordInGrid(Word*);







#endif // DICTIONNARY_H_INCLUDED
