#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Descripcion
//Entrada:
//Salida:
void funcion(int a,int b){
	printf("aca funcando.\n");
}

void controlador(int num){
	printf("Soy el hijo con pid: %d , y estoy vivo aún. No me mates papá.\n", getpid());
}