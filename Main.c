#include <stdio.h>
#include <ctype.h>

int main(){
	printf("Bienvenido a Sopa de Letras 1.0\n");
	char opcion;
	do{
		printf("Por favor, Elija una opcion:\n1-Jugar\n2-Ver Puntajes\n3-.Salir\n");
		scanf("%s",&opcion);
		switch(opcion){
		case '1':
			printf("Entre a la opcion 1\n");
			break;
		case '2':
			printf("Entre a la opcion 2\n");
			break;
		case '3':
			printf("Terminando programa, gracias por entrar a Sopa de Letras 1.0\n");
			break;
		default:
			printf("opcion no valida\n\n");
		}
	}while(opcion!='3');
	return 0;
}
