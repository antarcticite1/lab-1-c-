#include <stdlib.h>
#include "matrix_op.h"

double** matrix_plus(double** a, double** b, int n){
    double** res = malloc(n * sizeof(double*));
    for (int i=0; i<n; i++){
        res[i] = malloc(n*sizeof(double));
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

double** matrix_minus(double** a, double** b, int n){
    double** res = malloc(n * sizeof(double*));
    for (int i=0; i<n; i++){
        res[i] = malloc(n*sizeof(double));
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
}

double** matrix_multi(double** a, double** b, int n){
    int i, j, k;
    double** res = malloc(n * sizeof(double*));
    for (i=0; i<n; i++){
        res[i] = malloc(n*sizeof(double));
    }
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            res[i][j]=0;
            for (k=0; k<n; k++){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

void free_matrix(double** matrix, int n){
    for (int i=0; i<n; i++){
        free(matrix[i]);
    }
    free(matrix);
}

