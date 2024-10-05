#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    bool validInput;
    char shapeSelection; 
    char restart;
    char username[101];


    do {

        // Get basic user info for personalization
        printf("Enter your username [max of 100 characters]: ");
        validInput = scanf("%s", username) == 1 && strlen(username) <= 100;

        if (!validInput) {
            printf("\nInvalid username. Please try again.\n");
        } else {
            printf("\nHello %s!\nWelcome to the Area and Perimeter Calculator\n", username);
        }

    } while (!validInput);

    do {
        // Get shape type
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
                shapeSelection = shapes[shape][0];
            } else {
                printf("\nInvalid selection. Please try again.\n");
            }

        } while (!validInput);

        // Perform calculations
        do {
            if (shapeSelection == 'S') {
                double squareLength; 
                double squareArea;
                double squarePerimeter;

                printf("\nEnter the length of one side of the square (remember all sides are equal): \n");
                validInput = scanf("%lf", &squareLength) == 1;

                if (!validInput) {
                    printf("\nInvalid input. Please try again.\n");
                } else {
                    squareArea = squareLength * squareLength;
                    squarePerimeter = 4 * squareLength;
                    printf("\nArea of square with side length %.2f: %.2f\n\nPerimeter of square with side length %.2f: %.2f\n", 
                           squareLength, squareArea, squareLength, squarePerimeter);
                }
            } else if (shapeSelection == 'R') {
                double rectangleLength;
                double rectangleBreadth; 
                double rectangleArea;
                double rectanglePerimeter;

                printf("\nEnter the length of the rectangle (the longer side): \n");
                validInput = scanf("%lf", &rectangleLength) == 1;

                printf("\nEnter the breadth of the rectangle (the shorter side): \n");
                validInput = scanf("%lf", &rectangleBreadth) == 1;

                if (!validInput) {
                    printf("\nInvalid inputs. Please check your inputs and try again.\n");
                } else {
                    rectangleArea = rectangleLength * rectangleBreadth;
                    rectanglePerimeter = 2 * (rectangleLength + rectangleBreadth);
                    printf("\nArea of rectangle with length %.2f and breadth %.2f: %.2f\n\nPerimeter of rectangle with length %.2f and breadth %.2f: %.2f\n", 
                           rectangleLength, rectangleBreadth, rectangleArea, rectangleLength, rectangleBreadth, rectanglePerimeter);
                }
            } else if (shapeSelection == 'C') {
                double circleRadius;
                double circleArea;
                double circleCircumference;

                printf("\nEnter the radius of the circle: \n");
                validInput = scanf("%lf", &circleRadius) == 1;

                if (!validInput || circleRadius <= 0) {
                    printf("\nInvalid inputs. Please check your inputs and try again.\n");
                    validInput = 0;  // Make sure to stay in the loop if input is invalid
                } else {
                    circleArea = 3.14159 * circleRadius * circleRadius; // Pi * r^2
                    circleCircumference = 2 * 3.14159 * circleRadius;   // 2 * Pi * r
                    printf("\nArea of the circle with radius %.2f: %.2f\n\nCircumference of the circle with radius %.2f: %.2f\n", 
                           circleRadius, circleArea, circleRadius, circleCircumference);
                }
            } else if (shapeSelection == 'T') {
                double triangleBase;
                double triangleHeight;
                double triangleSide1, triangleSide2, triangleSide3;
                double triangleArea;
                double trianglePerimeter;

                printf("\nEnter the base of the triangle: \n");
                validInput = scanf("%lf", &triangleBase) == 1;

                printf("\nEnter the height of the triangle: \n");
                validInput = validInput && (scanf("%lf", &triangleHeight) == 1);

                printf("\nEnter the lengths of the three sides of the triangle (in any order, separated by pressing the enter key): \n");
                validInput = validInput && (scanf("%lf %lf %lf", &triangleSide1, &triangleSide2, &triangleSide3) == 3);

                if (!validInput || triangleBase <= 0 || triangleHeight <= 0 || triangleSide1 <= 0 || triangleSide2 <= 0 || triangleSide3 <= 0) {
                    printf("\nInvalid inputs. Please check your inputs and try again.\n");
                    validInput = 0;  // Make sure to stay in the loop if input is invalid
                } else {
                    triangleArea = 0.5 * triangleBase * triangleHeight; // (1/2) * base * height
                    trianglePerimeter = triangleSide1 + triangleSide2 + triangleSide3; // Sum of all sides
                    printf("\nArea of the triangle with base %.2f and height %.2f: %.2f\n\nPerimeter of the triangle with sides %.2f, %.2f, and %.2f: %.2f\n", 
                           triangleBase, triangleHeight, triangleArea, triangleSide1, triangleSide2, triangleSide3, trianglePerimeter);
                }
            } else {
                printf("\nInvalid selection. Please try again.\n");
            }
        } while (!validInput);

        printf("Would you like to run the program again? (y/n): \n");
        scanf(" %c", &restart); 

    } while (restart == 'y');
    
    return 0;
}
