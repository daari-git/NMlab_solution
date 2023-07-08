/* Gauss jacobi method 
prepared by:-
Subash khanal 
crn: 020-626 */

#include <stdio.h>
#define N 3  // Number of unknowns
#define MAX_ITER 100  // Maximum number of iterations
#define TOLERANCE 0.00001  // Convergence tolerance

void gaussJacobi(double A[N][N], double B[N], double X[N]) {
    int i, j, iter;
    double X_prev[N];

    // Initialize the solution vector
    for (i = 0; i < N; i++) {
        X[i] = 0.0;
    }

    // Perform iterations
    for (iter = 0; iter < MAX_ITER; iter++) {
        // Store the previous solution
        for (i = 0; i < N; i++) {
            X_prev[i] = X[i];
        }

        // Compute new approximations
        for (i = 0; i < N; i++) {
            double sum = B[i];

            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum -= A[i][j] * X_prev[j];
                }
            }

            X[i] = sum / A[i][i];
        }

        // Check for convergence
        double error = 0.0;
        for (i = 0; i < N; i++) {
            error += (X[i] - X_prev[i]) * (X[i] - X_prev[i]);
        }

        if (error < TOLERANCE * TOLERANCE) {
            break;
        }
    }
}

int main() {
    double A[N][N] = {{5,-2,3},
                      {-3,9,1},
                      {2,-1,-7}};
    double B[N] = {-1,2,3};
    double X[N];
    // programmer details 
	printf("Gauss Jacobi by:-\n Subash khanal\n\n");

    gaussJacobi(A, B, X);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("X[%d] = %.4f\n", i, X[i]);
    }

    return 0;
}
