//4. Fixed Point Iteration Method

#include <stdio.h>
#include <math.h>

// Define the function g(x) such that x = g(x)
double g(double x) {
    return (9 + 4 * x) / 3;  // Example: Rewriting f(x) = x^3 - 4x - 9 as x = (9 + 4x) / 3
}

void fixed_point_iteration(double x0, double tol, int max_iter) {
    double x1;
    int iter = 0;

    printf("Iteration %d: x = %.6f\n", iter, x0);

    while (iter < max_iter) {
        x1 = g(x0); // Compute next approximation

        printf("Iteration %d: x = %.6f\n", iter + 1, x1);

        if (fabs(x1 - x0) < tol) { // Stopping condition
            printf("\nRoot found at x = %.6f\n", x1);
            return;
        }

        x0 = x1;
        iter++;
    }

    printf("\nMethod did not converge within %d iterations.\n", max_iter);
}

int main() {
    double initial_guess = 2.5;
    double tolerance = 0.0001;
    int max_iterations = 20;

    fixed_point_iteration(initial_guess, tolerance, max_iterations);
    return 0;
}
