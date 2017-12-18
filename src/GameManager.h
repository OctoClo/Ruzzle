#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "string.h"

#include "Utils.h"
#include "Enums.h"
#include "Dictionnary.h"
#include "Word.h"

typedef struct _trieNode TrieNode;
typedef struct _interfaceGame InterfaceGame;
typedef struct _word Word;

typedef struct _gameManager
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    Step step;

    TrieNode* dictionary;

    InterfaceGame* interfaceGame;
    Word** words;
    int wordsCount;
} GameManager;

GameManager* gameManager;

void initSDL(void);
void readRootDictionary(void);

void initGameManager(void);
void gameLoop(void);

void addWord(Word*);
int isWordAlreadyFound(Word*);

void handleEvents(SDL_Event*);
void update(void);
void render(void);

void freeGameManager(void);
void cleanExit(void);

void fatalError(const char*, const char*);

#endif // GAME_MANAGER_H
