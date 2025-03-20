#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - x - 1
#define f(x) ((x)*(x)*(x) - (x) - 1)

void false_position(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Incorrect initial guesses. f(a) and f(b) must have opposite signs.\n");
        return;
    }

    double c;
    int iteration = 1;

    printf("Iteration\t a\t\t b\t\t c\t\t f(c)\n");
    do {
        // False position formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        printf("%d\t %lf\t %lf\t %lf\t %lf\n", iteration, a, b, c, f(c));

        // Check if the root is found
        if (fabs(f(c)) < tol) {
            printf("\nRoot found: %lf\n", c);
            return;
        }

        // Update a or b based on the sign of f(c)
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iteration++;
    } while (fabs(f(c)) > tol);

    printf("\nApproximate root: %lf\n", c);
}

int main() {
    double a, b, tol;

    // Input initial guesses and tolerance
    printf("Enter first guess (a): ");
    scanf("%lf", &a);
    printf("Enter second guess (b): ");
    scanf("%lf", &b);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    // Call the function to find the root
    false_position(a, b, tol);
printf("Programmed by Roshan Yadav");
    return 0;
}
