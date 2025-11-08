//Juan-compressor, makes a txt file compress with the .juan extension
#include <stdio.h>
#include "huffman.h"


int main(int argc, char *argv[]) {  //gcc main.c wtv wtv, and the file to compress
//should i make a dictionary in c? sounds like fun but lets try to do the incremental way

    //lets read the txt
    if (argc == 0) {
        printf("No files passed");
        printf("put the filename as an argument");
        return 0;
    } 

    char charArray[129];    //there's 128 chars in ascii   
    int freqArray[129] = {0};    //the frequency of these characters  
    int uniqueChars = 0;
    int* ptrUniqueChars = &uniqueChars;
    // *uniqueChars = 0;
    int charsTotal = 0;  
    char ch;
    FILE *fptr;

    fptr = fopen(argv[1], "r");  //should handle paths and such
    if (fptr == NULL) {
        printf("Error: Could not open file \n");
        return 1;
    }
    while((ch = fgetc(fptr)) != EOF) { //build tree, but firsdt we need the frequencies,
        // maybe we can make this inneficient
        // printf("%c", ch);
        if (charsTotal == 0 ){
            charArray[0] = ch;
            freqArray[0] = 1;

            uniqueChars++;
            charsTotal++;
        } else {
            for (int charSeen = 0; charSeen<uniqueChars; charSeen++){
                if (charArray[charSeen] == ch) {    //case where it finds a repeated char
                    freqArray[charSeen] = freqArray[charSeen] + 1;
                    charsTotal++;
                    break;
                } else if (charSeen == (uniqueChars)-1 ){
                    charArray[*ptrUniqueChars] = (char)ch;
                    freqArray[*ptrUniqueChars] = 1;
                    charsTotal++;
                    (*ptrUniqueChars)++;
                    break;
                }
            }
        }
    }
    for (int i=0; i<uniqueChars;i++){
        printf("character %c and number %d\n", charArray[i], freqArray[i]);
    }
    fclose(fptr);
    huffmanTree(charArray, freqArray, uniqueChars, charsTotal);

    return 0;
}