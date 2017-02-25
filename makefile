all: run

run: clearCodage compile
	./codageExponentiation

compile:
	gcc codageExponentiation.c -Wall -o codageExponentiation

clearCodage:
	rm -rf codageExponentiation
