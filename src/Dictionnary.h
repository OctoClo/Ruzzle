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
#include "InterfaceGame.h"

typedef struct _trieNode
{
    struct _trieNode* children[ALPHABET_SIZE];
    bool endOfWord;
} TrieNode;

TrieNode* rootDictionary;

TrieNode* initNode(void);
void insertNode(TrieNode*, const char*);
bool searchNode(TrieNode*, const char*);

bool isValidLetterDictionary(TrieNode*, Word*, Letter*);

TrieNode* possibleWordInGrid(TrieNode*);
void checkWordInGrid(TrieNode*, TrieNode*, Word*);
void freeDictionnary(TrieNode*);

#endif // DICTIONNARY_H_INCLUDED
