#include <stdio.h>

int main() {
    char username[1000];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Hello %s!.\nWelcome to the Area and Perimeter Calculator\n", username);
}
