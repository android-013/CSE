//2.False Position Method

#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

void false_position(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [%.4f, %.4f], f(a) and f(b) must have opposite signs.\n", a, b);
        return;
    }

    double c;
    int iter = 0;

    do {
        // Compute the new point using False Position formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        //printf("Iteration %d: a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", iter, a, b, c, f(c));

        if (fabs(f(c)) < tol)  // Stopping condition
            break;

        if (f(c) * f(a) < 0) 
            b = c; // Root is in [a, c]
        else 
            a = c; // Root is in [c, b]

        iter++;
    } while (fabs(f(c)) >= tol);

    printf("\nRoot found at x = %.6f\n", c);
}

int main() {
    double a = 2, b = 3; // Interval [a, b]
    double tolerance = 0.0001;

    false_position(a, b, tolerance);
    return 0;
}
