#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>


int main(int argc, char *argv[]){

	int seg = shmget(IPC_PRIVATE, 0x1000, IPC_CREAT | S_IRUSR | S_IWUSR); // Crea la hoja (privada, tamaño, creamos y permisos)

	char *mensaje = (char *) shmat(seg, (void *) 0, 0); // (Variable nombre hoja, posición, macros)
	sprintf(mensaje, "Hola soy javi");

	shmdt(mensaje);

	char *mensajeleido = (char *) shmat(seg, (void*) 0, 0);
	printf("%s", mensajeleido);

	shmdt(mensajeleido);

	shmctl(seg, IPC_RMID, 0); //Elimina la hoja (nombre, MACROBorrar, cero)
	return EXIT_SUCCESS;
}