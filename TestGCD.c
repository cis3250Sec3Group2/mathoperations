#include <stdlib.h>
#include <stdio.h>
#include "GreatestCommonDivisor.h"



/* Test of the function GreatestCommonDivisor */

/* We testing gcd with one number equal to zero */
static int test_gcd_with_arg0_is_0(){
    long int arg0, arg1, expected_gcd, gcd_result;

    int *success = (int*)malloc(sizeof(int));
	*success = '\0';

    arg0 = 0;
    arg1 = 12;
    expected_gcd = 0;

    /* running test */
    gcd_result = gcd(arg0, arg1, success);

    /* evaluate test */
    if(gcd_result == expected_gcd){
        printf("PASS test_gcd_with_arg0_is_0\n");
        return 0;
    }

    printf("FAIL test_gcd_with_arg0_is_0: got %ld, expected %ld for gcd() with %ld and %ld arguments\n",
        gcd_result, expected_gcd, arg0, arg1);
    return 1;
}

/* We testing gcd with success to null */
static int test_gcd_with_success_null(){
    long int arg0, arg1, expected_gcd, gcd_result;

    int *success = NULL;

    arg0 = 4;
    arg1 = 15;
    expected_gcd = 0;

    /* running test */
    gcd_result = gcd(arg0, arg1, success);

    /* evaluate test */
    if(gcd_result == expected_gcd){
        printf("PASS test_gcd_with_success_null\n");
        return 0;
    }

    printf("FAIL test_gcd_with_success_null: got %ld, expected %ld because success null, for gcd() with %ld and %ld arguments\n",
        gcd_result, expected_gcd, arg0, arg1);
    return 1;
}

/* We testing gcd with one number negative */
static int test_gcd_with_arg0_negative(){
    long int arg0, arg1, expected_gcd, gcd_result;

    int *success = (int*)malloc(sizeof(int));
	*success = '\0';

    arg0 = -6;
    arg1 = 2;
    expected_gcd = 2;

    /* running test */
    gcd_result = gcd(arg0, arg1, success);

    /* evaluate test */
    if(gcd_result == expected_gcd){
        printf("PASS test_gcd_with_arg0_negative\n");
        return 0;
    }

    printf("FAIL test_gcd_with_arg0_negative: got %ld, expected %ld for gcd() with %ld and %ld arguments\n",
        gcd_result, expected_gcd, arg0, arg1);
    return 1;
}

/* We testing gcd with arg1>arg0 */
static int test_gcd_with_arg1_greater_then_arg0(){
    long int arg0, arg1, expected_gcd, gcd_result;

    int *success = (int*)malloc(sizeof(int));
	*success = '\0';

    arg0 = 3;
    arg1 = 12;
    expected_gcd = 3;

    /* running test */
    gcd_result = gcd(arg0, arg1, success);

    /* evaluate test */
    if(gcd_result == expected_gcd){
        printf("PASS test_gcd_with_arg1_greater_then_arg0\n");
        return 0;
    }

    printf("FAIL test_gcd_with_arg1_greater_then_arg0: got %ld, expected %ld for gcd() with %ld and %ld arguments\n",
        gcd_result, expected_gcd, arg0, arg1);
    return 1;
}

/* We testing gcd with two positive integer arg1 and arg0 not relatively prime and arg0>arg1 */
static int test_gcd_basic(){
    long int arg0, arg1, expected_gcd, gcd_result;

    int *success = (int*)malloc(sizeof(int));
	*success = '\0';

    arg0 = 25;
    arg1 = 20;
    expected_gcd = 5;

    /* running test */
    gcd_result = gcd(arg0, arg1, success);

    /* evaluate test */
    if(gcd_result == expected_gcd){
        printf("PASS test_gcd_basic\n");
        return 0;
    }

    printf("FAIL test_gcd_basic: got %ld, expected %ld for gcd() with %ld and %ld arguments\n",
        gcd_result, expected_gcd, arg0, arg1);
    return 1;
}

/* We testing gcd with two positive integer arg1 and arg0 relatively prime and arg0>arg1 */
static int test_gcd_arg0_and_arg1_relatively_prime(){
    long int arg0, arg1, expected_gcd, gcd_result;

    int *success = (int*)malloc(sizeof(int));
	*success = '\0';

    arg0 = 7;
    arg1 = 3;
    expected_gcd = 1;

    /* running test */
    gcd_result = gcd(arg0, arg1, success);

    /* evaluate test */
    if(gcd_result == expected_gcd){
        printf("PASS test_gcd_arg0_and_arg1_relatively_prime\n");
        return 0;
    }

    printf("FAIL test_gcd_arg0_and_arg1_relatively_prime: got %ld, expected %ld for gcd() with %ld and %ld arguments\n",
        gcd_result, expected_gcd, arg0, arg1);
    return 1;
}

/* Main with no argument, all values for testing are hard coded */
int main(){
    int nbFailures = 0;

    /* Identify that we are beginning our tests */
    printf("TESTCASES: gcd() function\n");

    /* Run each test in turn */
    nbFailures += test_gcd_basic();
    nbFailures += test_gcd_with_arg0_is_0();
    nbFailures += test_gcd_with_success_null();
    nbFailures += test_gcd_with_arg0_negative();
    nbFailures += test_gcd_with_arg1_greater_then_arg0();
    nbFailures += test_gcd_arg0_and_arg1_relatively_prime();

    /* print out an identifyable completion, so that
    * if there is a crash we can recognize that we
    * did not get this far
    */

    if(nbFailures == 0){
        printf("COMPLETION: SUCCESS -- gcd()\n");
        return 0;
    }

    /* return non-zero to parent process so that our lack
    * of success can be tracked
    */
    printf("COMPLETION: FAILURES -- gcd() : %d\n", nbFailures);
    return -1;
}
