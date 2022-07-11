#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "util.h"

void print_mtrx(Matrix *m){
    printf("%dx%d\n", m->size_x, m->size_y);
    for(int i = 0; i < m->size_x; i++){
        for(int j = 0; j < m->size_y; j++){
            printf("%s%.2f|",j == 0 ? "|" : "", m->values[i][j]);
        }
        printf("\n");
    }
}

Matrix* __mtrx_create(int size_x, int size_y){
    Matrix *m;
    m = (Matrix *)malloc(sizeof(Matrix));
    m->values = malloc(sizeof(double**)*size_x);
    for(int i = 0; i < size_x; i++){
        m->values[i] = malloc(sizeof(double*)*size_y);
        for(int j = 0; j < size_y; j++){
            m->values[i][j] = 0;
        }
    }
    m->size_x = size_x;
    m->size_y = size_y;
    return m;
}

Matrix* mtrx_create(int size_x, int size_y, double** values){
    Matrix *m = __mtrx_create(size_x, size_y);
    for(int i = 0; i < size_x; i++){
        m->values[i] = malloc(sizeof(double*)*size_y);
        for(int j = 0; j < size_y; j++){
            m->values[i][j] = values[i][j];
        }
    }
    return m;
}

void mtrx_destroy(Matrix *m){
    if(m == NULL) return;
    for(int i = 0; i < m->size_x; i++){
        free(m->values[i]);
    }
    free(m->values);
    free(m);
}

double vec_len(Matrix *v){
    if(v->size_x != 1) return .0;
    double l = .0;
    for(int i = 0; i < v->size_y; i++)
        l += pow(v->values[0][i], 2);
    return sqrt(l);
}

Matrix* mtrx_add(Matrix *m, Matrix *m1){
    if(!(m->size_x == m1->size_x && m->size_y == m1->size_y)) return NULL;

    Matrix *_m = __mtrx_create(m->size_x, m->size_y);

    for(int i = 0; i < _m->size_x; i++){
        for(int j = 0; j < _m->size_y; j++){
            _m->values[i][j] = m->values[i][j] + m1->values[i][j];
        }
    }

    return _m;
}

Matrix* mtrx_sub(Matrix *m, Matrix *m1){
    if(!(m->size_x == m1->size_x && m->size_y == m1->size_y)) return NULL;

    Matrix *_m = __mtrx_create(m->size_x, m->size_y);

    for(int i = 0; i < _m->size_x; i++){
        for(int j = 0; j < _m->size_y; j++){
            _m->values[i][j] = m->values[i][j] - m1->values[i][j];
        }
    }

    return _m;
}

Matrix* mtrx_mult_fctr(Matrix *m, double factor){
    Matrix *_m = __mtrx_create(m->size_x, m->size_y);
    for(int i = 0; i < m->size_x; i++){
        for(int j = 0; j < m->size_y; j++){
            _m->values[i][j] = m->values[i][j] * factor;
        }
    }
    return _m;
}

// TODO: implement
Matrix* mtrx_mult_mtrx(Matrix *m, Matrix *m1){
    print_mtrx(m);
    printf("\n");
    print_mtrx(m1);
    printf("\n");
    if(m->size_x != m1->size_y) return NULL;
    Matrix *_m = __mtrx_create(m1->size_x, m->size_y);

    for(int i = 0; i < _m->size_y; i++){
        for(int j = 0; j < _m->size_x; j++){
            double t = 0;
            for(int a = 0; a < m->size_x; a++){
                for(int b = 0; b < m->size_y; b++){
                }
            }
            _m->values[i][j] = t;
        }
    }

    print_mtrx(_m);
    return _m;
}


double mtrx_trace(Matrix *m){
    double t = 0;
    for(int i = 0; i < m->size_x; i++){
        for(int j = 0; j < m->size_y; j++){
            if(i == j) t += m->values[i][j];
        }
    }
    return t;
}

/*
 * computes the cosinus angle between m and m1
 */
double mtrx_angle(Matrix *m, Matrix *m1){
    Matrix *_m = mtrx_mult_mtrx(m, m1);
    double s = mtrx_trace(_m);
    printf("%f\n", s);
    free(_m);
    return s / (sqrt(s) * sqrt(s));
}
