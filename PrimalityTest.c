#include <stdlib.h>
#include <math.h>
#include "PrimalityTest.h"

<<<<<<< HEAD
//This function checks to see if the number is a prime number
int isPrime(long int num) {
	if (num <= 1) {
		return 0;
	} else if (num <= 3) {
=======
/*This functino checks to see if the passed value is a prime number*/
int isPrime( long int num ) {
		int i;
 

		if (num <= 1) {
					return 0;
			} else if (num <= 3) {
					return 1;
			}

			if (num % 2 == 0) {
					return 0;
			}

			for (i = 3; i <= sqrt( num ); i += 2) {
					if (num % i == 0) {
							return 0;
					}
			}

>>>>>>> cpavel
		return 1;
}


/* This function gets the next prime number */
long int getNextPrime( long int num ) {
		if (num < 2) {
				return 2;
		}

<<<<<<< HEAD

//This function looks for the next prime number
long int getNextPrime(long int num) {
	if (num < 2) {
		return 2;
	}

	if (num % 2 == 0) {
		num += 1;
	} else {
		num += 2;
	}
=======
		if (num % 2 == 0) {
				num += 1;
		} else {
				num += 2;
		}
>>>>>>> cpavel

		while (isPrime(num == 0 )) {
				num += 2;
		}

		return num;
}
