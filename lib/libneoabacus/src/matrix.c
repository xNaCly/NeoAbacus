#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "util.h"

/*
 *
 * pretty prints matrices in the following way:
 *
 *  4x1: 
 *  ┌────┬────┬────┬────┐
 *  │0.00│1.00│2.00│3.00│
 *  └────┴────┴────┴────┘
 *
 *  2x2: 
 *  ┌────┬────┐
 *  │2.00│2.00│
 *  │2.00│2.00│
 *  └────┴────┘
 *
 *  3x3: 
 *  ┌────┬────┬────┐
 *  │2.00│2.00│2.00│
 *  │2.00│2.00│2.00│
 *  │2.00│2.00│2.00│
 *  └────┴────┴────┘
 *
 */
void print_mtrx(Matrix *m){
    printf("%dx%d: \n", m->size_x, m->size_y);

    for(int i = 0; i < m->size_x; i++){
        if(i == 0) printf("┌────");
        else printf("┬────");
        if(i == m->size_x-1) printf("┐\n");
    }

    if(m->size_y == 1) printf("│");

    for(int i = 0; i < m->size_x; i++){
        for(int j = 0; j < m->size_y; j++){
            printf("%s%.2f│", j == 0 && m->size_y != 1 ? "│": "", m->values[i][j]);
        }
        if(m->size_y != 1) printf("\n");
    }

    if(m->size_y == 1) printf("\n");

    for(int i = 0; i < m->size_x; i++){
        if(i == 0) printf("└────");
        else printf("┴────");
        if(i == m->size_x-1) printf("┘\n");
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
    // can only multiply matrices in which m has the exact same amount of colums as m1 amount of rows
    if(m->size_x != m1->size_y) return NULL;
    // row vector * column vector
    else if(m->size_y == 0 && m1->size_x == 0){
        Matrix *_m = __mtrx_create(1, 1);
        double s = 0;
        for(int i = 0; i < m->size_x; i++){
            for(int j = 0; j < m1->size_y; j++){
                s += m->values[i][0] * m1->values[0][j];
            }
        }
        _m->values[0][0] = s;
        return _m;
    }

    Matrix *_m = __mtrx_create(m1->size_x, m->size_y);

    for(int i = 0; i < _m->size_y; i++){
        for(int j = 0; j < _m->size_x; j++){
            for(int a = 0; a < m->size_x; a++){
                for(int b = 0; b < m->size_y; b++){

                }
            }
        }
    }

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
