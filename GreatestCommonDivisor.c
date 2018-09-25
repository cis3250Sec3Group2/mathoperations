#include <stdlib.h>
#include "GreatestCommonDivisor.h"

/*
* Fonction that calculate the greatest common divisor for two number
* Param:
* 	int num1 : first number
*	int num2 : secon number
* Return:
* 	long int greatest common divisor
*/
long int gcd(long int num1, long int num2, int* success) {
	if (num1 == 0 || num2 == 0) {
		*success = 0;
		return 0;
	}

	if (success == NULL) {
		return 0;
	} else {
		*success = '\0';
	}

	if (num1 < 0) {
		num1 *= -1;
	}

	if (num2 < 0) {
		num2 *= -1;
	}

	if (num2 > num1) {
		long int temp = num2;
		num2 = num1;
		num1 = temp;
	}

	long int remainder = '\0';
	long int lastRemainder = '\0';

	do {
		lastRemainder = remainder;
		remainder = (num1 % ((num1 / num2) * num2));
		num1 = num2;
		num2 = remainder;
	} while (remainder != 0);

	*success = 1;

	if (lastRemainder == 0) {
		return num1;
	} else {
		return lastRemainder;
	}
}
