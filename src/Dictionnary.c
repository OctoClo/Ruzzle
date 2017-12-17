#include "Dictionnary.h"

TrieNode* initNode(void){
    TrieNode* node = NULL;

    node = (TrieNode*)malloc(sizeof(TrieNode));
    if(node){
        node->endOfWord = false;
        for(int i = 0; i<ALPHABET_SIZE; i++){
            node->children[i] = NULL;
        }
    }

    return node;
}

void insertNode(TrieNode* root, const char* word){
    int length = strlen(word);
    int index;

    TrieNode* currentNode = root;

    for(int level = 0; level<length; level++){
        index = CHAR_TO_INDEX(word[level]);
        if(!currentNode->children[index]){
            currentNode->children[index] = initNode();
        }
        currentNode = currentNode->children[index];
    }

    currentNode->endOfWord = true;

}

bool searchNode(TrieNode* root, const char* word){
    int length = strlen(word);
    int index;

    TrieNode* currentNode = root;

    for(int level = 0; level<length; level++){

        index = CHAR_TO_INDEX(word[level]);

        if(!currentNode->children[index]){
            return false;
        }
        currentNode = currentNode->children[index];
    }

    return (currentNode != NULL && currentNode->endOfWord);

}



bool checkIfLetterIsPossible(TrieNode* root, Word* word, Letter* letter){

    int length = strlen(getWord(word));

    int indexWord;

    int indexLetter = CHAR_TO_INDEX(letter->character);



    TrieNode* currentNode = root;



    for(int level = 1; level<=length; level++){



        indexWord = CHAR_TO_INDEX(getLetter(word, level)->character);



        if(!currentNode->children[indexWord]){

            return false;

        }



        currentNode = currentNode->children[indexWord];

    }



    return (currentNode != NULL && currentNode->children[indexLetter] != NULL);

}

TrieNode* possibleWordInGrid(){
    Grid* currentGrid = gameManager->interfaceR->grid;
    TrieNode* root = initNode();
    int row, column;
    for(row=0; row<4;row++){
        for(column=0;column<4; column++){
            if(currentGrid->grid[row][column] != NULL){

            }

        }
    }
}


Word* checkWordInGrid(Word* word){
    Letter* lastLetter = getLetter(word, sizeWord(word));
    switch()

}
