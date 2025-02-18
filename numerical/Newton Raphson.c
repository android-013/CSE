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

void newton_raphson(double x0, double tol, int max_iter) {
    double x = x0;
    int iter = 0;

    while (iter < max_iter) {
        double fx = f(x);
        double fpx = f_prime(x);

        if (fabs(fpx) < 1e-6) { // Prevent division by zero
            printf("Derivative too small. Method fails.\n");
            return;
        }

        double x_new = x - fx / fpx;

        printf("Iteration %d: x = %.6f, f(x) = %.6f\n", iter, x, fx);

        if (fabs(x_new - x) < tol) {
            printf("\nRoot found at x = %.6f\n", x_new);
            return;
        }

        x = x_new;
        iter++;
    }

    printf("\nMethod did not converge within %d iterations.\n", max_iter);
}

int main() {
    double initial_guess = 2.5;
    double tolerance = 0.0001;
    int max_iterations = 20;

    newton_raphson(initial_guess, tolerance, max_iterations);
    return 0;
}
