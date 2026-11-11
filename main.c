#include <stdio.h>
#include <math.h>

static void clearInputBuffer(void) {
    int character;

    while ((character = getchar()) != '\n' && character != EOF) {
        /* Discard invalid input. */
    }
}

static void showMenu(void) {
    printf("\n========== SMART CALCULATOR ==========\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Power (x^y)\n");
    printf("7. Square Root\n");
    printf("8. Percentage\n");
    printf("9. Exit\n");
    printf("======================================\n");
}

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to Smart Calculator!\n");

    while (1) {
        showMenu();

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (choice == 9) {
            printf("Thank you for using Smart Calculator!\n");
            break;
        }

        if (choice < 1 || choice > 9) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        if (choice == 7) {
            printf("Enter a number: ");
            if (scanf("%lf", &num1) != 1) {
                printf("Invalid input!\n");
                clearInputBuffer();
                continue;
            }

            if (num1 < 0) {
                printf("Error: Negative number has no real square root.\n");
            } else {
                result = sqrt(num1);
                printf("Square Root = %.2lf\n", result);
            }
            continue;
        }

        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input!\n");
            clearInputBuffer();
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input!\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result = %.2lf\n", result);
                break;

            case 2:
                result = num1 - num2;
                printf("Result = %.2lf\n", result);
                break;

            case 3:
                result = num1 * num2;
                printf("Result = %.2lf\n", result);
                break;

            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result = %.2lf\n", result);
                }
                break;

            case 5:
                if (num2 == 0 || num1 != trunc(num1) || num2 != trunc(num2)) {
                    printf("Error: Modulus requires non-zero integers.\n");
                } else {
                    result = fmod(num1, num2);
                    printf("Result = %.0lf\n", result);
                }
                break;

            case 6:
                result = pow(num1, num2);
                printf("Result = %.2lf\n", result);
                break;

            case 8:
                if (num2 == 0) {
                    printf("Error: Total value cannot be zero.\n");
                } else {
                    result = (num1 / num2) * 100;
                    printf("Percentage = %.2lf%%\n", result);
                }
                break;
        }
    }

    return 0;
}
