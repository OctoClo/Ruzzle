#include "Dictionnary.h"

TrieNode* initNode(void)
{
    TrieNode* node = NULL;

    node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node)
    {
        node->endOfWord = false;
        int i;
        for (i = 0 ; i < ALPHABET_SIZE ; i++)
            node->children[i] = NULL;
    }

    return node;
}

void insertNode(TrieNode* root, const char* word)
{
    int length = strlen(word);
    int index;

    TrieNode* currentNode = root;

    int level;
    for (level = 0 ; level < length ; level++)
    {
        index = CHAR_TO_INDEX(word[level]);
        if ( !currentNode->children[index])
            currentNode->children[index] = initNode();
        currentNode = currentNode->children[index];
    }

    currentNode->endOfWord = true;
}

bool searchNode(TrieNode* root, const char* word)
{
    int length = strlen(word);
    int index;

    TrieNode* currentNode = root;

    int level;
    for (level = 0 ; level < length ; level++)
    {
        index = CHAR_TO_INDEX(word[level]);

        if (!currentNode->children[index])
            return false;

        currentNode = currentNode->children[index];
    }

    return (currentNode != NULL && currentNode->endOfWord);
}

bool isValidLetterDictionary(TrieNode* root, Word* word, Letter* letter)
{
    int length = strlen(getWord(word));
    int indexWord;
    int indexLetter = CHAR_TO_INDEX(letter->character);

    TrieNode* currentNode = root;

    int level;
    for (level = 1 ; level <= length ; level++)
    {
        indexWord = CHAR_TO_INDEX(getLetter(word, level)->character);

        if ( !currentNode->children[indexWord])
            return false;

        currentNode = currentNode->children[indexWord];
    }

    return (currentNode != NULL && currentNode->children[indexLetter] != NULL && !letter->selected);
}

void freeDictionnary(TrieNode* root){
    free(root);
}

TrieNode* possibleWordInGrid(TrieNode* root)
{
    Grid* currentGrid = gameManager->interfaceGame->grid;
    TrieNode* rootNew = initNode();
    Word* newWord = initWord();

    int row, column;
    for (column = 0 ; column < 4 ;column++)
    {
        for (row = 0 ; row < 4 ; row++)
        {
            if (currentGrid->grid[row][column] != NULL)
            {
                addLetterInWord(newWord, currentGrid->grid[row][column]);
                checkWordInGrid(root, rootNew, newWord);
                unSelectWord(newWord);
                newWord = initWord();
            }
        }
    }

    return rootNew;
}

void checkWordInGrid(TrieNode* root, TrieNode* rootNew, Word* word)
{
    Letter* lastLetter = getLetter(word, sizeWord(word));
    lastLetter->selected = 1;
    Grid* currentGrid = gameManager->interfaceGame->grid;
    char* wordLisible = getWord(word);

    if (searchNode(root, wordLisible))
    {
        insertNode(rootNew, getWord(word));
    }

    if(lastLetter->row<1 && lastLetter->column<1){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if(lastLetter->row<1 && (lastLetter->column>0 && lastLetter->column<(GRID_SIZE-1))){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if(lastLetter->row<1 && lastLetter->column==(GRID_SIZE-1)){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if((lastLetter->row>0 && lastLetter->row<(GRID_SIZE-1)) && lastLetter->column<1){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if(lastLetter->row==(GRID_SIZE-1) && lastLetter->column<1){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }

    }else if((lastLetter->row>0 && lastLetter->row<(GRID_SIZE-1)) && (lastLetter->column>0 && lastLetter->column<(GRID_SIZE-1))){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if(lastLetter->row==(GRID_SIZE-1) && lastLetter->column==(GRID_SIZE-1)){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if(lastLetter->row==(GRID_SIZE-1) && lastLetter->column>0){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column+1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column+1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
    }else if(lastLetter->row>0 && lastLetter->column==(GRID_SIZE-1)){
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row+1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column-1][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
        if(isValidLetterDictionary(root, word, currentGrid->grid[lastLetter->column][lastLetter->row-1])){
            addLetterInWord(word, currentGrid->grid[lastLetter->column][lastLetter->row-1]);
            checkWordInGrid(root, rootNew, word);
        }
    }

    if(sizeWord(word)>1){
       lastLetter->selected=0;
       lastLetter = getLetter(word, sizeWord(word)-1);
       deleteLastLetter(word);
    }
}
