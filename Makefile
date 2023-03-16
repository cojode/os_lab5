LIBNAME=funcs
CC=gcc
SRCS=*.c
FLAGS=-lm -g

all: program1 program2

program1: derivative.a
	$(CC) program1.c derivative.a -o program1 $(FLAGS)

program2: derivative.so sort.so
	$(CC) program2.c -o program2 $(FLAGS)

derivative.so: 
	$(CC) -fPIC -c simple_derivative.c complex_derivative.c
	$(CC) -shared *.o -o derivative.so 

sort.so: 
	$(CC) -fPIC -c bubble_sort.c quick_sort.c
	$(CC) -shared *.o -o sort.so

%.a:
	$(CC) -c simple_derivative.c complex_derivative.c
	ar rc $*.a *.o 
	ranlib $*.a

clean:
	rm -rf *.o *.a *.so program1 program2