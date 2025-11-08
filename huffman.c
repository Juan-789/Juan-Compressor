#include "huffman.h"



// now lets build the tree
huffmanNode* huffmanTree(char charsArr[], int freqArr[], int uniqueChars, int totChars) {
    //in essence this only builds the tree, so firstly we need to make all the items into leafs,
    //nodes with no children, atleast for the ones who only have 1 as freq
    char currLevel[uniqueChars];    //max
    int countAtLevel = 0;
    huffmanNode* reverse_eytzeger [] = {};   //huge
    for (int i = 0; i < uniqueChars; i++) {
        if (freqArr[i] == 1) {  //but what if the least isn't 0???? thenm pnens needs to pivot into 2, 3, 4 
            currLevel[countAtLevel] = charsArr[i];    //perhaps i need to start havin eytzinger method,
            countAtLevel += 1;
        }
    }
    // huffmanNode* leafs[countAtLevel];   //expand to a lot
    
    huffmanNode* leafs[20];

    for (int levelo = 0; levelo<countAtLevel; levelo++) {
        // printf("%c", currLevel[levelo]);
        huffmanNode* b = malloc(sizeof *b);
        b->frequency= 1;
        b->data = currLevel[levelo];
        b->left = NULL;
        b->right = NULL;
        leafs[levelo] = b;
    }
    

    //second level

    for (int outer = 0; outer<countAtLevel/2;outer++) {
        for (int level2 = 0; level2<countAtLevel; level2+=2) {
            huffmanNode* inner_second_level = malloc(sizeof *inner_second_level);
            inner_second_level->data = NULL;
            inner_second_level->left = leafs[level2];
            inner_second_level->right = leafs[level2+1];
            inner_second_level->frequency = (inner_second_level->right->frequency) + (inner_second_level->left->frequency);
            leafs[outer+countAtLevel] = inner_second_level;
        }
    }
    
    for (int leftOut = 0; leftOut<uniqueChars; leftOut++) {
        if (freqArr[leftOut] == 2) {
            //add it?
            huffmanNode* forgotten_second_level = malloc(sizeof *forgotten_second_level);
            forgotten_second_level->data = charsArr[leftOut];
            forgotten_second_level->left = NULL;
            forgotten_second_level->right = NULL;
            forgotten_second_level->frequency = 2;
            leafs[(countAtLevel/2)+countAtLevel] = forgotten_second_level;                
        }
    }
    
    // while loop, general solution
    
    for (int levelo1 = 0; levelo1<19; levelo1++) {
        if (levelo1<countAtLevel) { //if freq == 1, leaf, else inner
            // printf("leafs %d \n", leafs[levelo1]->frequency);
            printf("leafs %c \n", leafs[levelo1]->data);

        } else {
            printf("inner %c \n", leafs[levelo1]->data);
            // printf("inner %d \n", leafs[levelo1]->frequency);
        }
    }
    
    //empty
    huffmanNode* a = malloc(sizeof *a);

    a->frequency = 0;
    a->data = (char)"p";
    a->left = NULL;
    a->right = NULL;


    return a;
}