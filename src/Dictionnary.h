#ifndef DICTIONNARY_H_INCLUDED
#define DICTIONNARY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Utils.h"
#include "GridModel.h"
#include "Word.h"
#include "Letter.h"
#include "Interface.h"

typedef struct _trieNode TrieNode;

typedef struct _trieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool endOfWord;
} TrieNode;

TrieNode* initNode(void);
void insertNode(TrieNode*, const char*);
bool searchNode(TrieNode*, const char*);

bool checkIfLetterIsPossible(TrieNode*, Word*, Letter*);

TrieNode* possibleWordInGrid(TrieNode*);
void checkWordInGrid(TrieNode*, TrieNode*, Word*);

#endif // DICTIONNARY_H_INCLUDED
