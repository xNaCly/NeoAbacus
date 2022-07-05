#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "basic.h"
#include "util.h"

double* eq_roots(double a, double b, double c, double d, double e){
    double *roots = malloc(sizeof(double)*5);
    if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0) return NULL;
    else if(a != 0 && b != 0 && c != 0){
        // calculate crossings with the x axis for a quadratic equation
        // using the following formular:
        //
        // ax^2 + bx + c = 0
        // x_1,2 = (-b ± (b^2-4ac)^(1/2) ) / (2a)
        double t0 = (b*(-1) - sqrt((pow(b, 2))-4*a*c));
        double t1 = (b*(-1) + sqrt((pow(b, 2))-4*a*c));
        roots[0] = t0 / 2*a;
        roots[1] = t1 / 2*a;
    } else if(a != 0 && b != 0){
        // calculate crossings with the x axis for a linear equation using the following formular:
        // ax+b; x_0 = -b/a
        roots[0] = (double)(b*-1)/a;
    } 
    return roots;
}
