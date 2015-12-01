#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

struct TDato{  
	char letra;
}

void *imprimir(void *dato){  //funcion que realiza cada hilo.
	struct TDato *letter = (struct TDato *) dato;

	char c = letter->letra;

	while(1)
		putc(letra, stderr);
}

int main(int argc, char *argv[]){
	struct TDato A = {'A'};
	struct TDato B = {'B'};

	pthread_t hilos[2]; //declarar hilo

	pthread_create(&hilos[1], NULL, &imprimir, (void *) A); //crear hilo
	pthread_create(&hilos[2], NULL, &imprimir, (void *) B);

	pthread_join (&hilo[1], NULL);
	pthread_join (&hilo[2], NULL);

	return EXIT_SUCCESS;
}



