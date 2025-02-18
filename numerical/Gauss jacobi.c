#include <stdio.h>
#include <math.h>

#define N 3  // Number of equations (Adjust as needed)
#define TOL 0.0001  // Convergence tolerance
#define MAX_ITER 100  // Maximum iterations

void gauss_jacobi(double A[N][N], double B[N], double X[N]) {
    double X_new[N];  // Stores new values of X
    int iter = 0;
    int i, j;
    
    printf("Iteration %d: ", iter);
    for (i = 0; i < N; i++) {
        printf("x%d = %.6f  ", i + 1, X[i]);
    }
    printf("\n");

    while (iter < MAX_ITER) {
        for (i = 0; i < N; i++) {
            X_new[i] = B[i];

            for (j = 0; j < N; j++) {
                if (i != j) {
                    X_new[i] -= A[i][j] * X[j];
                }
            }
            X_new[i] /= A[i][i];  // Divide by diagonal element
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

        // Update X values for next iteration
        for (i = 0; i < N; i++) {
            X[i] = X_new[i];
        }

        if (converged) {
            printf("\nSolution found!\n");
            return;
        }

        iter++;
    }

    printf("\nMethod did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double A[N][N] = {
        {10, -1, 2}, 
        {-1, 11, -1}, 
        {2, -1, 10}
    };

    double B[N] = {6, 25, -11};  // Right-hand side vector
    double X[N] = {0, 0, 0};  // Initial guesses

    printf("Solving system using Gauss-Jacobi Method:\n");
    gauss_jacobi(A, B, X);

    return 0;
}
