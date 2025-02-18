#include <stdio.h>
#include <math.h>

#define N 3  // Number of equations
#define TOL 0.0001  // Convergence tolerance
#define MAX_ITER 100  // Maximum iterations

void recursive_gauss_jacobi(double A[N][N], double B[N], double X[N], double X_new[N], int iter) {
    if (iter >= MAX_ITER) {
        printf("Method did not converge within %d iterations.\n", MAX_ITER);
        return;
    }

    int i, j;
    for (i = 0; i < N; i++) {
        X_new[i] = B[i];
        for (j = 0; j < N; j++) {
            if (i != j) {
                X_new[i] -= A[i][j] * X[j];
            }
        }
        X_new[i] /= A[i][i];
    }

    // Print iteration results
    printf("Iteration %d: ", iter + 1);
    for (i = 0; i < N; i++) {
        printf("x%d = %.6f  ", i + 1, X_new[i]);
    }
    printf("\n");

    // Check for convergence
    int converged = 1;
    for (i = 0; i < N; i++) {
        if (fabs(X_new[i] - X[i]) > TOL) {
            converged = 0;
            break;
        }
    }

    // Copy new values into X
    for (i = 0; i < N; i++) {
        X[i] = X_new[i];
    }

    if (converged) {
        printf("\nSolution found!\n");
        return;
    }

    // Recursively call the function
    recursive_gauss_jacobi(A, B, X, X_new, iter + 1);
}

int main() {
    double A[N][N] = {
        {10, -1, 2}, 
        {-1, 11, -1}, 
        {2, -1, 10}
    };
    double B[N] = {6, 25, -11};  // Right-hand side vector
    double X[N] = {0, 0, 0};  // Initial guesses
    double X_new[N];

    printf("Solving system using Recursive Gauss-Jacobi Method:\n");
    recursive_gauss_jacobi(A, B, X, X_new, 0);

    return 0;
}
