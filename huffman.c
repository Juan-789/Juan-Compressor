#include <huffman.h>


typedef struct huffmanNode{
    int value;
    huffmanNode *left;
    huffmanNode *right;

} huffmanNode;