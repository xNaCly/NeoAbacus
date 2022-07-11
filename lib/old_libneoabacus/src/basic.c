#include <math.h>

double root(double base, double radicand){
    if(base < 0) return base;
    return pow(base, 1.0/radicand);
}
