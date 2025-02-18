#include <stdio.h>
#include <math.h>

#define N 3  // Number of equations
#define TOL 0.0001  // Convergence tolerance
#define MAX_ITER 100  // Maximum iterations

void recursive_gauss_seidel(double A[N][N], double B[N], double X[N], int iter) {
    if (iter >= MAX_ITER) {
        printf("Method did not converge within %d iterations.\n", MAX_ITER);
        return;
    }

    int i, j;
    double X_old[N], sum;

    // Store old values
    for (i = 0; i < N; i++) {
        X_old[i] = X[i];
    }

    // Update values using Gauss-Seidel formula
    for (i = 0; i < N; i++) {
        sum = B[i];
        for (j = 0; j < N; j++) {
            if (j != i) {
                sum -= A[i][j] * X[j];
            }
        }
        X[i] = sum / A[i][i];  // Update in place
    }

    // Print iteration results
    printf("Iteration %d: ", iter + 1);
    for (i = 0; i < N; i++) {
        printf("x%d = %.6f  ", i + 1, X[i]);
    }
    printf("\n");

    // Check for convergence
    int converged = 1;
    for (i = 0; i < N; i++) {
        if (fabs(X[i] - X_old[i]) > TOL) {
            converged = 0;
            break;
        }
    }

    if (converged) {
        printf("\nSolution found!\n");
        return;
    }

    // Recursively call the function
    recursive_gauss_seidel(A, B, X, iter + 1);
}

int main() {
    double A[N][N] = {
        {10, -1, 2}, 
        {-1, 11, -1}, 
        {2, -1, 10}
    };
    double B[N] = {6, 25, -11};  // Right-hand side vector
    double X[N] = {0, 0, 0};  // Initial guesses

    printf("Solving system using Recursive Gauss-Seidel Method:\n");
    recursive_gauss_seidel(A, B, X, 0);

    return 0;
}
