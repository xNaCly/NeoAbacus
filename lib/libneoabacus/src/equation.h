#ifndef EQUATION_H
#define EQUATION_H

/**
 * TODO: currently only supports linear and quadratic equations
 *
 * get roots for equations up with up to 5 variables
 * this method assumes the equation to be formated in the following way:
 * 0 = ax+bx+cx+dx+e
 * 0 = ax+bx+cx+dx
 * 0 = ax+bx+cx+d
 * 0 = ax+bx+c
 * 0 = ax+b
 */
double* eq_roots(double a, double b, double c, double d, double e);

#endif
