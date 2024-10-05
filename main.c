#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    // Define variables and limits
    char username[10];
    bool validInput;

    do {

    // Get basic user info for personalization
    printf("Enter your username: ");
    validInput = scanf("%s", username) == 1;

    if (!validInput){
       printf("Invalid username. Please try again.\n");
    }
    else {
        printf("Hello %s!.\nWelcome to the Area and Perimeter Calculator\n", username);    }

    }

    while(!validInput);

    return 0;
}
