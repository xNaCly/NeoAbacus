#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double** values;
    int size_x;
    int size_y;
} Matrix;

Matrix* mtrx_create(int size_x, int size_y, double** values);

void mtrx_destroy(Matrix *m);

double vec_len(Matrix *v);

Matrix* mtrx_add(Matrix *m, Matrix *m1);

Matrix* mtrx_sub(Matrix *m, Matrix *m1);

Matrix* mtrx_mult_fctr(Matrix *m, double factor);
Matrix* mtrx_mult_mtrx(Matrix *m, Matrix *m1);

double mtrx_scalar_prod(Matrix *m, Matrix *m1);

double mtrx_angle(Matrix *m, Matrix *m1);

double vec_triple_prod(Matrix *m, Matrix *m1, Matrix *m2);

double mtrx_trace(Matrix *m);

#endif
