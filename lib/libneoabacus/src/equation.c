#include <stdlib.h>
#include <stdio.h>

double* eq_roots(double a, double b, double c, double d, double e){
    double *roots = malloc(sizeof(double)*5);
    if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0) return NULL;
    else if(a != 0 && b != 0){
        // calculate crossings with the x axis for a linear equation using the following formular:
        // ax+b; x_0 = -b/a
        roots[0] = (double)(b*-1)/a;
    }
    return roots;
}
