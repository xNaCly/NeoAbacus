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

int fail_t = 0;
int success_t = 0;
int cur_t = 0;

int t_is_equal(double a, double b){
    if((a-b)<0.1) return 1;
    else return 0;
}

void t_assert(int condition, char* message){
    cur_t++;
    if(condition) { 
        printf("Test [%d]: '%s' passed\n", cur_t, message);
        success_t++; return; 
    }
    else { fail_t++; printf("Test [%d]: '%s' failed\n", cur_t, message); }
}

//void t_example(){
//    t_assert(0 == 1, "0 == 1 check");
//    t_assert(0 == 0, "0 == 0 check");
//    t_assert(0 > 0, "0 > 0 check");
//}

void t_matrix(){
    Vector *v = vec_create(3);
    Vector *v1 = vec_create(3);
    Vector *v2 = vec_add(v, v1);
    for(int i = 0; i < v->size; i++){
        v->values[i] = 2;
        v1->values[i] = 2;
    }
    double l = vec_len(v);
    double l1 = vec_len(v);
    double a = vec_angle(v, v2);
    double s = vec_scalar_prod(v, v1);

    t_assert(t_is_equal(3.464102, l) && t_is_equal(3.464102, l1), "calculate vector length");
    t_assert(v2 != NULL && t_is_equal(vec_len(v2), 6.928203), "add two vectors together");
    t_assert(t_is_equal(a, 90.002654), "calculate angle between two vectors");
    t_assert(t_is_equal(s, 12.0), "calculate scalar of two vectors");

    vec_destroy(v);
    vec_destroy(v1);
    vec_destroy(v2);
}

void end(clock_t begin){
    clock_t end = clock();

    int total_t = fail_t + success_t;
    int fail_perc = total_t > 0 ? (fail_t * 100) / total_t : 0;
    int success_perc = total_t > 0 ? (success_t * 100) / total_t : 0;
    double t = (double)(end-begin) / CLOCKS_PER_SEC;

    printf("test result: %s; total: %d; %d (%d%%) passed; %d (%d%%) failed; finished in: %.2fs\n", 
            fail_t == 0 ? "ok" : "fail", total_t, success_t, success_perc, fail_t, fail_perc, t);
}

int main(void){
    clock_t begin = clock();

    printf("running tests\n");
    // add new tests here:
    // t_example();
    t_matrix();

    end(begin);

    if(fail_t != 0) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
