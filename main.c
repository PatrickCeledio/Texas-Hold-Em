// Texas Hold 'Em 
// Patrick Celedio
// gcc .\main.c -o game.exe and then .\game.exe    

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Card structure
struct Card {
    // A = 1; J = 11; Q = 12; K = 13;
    // Ace card will be programmed to also represent 11, so its value is either 1 or 11
    int id;
    int number;
    char suit;
    char alive;
};

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

int menuChoice(){
    int choice = 0;
    scanf("%d", &choice);

    return choice;
}

int viewAvailableTables(){
    printf("Viewing Available Tables\n");
    return 0;
}

void printCard(struct Card card){
    char *rank;

    // Switch case handles face cards and ace
    // Default to handle numerical cards, turns int to string
    switch(card.number){
        case 1: 
            rank = "A";
            break;
        case 11:
            rank = "J";
            break;       
        case 12:
            rank = "Q";
            break;        
        case 13:
            rank = "K";
            break;    
        default: {
            static char buffer[3];
            snprintf(buffer, sizeof(buffer), "%d", card.number);
            rank = buffer;
        }
    }
    
    // This prints the card value and suit e.g. AH, 2P, 3C, 4D etc
    printf("%s%c ", rank, card.suit);
}

void printDeck(){
    
    for (int i = 0; i<52; i++){
        printCard(deck[i]);

        if ((i + 1) % 13 == 0);
            printf("\n");
    }
    printf("\n");
}

void shuffleDeck(){
    // Loop backwards and moves a random card into position i until 1 card left
    // Once completed, that deck becomes the shuffled deck
    for (int i = 51; i>0; i--){
        int j = rand() % (i + 1);

        struct Card shuffled = deck[i];
        deck[i] = deck[j];
        deck[j] = shuffled;
    }
}

int viewCardDeck(){
    printf("Viewing Deck: Current Order\n");
    printDeck();

    // Prompt to shuffle deck
    while(1){
        printf("Shuffle the deck? Y or N\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y'){
            shuffleDeck();
            printf("Shuffle completed.\n");
            printDeck();
        } else if (choice == 'n' || choice == 'N'){
            printf("Returning to menu.\n");
            break;
        } else {
            printf("Invalid input. Please enter Y or N.\n");
        }
    }// end While

    return 0;
}
void viewCredits(){
    printf("*****************************************\n");
    printf("Texas Hold 'Em in C Programming Language\n");
    printf("Attempted by Patrick Celedio\n");
    printf("*****************************************\n");
    
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
    // Init psuedo RNG with unique starting point everytime main runs
    srand((unsigned) time(NULL));
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
            printf("Goodbye!\n");
            exitGame();
            break;    
        default:
            printf("Player chose: %d\n", menuChoice);

        }// End switch
    }// End Loop


    return 0;
}