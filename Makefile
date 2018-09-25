all: GreatestCommonDivisor

GreatestCommonDivisor: GreatestCommonDivisor.o main.o
	gcc -o GreatestCommonDivisor GreatestCommonDivisor.o main.o

GreatestCommonDivisor.o: GreatestCommonDivisor.c
	gcc -o GreatestCommonDivisor.o -c GreatestCommonDivisor.c -W -Wall -ansi -pedantic

main.o: main.c GreatestCommonDivisor.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o
