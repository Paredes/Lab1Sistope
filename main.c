#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include "biblioteca.h"

int main(int argc, char *argv[])
{
	int hvalue=0;
	int mflag=0;
	int c;
	while( (c=getopt(argc,argv,"h:m")) != -1){
		switch(c){
			case 'h':
				sscanf(optarg,"%d",&hvalue);
				break;
			case 'm':
				mflag=1;
				break;
			case '?':
				if(optopt== 'c')
					fprintf(stderr, "Opcion -%c requiere un argumento.\n",optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Opcion desconocida `%c'.\n",optopt);
				else
					fprintf(stderr, "Opcion con caracter desconocido `\\x%x'.\n",optopt);
				return 1;
			default:
				abort();
		}
	}
	//printf("Cantidad de procesos: %d.\n",hvalue);
	//printf("PIDPadre:%d.\n",getpid() );
	int pidPadre=getpid();
	int arrayPID[hvalue];
	for (int i = 0; i < hvalue; i++){
		if(mflag){
			if(i==0){
				printf("Mostrando la información por pantalla:\n");
			}
			// si el proceso actual es el padre
			if( pidPadre == getpid()){
				arrayPID[i]=fork();
				// en caso de que se cree el proceso hijo con exito
				if(arrayPID[i] > 0){
					printf("Número: %d , pid: %d\n",i+1,arrayPID[i]);
				}
			}
		}
	}
	int en=0;
	int indiceHijo;
	int senal;
	while(en==0 && getpid()==pidPadre){
		printf("Ingresar número de hijo y señal a enviar (X - Y):");
		// numHijo - senal a enviar
		scanf("%d - %d",&indiceHijo,&senal);
		
		if(indiceHijo < 0 || indiceHijo >= hvalue){
			printf("El número de hijo es incorrecto\n debe ser un número entre 1 y %d\n",hvalue);
		}
		else{
			printf("La señal %d será enviada al hijo %d con pid %d\n",senal, indiceHijo,arrayPID[indiceHijo-1]);
		}
		signal(SIGINT, controlador);
	}

	return 0;
}
