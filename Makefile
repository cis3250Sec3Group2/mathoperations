all: MathOperations

MathOperations: GreatestCommonDivisor.o BaseConversion.o Fibonacci.o PrimalityTest.o PrimeFactorization.o MathOperations.o
	gcc -o MathOperations GreatestCommonDivisor.o  BaseConversion.o Fibonacci.o PrimalityTest.o PrimeFactorization.o MathOperations.o

MathOperations.o: MathOperations.c GreatestCommonDivisor.h  BaseConversion.h Fibonacci.h PrimalityTest.h PrimeFactorization.h
	gcc -o MathOperations.o -c MathOperations.c -W -Wall -ansi -pedantic

GreatestCommonDivisor.o: GreatestCommonDivisor.c
	gcc -o GreatestCommonDivisor.o -c GreatestCommonDivisor.c -W -Wall -ansi -pedantic

BaseConversion.o: BaseConversion.c
	gcc -o BaseConversion.o -c BaseConversion.c -W -Wall -ansi -pedantic

Fibonacci.o: Fibonacci.c
	gcc -o Fibonacci.o -c Fibonacci.c -W -Wall -ansi -pedantic

PrimalityTest.o: PrimalityTest.c
	gcc -o PrimalityTest.o -c PrimalityTest.c -W -Wall -ansi -pedantic

PrimeFactorization.o: PrimeFactorization.c
	gcc -o PrimeFactorization.o -c PrimeFactorization.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
