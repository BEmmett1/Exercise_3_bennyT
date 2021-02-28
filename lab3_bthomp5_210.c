/* Benny Thompson G01282798
 * CS 262, Lab Section 210
 * Lab 3
 */

#include<stdio.h>

char *f;
void menu(char *f);
void printX(int N, char C);
void printPlus(int N, char C);
int getChar(void);
int getOdd(void);



/* main method */
int main(void) {
    char input;
    int N;
    char C;
    int run;
    
    input = ' ';
    C = ' ';
    run = 1;

    while (run) {
        menu(&input);
        switch (input) {
            case 'C':
            case 'c':
                C = getChar();
                break;
            case 'N': 
            case 'n':
                N = getOdd();
                break;
            case '1':
                printPlus(N, C);
                break;
            case '2':
                printX(N, C);
                break;
            case 'Q':
            case 'q':
                run = 0;
        }
    }
    return 0;
}

/* 5 different functions

 1. Print Menu: prompts user to enter a choice and retrieves that choice
* return value must be void
* a single pass-by-reference char that takes the user entry
*/ 
void menu(char *f) {
    char userInput;
    printf("\nMENU:\n");
    printf("Enter/Change Character: \'C\' or \'c\'\n");
    printf("Enter/Change Number:    \'N\' or \'n\'\n");
    printf("Print Plus (+) Figure:  \'1\'\n");
    printf("Print * Figure:         \'2\'\n");
    printf("Quit Program:           \'Q\' or \'q\'\n");
    
    userInput = getChar();
    *f = userInput;

    return;
}

/* 2. getChar: prompts user to enter a single character. return value is char */
int getChar(void) {
    char c;
    printf("Enter char: ");
    scanf(" %c", &c);
    return c;
}

/* 3. giveOdd: prompts the user to enter odd number between 3 and 15 (inclusive). If value is
 outside range: prompt again. Value is to be stored in local variable N in main. return int */
int getOdd(void) {
    int num ;
    int foundOdd;
    num = 0;
    foundOdd = 0;
    
    while (!foundOdd) {
        printf("Please enter an odd number between 3 and 15 (inclusive):\n");
        scanf("%d", &num);
        if ((num >= 3 && num <= 15) && num % 2 != 0) {
            foundOdd = 1;
        }
    }
    return num;
}

void printX(int N, char C) {
    int row;
    int col;

    if (N < 3) {
        printf("\nPlease initialize N\n\n");
        return;
    }
    printf("\n");

    row = 0;
    col = 0;
    for (; row < N; row++) {
        col = 0;
        for (; col < N; col++) {
            if (col == row) printf("%c",C);
            else if (col == N-row-1) printf("%c",C);
            else printf(" ");
        }
        printf("\n");
    }
    
    return;
}

void printPlus(int N, char C) {
    int row;
    int col;

    if (N < 3) {
        printf("\nPlease initialize N\n\n");
        return;
    }
    printf("\n");

    row = 0;
    col = 0;

    for (row = 0; row < N; row++) {
        col = 0;
        for (; col < N; col++) {
            if (col == N/2) printf("%c",C);
            else if (row == N/2) printf("%c",C);
            else printf(" ");
        }
        printf("\n");
    }
    
    return;
}