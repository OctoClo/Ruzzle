#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
#include "word.h"
#include "LinkedLetter.h"
#include "TrieNode.h"


int main(int argc, char** argv)
{


    TrieNode* root = initNode();

    insertNode(root, "patate");
    insertNode(root, "oui");

    if(searchNode(root, "test")){
        printf("'test' est present dans root !");
    }else{
        printf("'test' n'est pas present dans root !");
    }








}
