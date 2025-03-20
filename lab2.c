#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001 // Error tolerance

// Function whose root we want to find
double f(double x) {
    return (x*x*x)-(3*x)-2; // Example equation: x^3 -3x-2= 0
}

// Derivative of the function
double df(double x) {
    return (3*x*x)-3; // Derivative: 3x^2 - 3
}

void newtonRaphson(double x0) {
    double x1;
    int iteration = 0;
    
    while (1) {
        x1 = x0 - f(x0) / df(x0); // Newton-Raphson formula
        printf("Iteration %d: x = %.6f\n", iteration, x1);
        
        if (fabs(x1 - x0) < EPSILON) { // Stop if the difference is small enough
            break;
        }
        
        x0 = x1;
        iteration++;
    }
    printf("Root of the equation: %.6f\n", x1);
}

int main() {
    double initialGuess;
    printf("Enter initial guess: ");
    scanf("%lf", &initialGuess);
    
    newtonRaphson(initialGuess);
    printf("Programmed by Roshan Yadav");
    return 0;
}
