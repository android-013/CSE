#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
    return x * x * x - 4 * x - 9;
}

double bisection_recursive(double a, double b, double tol, int iter) {
    double mid = (a + b) / 2;

    printf("Iteration %d: a = %.6f, b = %.6f, mid = %.6f, f(mid) = %.6f\n", iter, a, b, mid, f(mid));

    if ((b - a) < tol || f(mid) == 0.0) {
        return mid;
    }

    if (f(mid) * f(a) < 0) {
        return bisection_recursive(a, mid, tol, iter + 1);
    } else {
        return bisection_recursive(mid, b, tol, iter + 1);
    }
}

int main() {
    double a = 2, b = 3; // Interval [a, b]
    double tolerance = 0.0001;

    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [%.4f, %.4f], f(a) and f(b) must have opposite signs.\n", a, b);
    } else {
        double root = bisection_recursive(a, b, tolerance, 0);
        printf("\nRoot found at x = %.6f\n", root);
    }

    return 0;
}
