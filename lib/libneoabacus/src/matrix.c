#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "util.h"

Vector* vec_create(int size){
    Vector *v;
    v = (Vector *)malloc(sizeof(Vector));

    v->values = malloc(sizeof(double)*size);
    v->size = size;
    return v;
}

void vec_destroy(Vector *v){
    if(v == NULL) return;
    free(v->values);
    free(v);
}

double vec_len(Vector *v){
    double l; 
    for(int i = 0; i < v->size; i++) l += pow(v->values[i], 2);
    return sqrt(l);
}

Vector* vec_add(Vector *v, Vector *v1){
    // cant add two vectors with differing size (2d vector + 3d vector) 
    // (until matrices are implemented)
    if(v->size != v1->size) return NULL;

    Vector *_v = vec_create(v->size);

    for(int i = 0; i < _v->size; i++) 
        _v->values[i] = v->values[i] + v1->values[i];

    return _v;
}

Vector* vec_sub(Vector *v, Vector *v1);

Vector* vec_mult(Vector *v, double factor);

double vec_scalar_prod(Vector *v, Vector *v1){
    double s;
    for(int i = 0; i < v->size; i++){
        s += v->values[i] * v1->values[i];
    }
    return s;
}

double vec_angle(Vector *v, Vector *v1){
    return acos(vec_scalar_prod(v, v1) 
            / (vec_len(v) * vec_len(v1))) * 180.0 / PI;
}

double vec_triple_prod(Vector *v, Vector *v1, Vector *v2);

