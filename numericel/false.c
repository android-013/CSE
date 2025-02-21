#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

double false_position_recursive(double a, double b, double tol, int iter) {
    double c = (a * f(b) - b * f(a)) / (f(b) - f(a));

    printf("Iteration %d: a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", iter, a, b, c, f(c));

    if (fabs(f(c)) < tol)  // Stopping condition
        return c;

    if (f(c) * f(a) < 0) 
        return false_position_recursive(a, c, tol, iter + 1);
    else 
        return false_position_recursive(c, b, tol, iter + 1);
}

int main() {
    double a = 2, b = 3; // Interval [a, b]
    double tolerance = 0.0001;

    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [%.4f, %.4f], f(a) and f(b) must have opposite signs.\n", a, b);
    } else {
        double root = false_position_recursive(a, b, tolerance, 0);
        printf("\nRoot found at x = %.6f\n", root);
    }

    return 0;
}
