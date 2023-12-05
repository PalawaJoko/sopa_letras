#include <stdio.h>
#include <ctype.h>
#include "submenu.h"
#include "registro.h"

int main(){
	printf("Bienvenido a Sopa de Letras 1.0\n");
	char opcion;
	do{
		printf("Por favor, Elija una opcion:\n1-Jugar\n2-Ver Puntajes\n3-.Salir\n");
		scanf("%s",&opcion);
		switch(opcion){
		case '1':
			int recibido = subMenu();
			if(recibido!=0){
				opcion=3;
			}
			break;
		case '2':
			VerArchivo();
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
