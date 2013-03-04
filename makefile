# Csci 4061 Assignment 1
# This is the makefile for MySort

MySort: src/MySort.o
	gcc -o MySort src/MySort.o

src/MySort.o: src/MySort.c 
	gcc -o src/MySort.o -c src/MySort.c

clean:
	rm src/*.o
	rm MySort


