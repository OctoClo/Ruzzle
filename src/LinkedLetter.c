#include "LinkedLetter.h"


Liste* listeInitialisation()
{
    Liste* liste = malloc(sizeof(*liste));
    LinkedLetter* linkedLetter = malloc(sizeof(*linkedLetter));

    if (liste == NULL || linkedLetter == NULL)
        exit(EXIT_FAILURE);

    linkedLetter->lett = NULL;
    linkedLetter->next = NULL;
    liste->first = linkedLetter;

    return liste;
}

void listeInsertionBeginning(Liste* liste, Letter* l)
{
    LinkedLetter* newLink = malloc(sizeof(*newLink));

    if (liste == NULL || newLink == NULL)
        exit(EXIT_FAILURE);

    newLink->lett = l;

    /*if (liste->first->lett->character == ' ')*/
    if (liste->first->lett == NULL)
        newLink->next = NULL;
    else
        newLink->next = liste->first;

    liste->first = newLink;
}

void listeInsertionEnd(Liste* liste, Letter* l)
{
    LinkedLetter* newLink = malloc(sizeof(*newLink));

    if (liste == NULL || newLink == NULL)
        exit(EXIT_FAILURE);

    newLink->lett = l;
    newLink->next = NULL;

    LinkedLetter* current = liste->first;

    /*if (liste->first->lett->character == ' ')
    {
        liste->first = newLink;
        return;
    }*/

    if (liste->first->lett == NULL)
    {
        liste->first = newLink;
        return;
    }

    while (current->next != NULL)
        current = current->next;

    current->next = newLink;

    return;
}

void deleteFirstOfListe(Liste* liste)
{
    if (liste == NULL)
        exit(EXIT_FAILURE);

    if (liste->first != NULL)
    {
        LinkedLetter* toDelete = liste->first;
        liste->first = liste->first->next;
        free(toDelete);
    }
}

void displayListe(Liste* liste)
{
    if (liste == NULL)
        exit(EXIT_FAILURE);

    LinkedLetter* current = liste->first;

    // Added empty word case (necessary ?)
    if (current != NULL && current->lett == NULL)
        SDL_Log("Empty word !");
    else
    {
        while (current != NULL)
        {
            // Corrected character display
            char character[2];
            character[0] = current->lett->character;
            character[1] = '\0';
            SDL_Log(character);
            current = current->next;
        }
    }
}

int sizeListe(Liste* liste)
{
    if (liste == NULL)
        exit(EXIT_FAILURE);

    int count = 0;
    LinkedLetter* current = liste->first;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

Letter* getLetterAtRank(Liste* liste, int rank)
{
    if (liste == NULL)
        exit(EXIT_FAILURE);

    LinkedLetter* current = liste->first;

    int i;
    for (i = 1 ; i < rank ; i++)
        current = current->next;

    return current->lett;
}
