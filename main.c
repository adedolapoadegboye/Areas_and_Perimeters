#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    bool validInput;
    char shapeSelection;

    do {

    // Define name variables and limits
    char username[101];

    // Get basic user info for personalization
    printf("Enter your username [max of 100 characters]: ");
    validInput = scanf("%s", username) == 1 && strlen(username) <= 100;

    if (!validInput){
       printf("\nInvalid username. Please try again.\n");
    }
    else {
        printf("\nHello %s!\nWelcome to the Area and Perimeter Calculator\n", username);    }

    }

    while(!validInput);



    // Get shape type
    do
    {
    int shape;
    char *shapes[] = { "Square", "Rectangle", "Circle", "Triangle" }; 

    printf("\nSelect a shape from the list: \n");

    printf("0. Square\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");

    validInput = scanf("%i", &shape) == 1 && shape >= 0 && shape <= 3;

    if (validInput)
    {
        printf("\nYour selection: %s\n", shapes[shape]);
        shapeSelection = shapes[shape][0];
    } else {
        printf("\nInvalid selection. Please try again.\n");
    }

    } while(!validInput);


    // Get shape dimensions
    do
    {
    printf("%c \n", shapeSelection);
    } 
    while (!validInput);

    
    return 0;
}
