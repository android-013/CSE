// 4. Secant Method

#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

void secant_method(double x0, double x1, double tol, int max_iter) {
    double x2;
    int iter = 0;

    printf("Iteration %d: x0 = %.6f, x1 = %.6f\n", iter, x0, x1);

    while (iter < max_iter) {
        double fx0 = f(x0);
        double fx1 = f(x1);

        if (fabs(fx1 - fx0) < 1e-6) { // Prevent division by zero
            printf("Denominator too small. Method fails.\n");
            return;
        }

        // Secant method formula: x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        printf("Iteration %d: x2 = %.6f, f(x2) = %.6f\n", iter + 1, x2, f(x2));

        if (fabs(x2 - x1) < tol) { // Stopping condition
            printf("\nRoot found at x = %.6f\n", x2);
            return;
        }

        x0 = x1; // Shift x0 to x1
        x1 = x2; // Shift x1 to x2
        iter++;
    }

    printf("\nMethod did not converge within %d iterations.\n", max_iter);
}

int main() {
    double x0 = 2, x1 = 3; // Initial guesses
    double tolerance = 0.0001;
    int max_iterations = 20;

    secant_method(x0, x1, tolerance, max_iterations);
    return 0;
}
