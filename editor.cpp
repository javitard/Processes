#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

sig_atomic_t acabado = 0;

void cerrar(int signum){
	acabado = 1;
}

void spawn(const char *command, const char *parameter) {
	pid_t child = fork();

	if(!child) {
		execl(command,command,parameter,NULL);
		fprintf(stderr, "Programa hijo no encontrado.\n" );
	}
}

int main(int argc, char *argv[]) {
	int opcion;
	const char *child = "./editorhijo";
	const char *text_file = "file.txt";
	int child_status;

	struct sigaction sa;
	sa.sa_handler = cerrar;

	sigaction(SIGCHLD, &sa, NULL);

	spawn(child, text_file);

	wait(&child_status);

	system("cat file.txt");
	system("rm file.txt");


	return EXIT_SUCCESS;
}
