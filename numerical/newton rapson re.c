#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

// Define the derivative f'(x) = 3x^2 - 4
double f_prime(double x) {
    return 3 * x * x - 4;
}

double newton_raphson_recursive(double x, double tol, int max_iter, int iter) {
    double fx = f(x);
    double fpx = f_prime(x);

    if (fabs(fpx) < 1e-6) { // Prevent division by zero
        printf("Derivative too small. Method fails.\n");
        return x;
    }

    double x_new = x - fx / fpx;

    printf("Iteration %d: x = %.6f, f(x) = %.6f\n", iter, x, fx);

    if (fabs(x_new - x) < tol || iter >= max_iter) {
        return x_new;
    }

    return newton_raphson_recursive(x_new, tol, max_iter, iter + 1);
}

int main() {
    double initial_guess = 2.5;
    double tolerance = 0.0001;
    int max_iterations = 20;

    double root = newton_raphson_recursive(initial_guess, tolerance, max_iterations, 0);
    printf("\nRoot found at x = %.6f\n", root);
    return 0;
}
