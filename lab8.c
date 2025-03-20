#include <stdio.h>

// Function to be integrated
double f(double x) {
    return x * x; // Example: f(x) = x^2
}

// Trapezoidal Rule Function
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // First and last terms

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x); // Summing intermediate terms
    }

    return (h / 2) * sum; // Final result
}

int main() {
    double a, b;
    int n;

    // Input lower and upper limits
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter number of subintervals (n): ");
    scanf("%d", &n);

    // Compute the integral
    double result = trapezoidal(a, b, n);

    // Output result
    printf("Approximate integral using Trapezoidal Rule: %lf\n", result);
printf("Programmed by Roshan Yadav");
    return 0;
}
