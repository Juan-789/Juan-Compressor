#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct huffmanNode {
    int frequency;
    char data;
    struct huffmanNode *left;
    struct huffmanNode *right;
} huffmanNode;

huffmanNode* huffmanTree(char charArr[], int freqArr[], int uniqueChar, int totChar);

#endif