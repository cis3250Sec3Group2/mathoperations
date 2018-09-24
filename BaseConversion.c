#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "BaseConversion.h"

char* baseConversion(int baseFrom, int baseTo, char* num, int* success) {
	if (baseFrom < 2 || baseFrom > 36 || num == NULL || success == NULL) {
		if (success != NULL) {
			*success = -1;
		}
		return NULL;
	} else {
		*success = '\0';
	}

	int len = 0;
	int isPositive = '\0';
	while (num[len] != '\0') {
		if (len == 0) {
			if (num[len] == '-') {
				isPositive = 0;
			} else if (num[len] == '+') {
				isPositive = 1;
			} else {
				isPositive = 1;
			}
		}
		len++;
	}

	if (baseFrom == baseTo) {
		char* ret = (char*)malloc(sizeof(char) * (len + 1));
		ret[len] = '\0';

		memcpy (ret, num, len);
		*success = 1;
		return ret;

	}

	char maxChar = '\0';
	if (baseFrom <= 10) {
		maxChar = baseFrom + '0' - 1;
	} else {
		maxChar = 'A' + (baseFrom - 11);
	}

	int power = 0;
	unsigned long int numBase10 = 0;
	unsigned long int nextNum = '\0';
	int i;
	for (i = (len - 1); i >= 0; i--) {
		if (num[i] == '+' || num[i] == '-') {
			continue;
		}

		num[i] = toupper(num[i]);
		if (num[i] >= '0' && num[i] <= '9') {
			nextNum = num[i] - '0';
		} else if (num[i] >= 'A' && num[i] <= maxChar) {
			nextNum = (num[i] + 10) - 'A';
		} else {
			*success = 0;
			return NULL;
		}

		nextNum *= pow(baseFrom, power);

		if (willNextOverflow(numBase10, nextNum) == 1) {
			*success = 0;
			return NULL;
		}

		numBase10 += nextNum;
		power++;
	}

	len = 1;
	long int numCopy = numBase10;
	while (numCopy != 0) {
		numCopy /= baseTo;
		len++;
	}

	char* ret = (char*)malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';

	for (i = (len - 1); i > 0; i--) {
		nextNum = numBase10 % baseTo;

		if (nextNum > 9) {
			nextNum = (nextNum - 10) + 'A';
		} else {
			nextNum += '0';
		}

		ret[i] = nextNum;
		numBase10 /= baseTo;
	}

	if (isPositive == 0) {
		ret[0] = '-';
	} else {
		ret[0] = '+';
	}

	*success = 1;
	return ret;
}

int willNextOverflow(unsigned long int num1, unsigned long int num2) {
	if (num1 > ULONG_MAX - num2) {
		return 1;
	} else {
		return 0;
	}
}
