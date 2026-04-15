#ifndef matrix_op_h
#define matrix_op_h

double **matrix_plus(double** a, double** b, int n);
double **matrix_minus(double** a, double** b, int n);
double **matrix_multi(double** a, double** b, int n);
void free_matrix(double** matrix, int n);
#endif
