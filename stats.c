/*
 * histo.c
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"
#include "stats.h"

// TODO: function definitions for dealing with histogram below

void loadHistogram(int histogram[], char* token, int* vowelCount, int* consonantCount){
    char* temp = token;
    int vCount, cCount = 0;
    //printf("TEST: %s", temp);
    while(*temp != '\0'){
        //Need to convert to lowercase
        // if(*temp <= 'Z' && *temp >= 'A')
        // {
        //     printf("Before: %c", *temp);
        //     *temp += 32;
        //     printf("After: %c", *temp);
        // }
        printf("CHAR: %c\n", *temp);
        if(*temp == 'a' || *temp == 'e' || *temp == 'i' || *temp == 'o' || *temp == 'u'){
            vCount++;
        }
        else{
            cCount++;
        }
        //printf("Char to int: %c --> %d\n", *temp,(int)*temp);
        temp++;
    }
    printf("Vowels: %d  Cons: %d\n", vCount, cCount);


}
int vowelCount();
int consonantCount();
