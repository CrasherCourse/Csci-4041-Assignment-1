# Csci 4061 Assignment 1
# This is the makefile for MySort

MySort: src/MySort.o src/SortAlgs.o src/FileManager.o
	gcc -g -o MySort src/MySort.o src/SortAlgs.o src/FileManager.o -lrt

src/MySort.o: src/MySort.c 
	gcc -g -o src/MySort.o -c src/MySort.c

src/SortAlgs.o: src/SortAlgs.c
	gcc -g -o src/SortAlgs.o -c src/SortAlgs.c

src/FileManager.o: src/FileManager.c
	gcc -g -o src/FileManager.o -c src/FileManager.c

clean:
	rm src/*.o
	rm MySort


