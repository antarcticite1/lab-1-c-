#include <stdio.h>

int main() {
    int x = 1;
    
    while (x) {
        int n = 3;
        double arr[n][n];
        double sumMain = 0, sumSecondary = 0;
        
        printf("Enter values for%dx%d array:\n", n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("Element [%d][%d]: ", i + 1, j + 1);
                scanf("%lf", &arr[i][j]);
            }
        }

        printf("\nmatrix:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%.2lf ", arr[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    sumMain += arr[i][j];
                }

                if (i + j == n - 1) {
                    sumSecondary += arr[i][j];
                }
            }
        }
        
        printf("\nSum of main diagonal elements: %.2lf\n", sumMain);
        printf("Sum of secondary diagonal elements: %.2lf\n", sumSecondary);
        



        int m = 2;
        int intArr[m][m];
        int result[m][m];
        
        printf("\nEnter values for the %dx%d integer array:\n", m, m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                printf("Element [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &intArr[i][j]);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    result[i][j] += intArr[i][k] * intArr[k][j];
                }
            }
        }
        
        printf("\nSquare of the matrix:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                printf("%5d ", result[i][j]);
            }
            printf("\n");
        }

        printf("\nRun again? (1 = yes, 0 = no): ");
        scanf("%d", &x);
        printf("\n");
    }
    
    return 0;
}
