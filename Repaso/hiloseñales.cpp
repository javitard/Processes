#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

sig_atomic_t numero = 0;

void acabar (int signumber){
	numero = 1;
}

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

	//int esperar;

	struct TDato A = {'A'};
	struct TDato B = {'B'};
pthread_t hilos[2]; //declarar hilo

	pthread_create(&hilos[1], NULL, &imprimir, (void *) A); //crear hilo
	pthread_create(&hilos[2], NULL, &imprimir, (void *) B);
	

	struct sigaction sa;
	sa.sa_handler = &acabar;
	sigaction (SIGINT, &sa, NULL); //señal a cambiar - funcion - usa por defecto la anterior(NULL)

	if(numero != 0)
	//wait(&esperar)
	pthread_join (&hilos[1], NULL);
	pthread_join (&hilos[2], NULL);

	return EXIT_SUCCESS;
}



