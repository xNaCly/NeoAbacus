#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fail_t = 0;
int success_t = 0;

void end(clock_t begin){
    clock_t end = clock();
    int total_t = fail_t + success_t;
    int fail_perc = total_t > 0 ? (fail_t * 100) / total_t : 0;
    int success_perc = total_t > 0 ? (success_t * 100) / total_t : 0;
    double t = (double)(end-begin) / CLOCKS_PER_SEC;
    printf("test result: %s; %d (%d) passed; %d (%d) failed; finished in: %.2fs\n", 
            fail_t == 0 ? "ok" : "fail", success_t, success_perc, fail_t, fail_perc, t);
}

int main(void){
    clock_t begin = clock();
    printf("running tests\n");
    end(begin);
    if(fail_t != 0) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
