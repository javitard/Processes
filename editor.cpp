#include <stdio.h>
#include <stdlib.h>

const char *programa[] = {
	"gedit",
	"vim",
	NULL
};

int mostrar_menu() {
	int opcion;

	system("clear");
	printf("Opciones:\n");
	for (int op=0; programa[op]; op++)
		printf("\n%i .- %s\n", op + 1, programa[op]);
	printf("\n ¿Con qué programa quiere editar el archivo de texto?\n");
	scanf("%i", &opcion);

	return opcion - 1;
}

int main(int argc, char *argv[]) {
	int opcion;
	opcion = mostrar_menu();
	printf("\nSe ha arrancado %s\n\n", programa[opcion]);
	system(programa[opcion]);
	return EXIT_SUCCESS;
}