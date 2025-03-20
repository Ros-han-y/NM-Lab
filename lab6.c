#include <stdio.h>

#define MAX 10 // Maximum number of data points

// Function to calculate divided differences
void dividedDifferenceTable(double x[], double y[][MAX], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j+1][i-1] - y[j][i-1]) / (x[j+i] - x[j]);
        }
    }
}

// Function to find interpolated value using Newton's Divided Difference
double interpolate(double x[], double y[][MAX], int n, double xp) {
    double result = y[0][0]; // First term
    double term;
    
    for (int i = 1; i < n; i++) {
        term = y[0][i];
        for (int j = 0; j < i; j++) {
            term *= (xp - x[j]);
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    double x[MAX], y[MAX][MAX], xp;

    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i][0]); // First column of divided difference table
    }

    // Compute divided difference table
    dividedDifferenceTable(x, y, n);

    // Input the value of x for interpolation
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xp);

    // Perform interpolation
    double yp = interpolate(x, y, n, xp);
    
    // Output result
    printf("Interpolated value at x = %lf is y = %lf\n", xp, yp);
printf("Programmed by Roshan Yadav");
    return 0;
}
