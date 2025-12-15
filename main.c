// Texas Hold 'Em 
// Patrick Celedio
// gcc .\main.c -o game.exe and then .\game.exe    

#include <stdio.h>
#include <stdlib.h>

// Card structure
struct Card {
    // A = 1; J = 11; Q = 12; K = 13;
    // Ace card will be programmed to also represent 11, so its value is either 1 or 11
    int id;
    int number;
    char suit;
    char alive;
};

int menuChoice(){
    int choice = 0;
    scanf("%d", &choice);

    return choice;
}

int viewAvailableTables(){
    printf("Viewing Available Tables");
    return 0;
}

int viewCardDeck(){
    printf("Viewing Deck");
    int deck = [52];
    return 0;
}
void viewCredits(){
    printf("Texas Hold 'Em in C Programming Language\n");
    printf("Attempted by Patrick Celedio\n");
}
void exitGame(){
    printf("Player chose to exit game.\n");
    exit(0);
}

int menu(){
    printf("=====================================\n");
    printf("= Texas Hold 'Em by Patrick Celedio =\n");
    printf("= Please enter a number to navigate =\n");
    printf("=====================================\n\n");

    int choice = -1; 

    printf("1) Join a table\n");
    printf("2) View card deck \n");
    printf("3) Credits\n");
    printf("4) Exit\n");
    choice = menuChoice();

    return choice;
}

int main(int arg, char* argv[]){
    
    struct Card deck[52] = {
        // ID, number, suit, alive
        {1,1,'H','Y'},
        {2,2,'H','Y'},
        {3,3,'H','Y'},
        {4,4,'H','Y'},
        {5,5,'H','Y'},
        {6,6,'H','Y'},
        {7,7,'H','Y'},
        {8,8,'H','Y'},
        {9,9,'H','Y'},
        {10,10,'H','Y'},
        {11,11,'H','Y'},
        {12,12,'H','Y'},
        {13,13,'H','Y'},
        {14,1,'D','Y'},
        {15,2,'D','Y'},
        {16,3,'D','Y'},
        {17,4,'D','Y'},
        {18,5,'D','Y'},
        {19,6,'D','Y'},
        {20,7,'D','Y'},
        {21,8,'D','Y'},
        {22,9,'D','Y'},
        {23,10,'D','Y'},
        {24,11,'D','Y'},
        {25,12,'D','Y'},
        {26,13,'D','Y'},
        {27,1,'C','Y'},
        {28,2,'C','Y'},
        {29,3,'C','Y'},
        {30,4,'C','Y'},
        {31,5,'C','Y'},
        {32,6,'C','Y'},
        {33,7,'C','Y'},
        {34,8,'C','Y'},
        {35,9,'C','Y'},
        {36,10,'C','Y'},
        {37,11,'C','Y'},
        {38,12,'C','Y'},
        {39,13,'C','Y'},
        {40,1,'S','Y'},
        {41,2,'S','Y'},
        {42,3,'S','Y'},
        {43,4,'S','Y'},
        {44,5,'S','Y'},
        {45,6,'S','Y'},
        {46,7,'S','Y'},
        {47,8,'S','Y'},
        {48,9,'S','Y'},
        {49,10,'S','Y'},
        {50,11,'S','Y'},
        {51,12,'S','Y'},
        {52,13,'S','Y'},
    };

    int menuLoop = -1;
    int menuChoice = 0;
    while(menuLoop){
        menuChoice = menu();

        switch(menuChoice){
        case 1:
            printf("Player chose: %d\n", menuChoice);
            viewAvailableTables();
            break;
        case 2:
            printf("Player chose: %d\n", menuChoice);
            viewCardDeck();
            break;
        case 3:
            printf("Player chose: %d\n", menuChoice);
            viewCredits();
            break;
        case 4:
            printf("Player chose: %d\n", menuChoice);
            exitGame();
            break;    
        default:
            printf("Player chose: %d\n", menuChoice);

        }// End switch
    }// End Loop


    return 0;
}