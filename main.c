#include <stdlib.h>
#include <stdio.h>
#include "GreatestCommonDivisor.h"

/* Main for testing GreatestCommonDivisor.c */

int main (int argc, char *argv[]) {
    int num1 = 100;
    int num2 = 30;
    int success = 0;

    long int greatestCommonDivisor = gcd(num1, num2, &success);

    if(success == 1){
        printf("%ld\n", greatestCommonDivisor);
    }
}
