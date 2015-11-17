#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *programa[] = {
	"gedit",
	"vim",
	"subl",
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



int main(int argc, char **argv) {
	FILE *pf = NULL;
	int opcion;

	opcion = mostrar_menu();

	if(opcion > 3 || opcion < 0) {
		fprintf(stderr, "Error: el número no está asociado a ningún programa.\n");
} 
	else {

	printf("\nSe ha arrancado %s, guarde el archivo como file.txt \n\n", programa[opcion]);
	system(programa[opcion]);
}

	fclose(pf);
	return EXIT_SUCCESS;
	
}