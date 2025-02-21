#include <stdio.h>
#include <math.h>

// Define the function g(x) such that x = g(x)
double g(double x) {
    return (9 + 4 * x) / 3;  // Example transformation of f(x) = x^3 - 4x - 9
}

double fixed_point_recursive(double x0, double tol, int max_iter, int iter) {
    double x1 = g(x0);

    printf("Iteration %d: x = %.6f\n", iter, x1);

    if (fabs(x1 - x0) < tol || iter >= max_iter) {
        return x1;
    }

    return fixed_point_recursive(x1, tol, max_iter, iter + 1);
}

int main() {
    double initial_guess = 2.5;
    double tolerance = 0.0001;
    int max_iterations = 20;

    double root = fixed_point_recursive(initial_guess, tolerance, max_iterations, 0);
    printf("\nRoot found at x = %.6f\n", root);
    return 0;
}
