#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001 // Tolerance level

// Define the function whose root we want to find
double func(double x)
{
    return x * x * x - x - 3; // Example: f(x) = x^3 - x - 3
}

// Bisection Method function
double bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        printf("Invalid interval! The function values at the given interval must have opposite signs.\n");
        return -1;
    }

    double c;
    while ((b - a) >= EPSILON)
    {
        c = (a + b) / 2; // Find the midpoint

        if (func(c) == 0.0) // If exact root is found
            break;

        if (func(c) * func(a) < 0) // Decide the new interval
            b = c;
        else
            a = c;
    }
    return c;
}

int main()
{
    double a, b;

    // Input the interval [a, b]
    printf("Enter the initial guesses a and b: ");
    scanf("%lf %lf", &a, &b);

    double root = bisection(a, b);

    if (root != -1)
        printf("The root of the equation is: %.4lf\n", root);
printf("Programmed by Roshan Yadav");
    return 0;
}
