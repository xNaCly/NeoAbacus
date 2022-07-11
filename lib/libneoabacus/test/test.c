/*
 * @author xnacly
 *
 * test.c implements a simple testing framework for the nacus library (libneoabacus)
 *
 * Infos for contributors:
 *     View the t_example() for reference
 *
 *     Checklist to create a new test for a function:
 *         - import lib file
 *         - create a new test function prefixed with t_
 *         - call function and assign return value to a new variable
 *         - use t_assert(return_value != 0) to check if the function worked correctly
 *         - call the test function in main
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../src/matrix.h"
#include "../src/basic.h"
#include "../src/equation.h"
#include "../src/util.h"

int fail_t = 0;
int success_t = 0;
int cur_t = 0;

/*
 * compares two doubles
 */
int t_is_equal(double a, double b){
    if((fabs(a) - fabs(b)) < 0.1) return 1;
    else return 0;
}

/*
 * implementation of assert method to log results and count fails and successes
 */
void t_assert(int condition, char* message){
    cur_t++;
    if(condition) { 
        printf("[PASS] [t_%d]: '%s' passed\n",
                cur_t,
                message);
        success_t++; return; 
    }
    else { 
        fail_t++;
        printf("[FAIL] [t_%d]: '%s' failed\n", cur_t, message); 
    }
}

//void t_example(){
//    t_assert(0 == 1, "0 == 1 check");
//    t_assert(0 == 0, "0 == 0 check");
//    t_assert(0 > 0, "0 > 0 check");
//}

void t_equ(){
    double *roots = eq_roots(5, -3, 0, 0, 0);
    double *roots1 = eq_roots(2, -8, 6, 0, 0);
    t_assert(t_is_equal(-0.6, roots[0]),
            "getting root of a linear equation");
    t_assert(t_is_equal(3.0, roots1[1]) 
            && t_is_equal(1.0, roots1[0]), 
            "getting roots of a quadratic equation");
    free(roots);
    free(roots1);
}

void t_basic(){
    t_assert(t_is_equal(3, root(27, 3)), 
            "calculate the 3d root of 12");
}

void t_matrix(){
    double** values = malloc(sizeof(double)*2);
    for(int i = 0; i < 2; i++){
        values[i] = malloc(sizeof(double)*2);
        for(int j = 0; j < 3; j++){
            values[i][j] = 2;
        }
    }

    double** values1 = malloc(sizeof(double)*3);
    for(int i = 0; i < 3; i++){
        values1[i] = malloc(sizeof(double)*3);
        for(int j = 0; j < 3; j++){
            values1[i][j] = 2;
        }
    }

    //double** rv_values = malloc(sizeof(double)*4);
    //for(int i = 0; i < 4; i++){
    //    rv_values[i] = malloc(sizeof(double));
    //    for(int j = 0; j < 1; j++){
    //        rv_values[i][j] = i;
    //    }
    //}

    //Matrix *rv = mtrx_create(4, 1,  rv_values);
    //print_mtrx(rv);
    //printf("\n");

    Matrix *m = mtrx_create(2, 2, values);
    Matrix *m1 = mtrx_create(2, 2, values);
    Matrix *m2 = mtrx_add(m, m1);
    Matrix *m3 = mtrx_sub(m, m1);
    Matrix *m4 = mtrx_mult_mtrx(m, m1);
    Matrix *m5 = mtrx_create(3,3, values1);
    //print_mtrx(m5);

    double t = mtrx_trace(m);
    double t1 = mtrx_trace(m5);
    /* double a = mtrx_angle(m, m2); */

    for(int i = 0; i < 2; i++) free(values[i]);
    free(values);

    for(int i = 0; i < 3; i++) free(values1[i]);
    free(values1);

    t_assert(t_is_equal(m2->values[0][0], 4) &&
            t_is_equal(m2->values[0][1], 4) && 
            t_is_equal(m2->values[1][0], 4) && 
            t_is_equal(m2->values[1][1], 4), "adding matrices test");
    t_assert(t_is_equal(m3->values[0][0], 0) && 
            t_is_equal(m3->values[0][1], 0) && 
            t_is_equal(m3->values[1][0], 0) && 
            t_is_equal(m3->values[1][1], 0), "subtracting matrices test");
    t_assert(t_is_equal(t, 4) 
            && t_is_equal(t1, 6), "trace matrix test");

    mtrx_destroy(m);
    mtrx_destroy(m1);
    mtrx_destroy(m2);
    mtrx_destroy(m3);
    mtrx_destroy(m4);
    mtrx_destroy(m5);
}

void end(clock_t begin){
    clock_t end = clock();

    int total_t = fail_t + success_t;
    int fail_perc = total_t > 0 ? (fail_t * 100) / total_t : 0;
    int success_perc = total_t > 0 ? (success_t * 100) / total_t : 0;
    double t = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("test result: %s%s%s; total: %d; %d (%d%%) passed; %d (%d%%) failed; finished in: %.2fs\n",
            fail_t == 0 ? ANSI_COLOR_GREEN : ANSI_COLOR_RED,
            fail_t == 0 ? "ok" : "fail",
            ANSI_RESET,
            total_t,
            success_t,
            success_perc,
            fail_t,
            fail_perc,
            t);
}

int main(void){
    clock_t begin = clock();

    printf("running tests\n");
    // add new tests here:
    // t_example();

    t_matrix();
    t_basic();
    t_equ();

    end(begin);

    if(fail_t != 0) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
