#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    // Define variables and limits
    char username[1000];
    bool validInput =  false;

    do{

    // Get basic user info for personalization
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Hello %s!.\nWelcome to the Area and Perimeter Calculator\n", username);
    validInput = true;

    }
    
    while(validInput);

    return 0;
}
