#include <stdlib.h>
#include <string.h>
#include "PrimeFactorization.h"
#include "PrimalityTest.h"
<<<<<<< HEAD

/*The function calculates the prime base*/
=======
/*Done by Ciprian Pavel*/
>>>>>>> c072939ce852aed5736faa2202fc466f2806b381
char* primeFactorization(long int num, int* success) {
		long int base = 2;
		long int power = 0;
		char* list = malloc(sizeof(char));

		if (success == NULL) {
			return NULL;
		} else {
			*success = '\0';
		}

		if (num <= 1) {
			*success = -1;
			return NULL;
		}
		list[0] = '\0';

		if (isPrime(num) == 1) {
			*success = 1;
			list = addToList(list, num, 1);
			return list;
		}

		while (num != 1) {
			while (num % base == 0) {
				num /= base;
				power++;
			}

			if (power != 0) {
				list = addToList(list, base, power);

				if (num != 1 && isPrime(num) == 1) {
					list = addToList(list, num, 1);
					break;
				}

				power = 0;
			}

			base = getNextPrime(base);
		}

		*success = 1;
		return list;
}

/*The function converts the number to string*/
char* toString(long int num) {
		int len = 1;
		int i;
		long int newNum = num;
		char *ret = malloc(sizeof(char) * len + 1);

		while (newNum / 10 != 0) {
			newNum /= 10;
			len++;
		}
		ret[len] = '\0';

		for (i = len - 1; i >= 0; i--) {
			ret[i] = ((num % 10) + '0');
			num /= 10;
		}

		return ret;
}

/*The function adds the string to the list*/
char* addToList(char* list, long int base, long int power) {
		char* baseStr = toString(base);
		char* powerStr = toString(power);
		int currentLen = strlen(list);
		int newLen = currentLen + strlen(baseStr) + strlen(powerStr);

		char* newList;
		if (currentLen == 0) {
			newList = realloc(list, sizeof(char) * newLen + 2);
			strcat(newList,baseStr);
			strcat(newList, "^");
			strcat(newList, powerStr);
		} else {
			newList = realloc(list, sizeof(char) * newLen + 5);
			strcat(newList, " * ");
			strcat(newList, baseStr);
			strcat(newList, "^");
			strcat(newList, powerStr);
		}

		free(baseStr);
		free(powerStr);
		baseStr = NULL;
		powerStr = NULL;
		return newList;
}
