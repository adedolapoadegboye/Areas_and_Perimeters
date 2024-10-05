#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {

    bool validInput;

    do {

    // Define name variables and limits
    char username[101];

    // Get basic user info for personalization
    printf("Enter your username [max of 100 characters]: ");
    validInput = scanf("%s", username) == 1 && strlen(username) <= 100;

    if (!validInput){
       printf("Invalid username. Please try again.\n");
    }
    else {
        printf("Hello %s!\nWelcome to the Area and Perimeter Calculator\n", username);    }

    }

    while(!validInput);

    

    // Get shape type
    do
    {
    enum shapeType { square = 0, rectangle = 1, circle = 2, triangle = 3, quit = 4 };
    int shape;
    const char *shapes[] = { "square", "rectangle", "circle", "triangle", "quit" }; 

    printf("Select a shape from the list: \n");

    printf("0. Square\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("4. Quit\n");

    validInput = scanf("%i", &shape) == 1 && shape >= 0 && shape <= 4;

    if (validInput)
    {
        printf("Your selection: %s\n", shapes[shape]);
    } else {
        printf("Invalid selection. Please try again.\n");
    }

    } while(!validInput);

    

    return 0;
}
