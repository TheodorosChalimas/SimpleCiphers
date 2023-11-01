
project1: demo.o simple_crypto.o
		gcc demo.c simple_crypto.o -o project1

demo.o: demo.c
		gcc -c demo.c

simple_crypto.o: simple_crypto.c simple_crypto.h
		gcc -c simple_crypto.c

clean:
		rm *.o project1
