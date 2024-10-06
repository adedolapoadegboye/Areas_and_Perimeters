#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to clear input buffer (especially useful after using scanf)
void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    bool validInput;
    char shapeSelection; 
    char restart;
    char username[101];

    // Ask for the username, ensuring valid input
    do {
        printf("Enter your username [max of 100 characters]: ");
        validInput = scanf("%100s", username) == 1 && strlen(username) <= 100;

        if (!validInput) {
            printf("\nInvalid username. Please try again.\n");
            clear_input_buffer();  // Clear input buffer
        } else {
            printf("\nHello %s!\nWelcome to the Area and Perimeter Calculator\n", username);
        }

    } while (!validInput);

    // Main loop to repeat calculations if the user wants to restart
    do {
        // Get shape type from the user
        do {
            int shape;
            char *shapes[] = { "Square", "Rectangle", "Circle", "Triangle" }; 

            printf("\nSelect a shape from the list: \n");
            printf("0. Square\n");
            printf("1. Rectangle\n");
            printf("2. Circle\n");
            printf("3. Triangle\n");

            validInput = scanf("%i", &shape) == 1 && shape >= 0 && shape <= 3;

            if (validInput) {
                printf("\nYour selection: %s\n", shapes[shape]);
                shapeSelection = shapes[shape][0];  // First letter of the shape (S, R, C, T)
            } else {
                printf("\nInvalid selection. Please try again.\n");
                clear_input_buffer();  // Clear input buffer
            }

        } while (!validInput);

        // Perform calculations based on shape selection
        do {
            if (shapeSelection == 'S') {
                double squareLength, squareArea, squarePerimeter;

                printf("\nEnter the length of one side of the square (positive value): \n");
                validInput = scanf("%lf", &squareLength) == 1 && squareLength > 0;

                if (!validInput) {
                    printf("\nInvalid input. Please try again.\n");
                    clear_input_buffer();
                } else {
                    squareArea = squareLength * squareLength;
                    squarePerimeter = 4 * squareLength;
                    printf("\nArea of square: %.2f\nPerimeter of square: %.2f\n", squareArea, squarePerimeter);
                }

            } else if (shapeSelection == 'R') {
                double rectangleLength, rectangleBreadth, rectangleArea, rectanglePerimeter;

                printf("\nEnter the length of the rectangle (positive value): \n");
                validInput = scanf("%lf", &rectangleLength) == 1 && rectangleLength > 0;

                printf("\nEnter the breadth of the rectangle (positive value): \n");
                validInput = validInput && scanf("%lf", &rectangleBreadth) == 1 && rectangleBreadth > 0;

                if (!validInput) {
                    printf("\nInvalid inputs. Please try again.\n");
                    clear_input_buffer();
                } else {
                    rectangleArea = rectangleLength * rectangleBreadth;
                    rectanglePerimeter = 2 * (rectangleLength + rectangleBreadth);
                    printf("\nArea of rectangle: %.2f\nPerimeter of rectangle: %.2f\n", rectangleArea, rectanglePerimeter);
                }

            } else if (shapeSelection == 'C') {
                double circleRadius, circleArea, circleCircumference;

                printf("\nEnter the radius of the circle (positive value): \n");
                validInput = scanf("%lf", &circleRadius) == 1 && circleRadius > 0;

                if (!validInput) {
                    printf("\nInvalid input. Please try again.\n");
                    clear_input_buffer();
                } else {
                    circleArea = 3.14159 * circleRadius * circleRadius;
                    circleCircumference = 2 * 3.14159 * circleRadius;
                    printf("\nArea of the circle: %.2f\nCircumference of the circle: %.2f\n", circleArea, circleCircumference);
                }

            } else if (shapeSelection == 'T') {
                double triangleBase, triangleHeight, triangleSide1, triangleSide2, triangleSide3, triangleArea, trianglePerimeter;

                printf("\nEnter the base of the triangle (positive value): \n");
                validInput = scanf("%lf", &triangleBase) == 1 && triangleBase > 0;

                printf("\nEnter the height of the triangle (positive value): \n");
                validInput = validInput && scanf("%lf", &triangleHeight) == 1 && triangleHeight > 0;

                printf("\nEnter the lengths of the three sides (positive values): \n");
                validInput = validInput && scanf("%lf %lf %lf", &triangleSide1, &triangleSide2, &triangleSide3) == 3 &&
                             triangleSide1 > 0 && triangleSide2 > 0 && triangleSide3 > 0;

                if (!validInput) {
                    printf("\nInvalid inputs. Please try again.\n");
                    clear_input_buffer();
                } else {
                    triangleArea = 0.5 * triangleBase * triangleHeight;
                    trianglePerimeter = triangleSide1 + triangleSide2 + triangleSide3;
                    printf("\nArea of the triangle: %.2f\nPerimeter of the triangle: %.2f\n", triangleArea, trianglePerimeter);
                }
            } else {
                printf("\nInvalid selection. Please try again.\n");
            }

        } while (!validInput);

        // Ask the user if they want to restart the program
        printf("Would you like to run the program again? (y/n): \n");
        scanf(" %c", &restart);
        clear_input_buffer();  // Clear any trailing characters from buffer

    } while (restart == 'y');

    printf("\nThanks for using the Area and Perimeter Calculator!\n");
    return 0;
}
