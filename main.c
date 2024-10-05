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


    // Perform square calculations
    do
    {
    
    if (shapeSelection == 'S') {

        float squareLength; 
        float squareArea;
        float squarePerimeter;

        printf("\nEnter the length of one side of the square (remember all sides are equal): \n");

        validInput = scanf("%f", &squareLength) == 1;

        if (!validInput) {
            printf("\nInvalid input. Please try again.\n");
        } else {
            squareArea = squareLength * squareLength;
            squarePerimeter = 4 * squareLength;
            printf("\nArea of square with side length %.2f: %.2f\n\nPerimeter of square with side length %.2f: %.2f\n", squareLength, squareArea, squareLength, squarePerimeter);
        }
    } else {
        printf("\nInvalid selection. Please try again.\n");
    } }
    while (!validInput);

    // Perform rectangle calculations
    do
    {
    
    if (shapeSelection == 'R') {

        float rectangleLength;
        float rectangleBreadth; 
        float rectangleArea;
        float rectanglePerimeter;

        printf("\nEnter the length of the rectangle (the longer side): \n");

        validInput = scanf("%f", &rectangleLength) == 1;

        printf("\nEnter the breadth of the rectangle (the shorter side): \n");

        validInput = scanf("%f", &rectangleBreadth) == 1;

        if (!validInput) {
            printf("\nInvalid inputs. Please check your inputs andtry again.\n");
        } else {
            rectangleArea = rectangleLength * rectangleBreadth;
            rectanglePerimeter = 2 * (rectangleLength + rectangleBreadth);
            printf("\nArea of rectangle with length %.2f and breadth %.2f: %.2f\n\nPerimeter of rectangle with length %.2f and breadth %.2f: %.2f\n", rectangleLength, rectangleBreadth, rectangleArea, rectangleLength, rectangleBreadth, rectanglePerimeter);
        }
    } else {
        printf("\nInvalid selection. Please try again.\n");
    } }
    while (!validInput);
    
    return 0;
}
