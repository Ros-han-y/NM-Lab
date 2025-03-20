#include <stdio.h>
#include <math.h>

// Define function to ensure correct floating-point operations
#define f(x) (1.0 / (1.0 + (x)))

int main() {
    float a, h, x0, xn, fx0, fxn, term, v;
    int i, k;

    // Taking input
    printf("Enter the Lower & Upper Limits: ");
    scanf("%f %f", &x0, &xn);

    printf("Enter the number of Segments (must be even): ");
    scanf("%d", &k);

    // Check if k is even, as required by Simpson's rule
    if (k % 2 != 0) {
        printf("\nError: The number of segments must be even for Simpson's 1/3 rule.\n");
        return 1; // Exit the program if k is odd
    }

    // Compute step size
    h = (xn - x0) / k;
    fx0 = f(x0);
    fxn = f(xn);
    term = fx0 + fxn;

    // Apply Simpson's 1/3 Rule
    for (i = 1; i <= k - 1; i += 2) {
        a = x0 + i * h;
        term += 4 * f(a);
    }

    for (i = 2; i <= k - 2; i += 2) {
        a = x0 + i * h;
        term += 2 * f(a);
    }

    v = (h / 3.0) * term; // Ensure proper floating-point division

    // Display result
    printf("Using Composite Simpson's 1/3 rule:");
    printf("\nValue of Integration = %f\n", v);
    printf("Programmed by Roshan Yadav\n");

    return 0;
}
