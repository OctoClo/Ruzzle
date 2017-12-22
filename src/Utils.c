#include "Utils.h"

int randInter(int a, int b){
    return rand()%(a-b)+a;
}

int randModifier(void){
    int sumOfWeight=0;
    int num_choice=5;
    int choice_weight[num_choice];
    choice_weight[0]=10;//DOUBLE_LETTER
    choice_weight[1]=5;//TRIPLE_LETTER
    choice_weight[2]=2;//DOUBLE_WORD
    choice_weight[3]=1;//TRIPLE_WORD
    choice_weight[4]=82;//NONE

    int i;
    for(i=0;i<num_choice;i++){
        sumOfWeight += choice_weight[i];
    }
    int rnd = randInter(0, sumOfWeight);
    for(i=0; i<num_choice; i++){
        if(rnd<choice_weight[i]){
            return i;
        }
        rnd -= choice_weight[i];
    }
}

char randLetter(void){
    int sumOfWeight=0;
    int num_choice=ALPHABET_SIZE;
    int choice_weight[num_choice];
    choice_weight[0]=10;//A
    choice_weight[1]=8;//B
    choice_weight[2]=8;//C
    choice_weight[3]=9;//D
    choice_weight[4]=10;//E
    choice_weight[5]=7;//F
    choice_weight[6]=9;//G
    choice_weight[7]=7;//H
    choice_weight[8]=10;//I
    choice_weight[9]=3;//J
    choice_weight[10]=1;//K
    choice_weight[11]=10;//L
    choice_weight[12]=9;//M
    choice_weight[13]=10;//N
    choice_weight[14]=10;//O
    choice_weight[15]=8;//P
    choice_weight[16]=3;//Q
    choice_weight[17]=10;//R
    choice_weight[18]=10;//S
    choice_weight[19]=10;//T
    choice_weight[20]=10;//U
    choice_weight[21]=7;//V
    choice_weight[22]=1;//W
    choice_weight[23]=1;//X
    choice_weight[24]=1;//Y
    choice_weight[25]=1;//Z
    int i;
    for(i=0;i<num_choice;i++){
        sumOfWeight += choice_weight[i];
    }
    int rnd = randInter(0, sumOfWeight);
    for(i=0; i<num_choice; i++){
        if(rnd<choice_weight[i]){
            i = i + (int)'a';
            return (char)i;
        }
        rnd -= choice_weight[i];
    }
}
