#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
#include "word.h"
#include "LinkedLetter.h"
#include "TrieNode.h"

#define TAILLE_MAX 100


int main(int argc, char** argv)
{


    FILE* dico = NULL;
    char word[TAILLE_MAX];
    int length;

    //Ouverture du fichier dico
    dico = fopen("src/file/dico.txt", "r");

    //D�claration de l'arbre pr�fix�
    TrieNode* root = initNode();


    //Traitement du fichier dico
    if(dico != NULL){


        //Enregistrement des mots du dictionnaire dans l'arbre pr�fix�e
        while(fgets(word, TAILLE_MAX, dico) != NULL){
            strtok(word, "\n");
            insertNode(root, word);
        }



        fclose(dico);
    }


    //V�rification de pr�sence du mot (Test)
    if(searchNode(root, "jambon")){
        printf("OUIIII");

    }else{
        printf("NOOON");
    }










    return 0;


}
