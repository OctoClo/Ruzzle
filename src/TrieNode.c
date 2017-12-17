#include "TrieNode.h"

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
