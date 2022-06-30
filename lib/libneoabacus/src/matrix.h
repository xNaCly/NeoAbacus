#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double* values;
    int size;
} Vector;

Vector* vec_create(int size);

void vec_destroy(Vector *v);

double vec_len(Vector *v);

Vector* vec_add(Vector *v, Vector *v1);

Vector* vec_sub(Vector *v, Vector *v1);

Vector* vec_mult(Vector *v, double factor);

double vec_scalar_prod(Vector *v, Vector *v1);

double vec_angle(Vector *v, Vector *v1);

double vec_triple_prod(Vector *v, Vector *v1, Vector *v2);

#endif
