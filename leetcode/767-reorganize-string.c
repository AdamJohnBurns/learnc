
/*

Inputs
S = string, 1-500 chars

Expected results
"aab" => "aba"
"aaab" => ""

Solutions
? = randomly juggle around and hope for the best
n^2 = loop through entire string twice
n+n = loop through once to generate map of how many, then loop through map to evenly distribute

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_map {
    char letter;
    int num;
    struct t_map *next;
};

struct t_map *mapHead;
int numUnique = 0;
int totalLetters = 0;

void addChar (c) {
    struct t_map *mapCurrent = mapHead;
    struct t_map *last = NULL;
    
    // if the list is empty, add the first one
    if (mapCurrent == NULL) {
        // create the head of a linked list containing all unique chars
        mapHead = (struct t_map *) malloc( sizeof(struct t_map) );
        mapHead->letter = c;
        mapHead->num = 1;
        mapHead->next = NULL;
        numUnique++;
        totalLetters++;
        printf("Starting new list, added new letter '%c'\n", c);
        return;
    }

    // otherwise, search the remaining nodes for it
    while(mapCurrent != NULL) {
        if (mapCurrent->letter == c) {
            mapCurrent->num++;
            totalLetters++;
            printf("Found existing letter '%c', increased count to %d\n", c, mapCurrent->num);
            break;
        }
        
        last = mapCurrent;
        mapCurrent = mapCurrent->next; 
    }
    
    // if the pointer is null, we've reached the end of the list without
    // finding the value
    if (mapCurrent == NULL && last != NULL) {
        struct t_map *newChar = (struct t_map*) malloc( sizeof(struct t_map) );
        newChar->letter = c;
        newChar->num = 1;
        newChar->next = NULL;
            
        last->next = newChar;
        
        numUnique++;
        totalLetters++;
        printf("Added new letter '%c'\n", c);
    }
}

char * reorganizeString(char * S) {
    // add each character to the list
    for (int i = 0; i < strlen(S); i++) {
        addChar(S[i]);
    }

    // knowing how many unique letters and total letters there are, we should be able to 
    // figure out if there's a possible answer
    printf("numUnique = %d, totalLetters = %d\n", numUnique, totalLetters);

    // try and output letters, spreading out
    
    return "";
}

int main(int argc, char **argv) {
    reorganizeString("aab");
}













