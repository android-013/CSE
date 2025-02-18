#include <stdio.h>
#include <math.h>

#define N 3  // Number of equations
#define TOL 0.0001  // Convergence tolerance
#define MAX_ITER 100  // Maximum iterations

void gauss_seidel(double A[N][N], double B[N], double X[N]) {
    int iter = 0, i, j;
    double sum, X_old[N];
    
    printf("Iteration %d: ", iter);
    for (i = 0; i < N; i++) {
        printf("x%d = %.6f  ", i + 1, X[i]);
    }
    printf("\n");

    while (iter < MAX_ITER) {
        for (i = 0; i < N; i++) {
            X_old[i] = X[i];  // Store previous values
        }

        for (i = 0; i < N; i++) {
            sum = B[i];
            
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum -= A[i][j] * X[j];  // Use updated values
                }
            }

            X[i] = sum / A[i][i];  // Compute new x_i
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

    printf("Solving system using Gauss-Seidel Method:\n");
    gauss_seidel(A, B, X);

    return 0;
}
