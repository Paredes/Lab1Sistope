CC=gcc
route=

all:main.o funciones.o
	$(CC) main.o funciones.o -o lab1 -Wall -I.
	rm main.o funciones.o


funciones.o: $(route)funciones.c
	$(CC) -c $(route)funciones.c

main.o: $(route)main.c
	$(CC) -c $(route)main.c