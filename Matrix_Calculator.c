#include <stdio.h>

/* Helper function prototypes */
void inputMatrix(int r, int c, double m[r][c]);
void printMatrix(int r, int c, double m[r][c]);
void addMatrix(int r, int c, double a[r][c], double b[r][c]);
void subtractMatrix(int r, int c, double a[r][c], double b[r][c]);
void scalarMultiply(int r, int c, double a[r][c], double k);
void multiplyMatrix(int r1, int c1, int r2, int c2, double a[r1][c1], double b[r2][c2]);
void transposeMatrix(int r, int c, double a[r][c]);
double determinant2x2(double m[2][2]);
double determinant3x3(double m[3][3]);
void inverse2x2(double m[2][2]);

/* Implementations */

void inputMatrix(int r, int c, double m[r][c]) {
    printf("Enter elements row by row:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%lf", &m[i][j]);
}

void printMatrix(int r, int c, double m[r][c]) {
    printf("\nMatrix (%dx%d):\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%10.4lf ", m[i][j]);
        printf("\n");
    }
}

void addMatrix(int r, int c, double a[r][c], double b[r][c]) {
    double res[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];

    printMatrix(r, c, res);
}

void subtractMatrix(int r, int c, double a[r][c], double b[r][c]) {
    double res[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];

    printMatrix(r, c, res);
}

void scalarMultiply(int r, int c, double a[r][c], double k) {
    double res[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] * k;

    printMatrix(r, c, res);
}

void multiplyMatrix(int r1, int c1, int r2, int c2, double a[r1][c1], double b[r2][c2]) {
    if (c1 != r2) {
        printf("Error: multiplication not possible (columns of A must equal rows of B).\n");
        return;
    }

    double res[r1][c2];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0.0;
            for (int k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }

    printMatrix(r1, c2, res);
}

void transposeMatrix(int r, int c, double a[r][c]) {
    double t[c][r];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printMatrix(c, r, t);
}

double determinant2x2(double m[2][2]) {
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}

double determinant3x3(double m[3][3]) {
    double det =
        m[0][0] * (m[1][1]*m[2][2] - m[1][2]*m[2][1]) -
        m[0][1] * (m[1][0]*m[2][2] - m[1][2]*m[2][0]) +
        m[0][2] * (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    return det;
}

void inverse2x2(double m[2][2]) {
    double det = determinant2x2(m);

    if (det == 0.0) {
        printf("Inverse does not exist (determinant is zero).\n");
        return;
    }

    double inv[2][2];
    inv[0][0] =  m[1][1] / det;
    inv[0][1] = -m[0][1] / det;
    inv[1][0] = -m[1][0] / det;
    inv[1][1] =  m[0][0] / det;

    printMatrix(2, 2, inv);
}

int main(void) {
    int choice;

    while (1) {
        printf("\n=== MATRIX CALCULATOR ===\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Subtraction\n");
        printf("3. Matrix Multiplication\n");
        printf("4. Scalar Multiplication\n");
        printf("5. Matrix Transpose\n");
        printf("6. Determinant (2x2 or 3x3)\n");
        printf("7. Inverse (2x2)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 0;
        }

        if (choice == 0) {
            printf("Exiting...\n");
            break;
        }

        int r, c, r2, c2;
        double k;

        switch (choice) {
            case 1: { /* Addition */
                printf("Enter rows & cols (r c): ");
                scanf("%d %d", &r, &c);
                double a1[r][c], b1[r][c];
                printf("Matrix A:\n"); inputMatrix(r, c, a1);
                printf("Matrix B:\n"); inputMatrix(r, c, b1);
                addMatrix(r, c, a1, b1);
                break;
            }

            case 2: { /* Subtraction */
                printf("Enter rows & cols (r c): ");
                scanf("%d %d", &r, &c);
                double a2[r][c], b2[r][c];
                printf("Matrix A:\n"); inputMatrix(r, c, a2);
                printf("Matrix B:\n"); inputMatrix(r, c, b2);
                subtractMatrix(r, c, a2, b2);
                break;
            }

            case 3: { /* Multiplication */
                printf("Enter rows & cols for Matrix A (r c): ");
                scanf("%d %d", &r, &c);
                printf("Enter rows & cols for Matrix B (r c): ");
                scanf("%d %d", &r2, &c2);
                double a3[r][c], b3[r2][c2];
                printf("Matrix A:\n"); inputMatrix(r, c, a3);
                printf("Matrix B:\n"); inputMatrix(r2, c2, b3);
                multiplyMatrix(r, c, r2, c2, a3, b3);
                break;
            }

            case 4: { /* Scalar Multiplication */
                printf("Enter rows & cols (r c): ");
                scanf("%d %d", &r, &c);
                double a4[r][c];
                printf("Matrix:\n"); inputMatrix(r, c, a4);
                printf("Enter scalar value: ");
                scanf("%lf", &k);
                scalarMultiply(r, c, a4, k);
                break;
            }

            case 5: { /* Transpose */
                printf("Enter rows & cols (r c): ");
                scanf("%d %d", &r, &c);
                double a5[r][c];
                printf("Matrix:\n"); inputMatrix(r, c, a5);
                transposeMatrix(r, c, a5);
                break;
            }

            case 6: { /* Determinant */
                int size;
                printf("Choose size (2 or 3): ");
                scanf("%d", &size);

                if (size == 2) {
                    double m2[2][2];
                    printf("Enter 2x2 matrix:\n"); inputMatrix(2, 2, m2);
                    printf("Determinant = %.4lf\n", determinant2x2(m2));
                } else if (size == 3) {
                    double m3[3][3];
                    printf("Enter 3x3 matrix:\n"); inputMatrix(3, 3, m3);
                    printf("Determinant = %.4lf\n", determinant3x3(m3));
                } else {
                    printf("Invalid size. Only 2 or 3 allowed.\n");
                }
                break;
            }

            case 7: { /* Inverse 2x2 */
                double m2[2][2];
                printf("Enter 2x2 matrix:\n"); inputMatrix(2, 2, m2);
                inverse2x2(m2);
                break;
            }

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
