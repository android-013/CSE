#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [%.4f, %.4f], f(a) and f(b) must have opposite signs.\n", a, b);
        return;
    }

    double mid;
    int iter = 0;

    while ((b - a) >= tol) {
        mid = (a + b) / 2;

        printf("Iteration %d: a = %.6f, b = %.6f, mid = %.6f, f(mid) = %.6f\n", iter, a, b, mid, f(mid));

        if (f(mid) == 0.0) { // Exact root found
            break;
        } else if (f(mid) * f(a) < 0) {
            b = mid;
        } else {
            a = mid;
        }
        iter++;
    }

    printf("\nRoot found at x = %.6f\n", mid);
}

int main() {
    double a = 2, b = 3; // Interval [a, b]
    double tolerance = 0.0001;

    bisection(a, b, tolerance);
    return 0;
}
