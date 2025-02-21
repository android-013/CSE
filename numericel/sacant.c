#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

double secant_method_recursive(double x0, double x1, double tol, int max_iter, int iter) {
    double fx0 = f(x0);
    double fx1 = f(x1);

    if (fabs(fx1 - fx0) < 1e-6) { // Prevent division by zero
        printf("Denominator too small. Method fails.\n");
        return x1;
    }

    // Secant method formula: x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
    double x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

    printf("Iteration %d: x0 = %.6f, x1 = %.6f, x2 = %.6f, f(x2) = %.6f\n", iter, x0, x1, x2, f(x2));

    if (fabs(x2 - x1) < tol || iter >= max_iter) { // Stopping condition
        return x2;
    }

    return secant_method_recursive(x1, x2, tol, max_iter, iter + 1);
}

int main() {
    double x0 = 2, x1 = 3; // Initial guesses
    double tolerance = 0.0001;
    int max_iterations = 20;

    double root = secant_method_recursive(x0, x1, tolerance, max_iterations, 0);
    printf("\nRoot found at x = %.6f\n", root);
    return 0;
}
