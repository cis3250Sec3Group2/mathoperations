#include<stdio.h>
#include"BaseConversion.c"

int main() {
  char *a;
  int *x;
  *a = "test";
  *x = 5;
  baseConversion(2, 10, *a, *x);
//  willNextOverflow(unsigned long int, unsigned long int);
}
