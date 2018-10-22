/*
*	This program is the main ptrgoram used to test the fucntionality of all other programs
* in mathoperations, using user input and switch statements
*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#include "MathOperations.h"
#include "PrimalityTest.h"
#include "PrimeFactorization.h"
#include "Fibonacci.h"
#include "BaseConversion.h"
#include "GreatestCommonDivisor.h"


/*Done by Anemmeabasi*/

//this is the main functions used to test the functionality of all other files in the mathoperations folder
int main(int argc, char *argv[]) {

		long int i, j, longResult, lastDigit;
		int baseFrom, baseTo;
		char * a, * strResult, * ordinalIndicator;
		bool boolResult;
		unsigned long int unsignedLResult;
		int * success;

		success = malloc(sizeof(int));
		//*success = '\0';

		/*proper way to do a do-while loop*/
		do {
				printf("*** FUN WITH MATH OPERATIONS ***\n");
				/*printf statements introduced*/
				printf("Select one of the following options to continue (1 - 6):\n");
				printf("1. Primality Test\n");
				printf("2. Prime Factorization\n");
				printf("3. Nth Term in Fibonacci Sequence\n");
				printf("4. Convert a Number from any Base to any Base\n");
				printf("5. Greatest Common Divisor\n");
				printf("6. Exit\n");
				printf("Your Selection: \t");

				i = retrieveNumericInput(success);
				if (success != 1 || i > 6 || i < 1) {
						printf("Error parsing response, please try again.\n");
				}
		} while (success != 1 || i > 6 || i < 1);

		switchCases(i, success);

		return 0;
}


//prints out the user menu for them to select what operations they want to perform.
void switchCases(long int i, int * success) {

		switch (i) {
		case 1:

				do {
						printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
						"Primality Test:\n"
						"Enter a Number to Test the Primality Of: ");

						i = retrieveNumericInput(success);
						if (*success != 1) {
						printf("\nError parsing response, please try again.");
						}
				} while (*success != 1);

				if ((boolResult = isPrime(i)) == 0) {
						printf("The Number IS NOT Prime.\n");
				} else if (boolResult == 1) {
						printf("The Number IS Prime.\n");
				}

				*success = '\0';
				boolResult = '\0';
				i = '\0';
				break;

		case 2:

				do {
						printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
						"Prime Factorization:\n"
						"Enter a Number to take the Prime Factorization Of: ");

						i = retrieveNumericInput(success);
								if (*success != 1) {
										printf("\nError parsing response, please try again.\n");
								} else {

										strResult = primeFactorization(i, success);

										if (strResult == NULL && *success == -1) {
												printf("\nError: Please Enter a Number Greater Than 1.\n");
											}
								}
				} while (*success != 1);

				printf("The Prime Factorization of %ld is: %s\n", i, strResult);

				free(strResult);
				break;

		case 3:

		do {
				printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
				"Nth Term in Fibonacci Sequence:\n"
				"Enter the Term of the Fibonacci Sequence You Want: ");

				i = retrieveNumericInput(success);
						if (*success != 1) {
								printf("\nError parsing response, please try again.\n");
						} else {

						unsignedLResult = nthFibonacciTerm(i, success);

								if (*success == -1) {
										printf("\nError: Please Enter a Non-Negative Number.\n");
								} else if (*success == 0 && unsignedLResult == ULONG_MAX) {
										printf("\nError: Number Too Big. Please Enter a Smaller Term.\n");
								}
						}
		} while (*success != 1);

		lastDigit = i % 10;

		if (lastDigit == 1) {
				ordinalIndicator = "st";
		} else if (lastDigit == 2) {
				ordinalIndicator = "nd";
		} else if (lastDigit == 3) {
				ordinalIndicator = "rd";
		} else {
				ordinalIndicator = "th";
		}

		printf("The %ld%s Term of the Fibonacci Sequence is: %lu\n", i, ordinalIndicator, unsignedLResult);
		break;

		case 4:

		do {
				printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
				"Convert a Number From Any Base to Any Base:\n"
				"Enter the Base to Convert From: ");

				baseFrom = retrieveNumericInput(success);

				if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
				} else if (baseFrom < 2 || baseFrom > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
				    continue;
				}

				printf("Now Enter the Number to Convert: ");
				a = retrieveAlphanumericInput(success, baseFrom);

				if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
				    continue;
				}

				printf("Now Enter the Base to Convert To: ");
				baseTo = retrieveNumericInput(success);

				if (*success != 1) {
						printf("\nError parsing input. Please try again.\n");
						continue;
				} else if (baseTo < 2 || baseTo > 36) {
						printf("\nError: Please Enter a Base Between 2 and 36 (Inclusive)\n");
						*success = 0;
						continue;
				}

				strResult = baseConversion(baseFrom, baseTo, a, success);
				if (*success != 1) {
						printf("\nError Converting Number. Please try again.\n");
						continue;
				}
		} while (*success != 1);

		printf("The Base %d Number %s in Base %d is: %s\n", baseFrom, a, baseTo, strResult);


		free(a);
		free(strResult);
		break;

		case 5:

				do {
						printf("\n~~~~~~~~~~~~~~~~~~~~\n\n"
						"Greatest Common Divisor:\n"
						"Enter Number 1: ");

						i =  retrieveNumericInput(success);

						if (*success != 1) {
								printf("\nError parsing input. Please try again.\n");
								continue;
						}

						if (i == 0) {
								printf("\nError: Please Enter a Non-Zero Number.\n");
								continue;
						}

						printf("Now Enter Number 2: ");
						i2 = retrieveNumericInput(success);

						if (*success != 1) {
								printf("\nError parsing input. Please try again.\n");
								continue;
						}

						if (i == 0) {
								printf("\nError: Please Enter a Non-Zero Number.\n");
								continue;
						}

						longResult = gcd(i, i2, success);

						if (*success != 1) {
								printf("\nError getting result. Please try again.\n");
								continue;
						}
				} while (*success != 1);

				printf("The Greatest Common Divisor of %ld and %ld is %ld\n", i, i2, longResult);
				break;

		case 6:

			free(success);
			break;

		default:

		free(success);
		}

		printf("\n~~~~~~~~~~~~~~~~~~~~\n\n");
		}
}


long int retrieveNumericInput(int* success) {

		char *input;
		char *endptr;
		long int ret;

		retrieveInput(&input, success, 10);

		if (input == NULL || *success != 1) {
				*success = 0;
		}

		errno = 0;
		ret = strtol(input, &endptr, 10);

		if (input == endptr) {
				*success = 0;
		}

		free(input);

		if ((ret == LONG_MAX || ret == LONG_MIN) && errno == ERANGE) {
				*success = 0;
		} else {
				*success = 1;
		}

		reutrn ret;
}


//recieves and checks that what the use entered is alphanumeric
char* retrieveAlphanumericInput(int* success, int base) {

		char *input = NULL;

		retrieveInput(&input, success, base);

		if (input == NULL || *success != 1) {
				*success = 0;
		} else {
				*success = 1;
		}

		return input;
}


//recies what the user inputs
void retrieveInput(char** input, int* success, int base) {

		int size = 128;
		char* newInput = NULL;
		char maxChar = '\0';
		char c = '\0';
		int len = 0;

		if (input == NULL || success == NULL || (base < 2 || base > 36)) {
				return;
		} else {
				*success = '\0';
		}

		*input = malloc(sizeof(char) * size);

		(*input)[size - 1] = '\0'; //wtf does this do???

		if (*input == NULL) {
				*success = 0;
		}

		if (base <= 10) {
				maxChar = base + '0' - 1;
		} else {
				maxChar = 'A' + (base - 11);
		}

		do {
				c = getchar();
				c = toupper(c);

				if (isspace(c)) {
						continue;
				}

				if ((!isalnum(c) && (c != '-' && c != '+')) || ((c == '-' || c == '+') && len != 0) || c > maxChar) {
						free(*input);
						*success = 0;
				}

				if (len == (size - 1)) {
						size += 64;
						newInput = realloc(*input, sizeof(char) * size);
								if (newInput == NULL) {
										*success = 0;
										free(*input);
										return;
								} else {
										*input = newInput;
								}
				}

				if (len == 0 && (c != '-' && c != '+')) {
						(*input)[len] = '+';
						len++;
				}

				(*input)[len] = c;
				len++;
		} while (c != '\n' && c != EOF);

		if (len == 0) {
				free(*input);
				*success = 0;
		}

		newInput = realloc(*input, sizeof(char) * len + 1);

		if (newInput == NULL) {
				*success = 0;
				free(*input);
		} else {
				*input = newInput;
		}

		*success = 1;
		(*input)[len] = '\0';
}
