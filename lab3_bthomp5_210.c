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



// main method
int main(void) {
    // printf("Hello world\n");

    // print a menu of choices for the user (refer to graphic)
    // get char from user and store in char variable c
    
    char C = ' ';
    menu(&C);
    // printf("%c\n", C);

    int N;
    N = getOdd();
    // printf("%d\n", N);

    C = '*';
    printPlus(N, C);

}

// 5 different functions

/* 1. Print Menu: prompts user to enter a choice and retrieves that choice
* return value must be void
* a single pass-by-reference char that takes the user entry
*/ 
void menu(char *f) {
    printf("MENU:\n");
    printf("Enter/Change Character: \'C\' or \'c\'\n");
    printf("Enter/Change Number:    \'N\' or \'n\'\n");
    printf("Print Plus (+) Figure:  \'1\'\n");
    printf("Print * Figure:         \'2\'\n");
    printf("Quit Program:           \'Q\' or \'q\'\n");

    char userInput;
    userInput = getChar();
    *f = userInput;

    return;
}

// 2. getChar: prompts user to enter a single character. return value is char
getChar(void) {
    printf("Enter char: ");
    char c;
    scanf(" %c", &c);
    return c;
}

// 3. giveOdd: prompts the user to enter odd number between 3 and 15 (inclusive). If value is
// outside range: prompt again. Value is to be stored in local variable N in main. return int
getOdd(void) {
    int num = 0;
    int foundOdd = 0;
    
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
    int row = 0;
    int col = 0;
    for (row = 0; row < N; row++) {
        // printf("row: %d", row);
        col = 0;
        for (col; col < N; col++) {
            // printf("col: %d", col);
            if (col == row) printf("%c",C);
            else if (col == N-row-1) printf("%c",C);
            else printf(" ");
        }
        printf("\n");
    }
    
    return;
}

void printPlus(int N, char C) {
    int row = 0;
    int col = 0;
    for (row = 0; row < N; row++) {
        // printf("row: %d", row);
        col = 0;
        for (col; col < N; col++) {
            // printf("col: %d", col);
            if (col == N/2) printf("%c",C);
            else if (row == N/2) printf("%c",C);
            else printf(" ");
        }
        printf("\n");
    }
    
    return;
}