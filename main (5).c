#include <stdio.h>
#include "labs.h"
#define maxWord (4096)
#define maxString (4096)
int firstLab ();
int secondLab ();
int thirdLab (); 
int fourthLab ();
int fifthLab ();
int sixthLab (); 
int seventhLab ();


int main() {
    int input;
    printf("Enter lab number: \n");
    if (scanf("%d", &input) != 1) {
        printf("Wrong number!\n");
    }

    if (input == 1) {firstLab ();}
    if (input == 2) {secondLab ();}
    if (input == 3) {thirdLab ();}
    if (input == 4) {fourthLab ();}
    if (input == 5) {fifthLab ();}
    if (input == 6) {sixthLab ();}
    else if (input == 7) {seventhLab ();}
    
    else { printf("No such lab");}

    getchar(); getchar();
    return 0;
}