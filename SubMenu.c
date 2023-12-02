#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SubMenu.h"

int menuTemas(char datos[2][1]){
	char aux;
	do{
		printf("------TEMAS------ \n");
		printf("1. Animales \n2. Hogar \n3. Comida \n4. Volver\n");
		printf("Escoge un tema: ");
		scanf("%s", &aux);
		switch(aux){
			case '1':
				strcpy(datos[0], "A");
				break;
			case '2':
				strcpy(datos[0], "H");
				break;
			case '3':
				strcpy(datos[0], "C");
				break;
			case '4': 
				return 0;
			default:
				printf("Entrada incorrecta, Vuelva a intentarlo\n");
			}
	}while(aux!=4);
	return 0;
}
void menuDif(char datos[2][1]){
	char aux;
	printf("------DIFICULTAD------ \n");
	printf("1. Facil \n2. Media \n3. Dificil\n4. Volver\n");
	printf("Escoge una dificultad: ");
	scanf("%s", &aux);
	switch(aux){
		case '1':
			strcpy(datos[1], "F");
			break;
		case '2':
			strcpy(datos[1], "M");
			break;
		case '3':
			strcpy(datos[1], "D");
			break;
		case '4': 
			menuTemas(datos);
		default:
			printf("Entrada incorrecta, Vuelva a intentarlo\n");
			menuDif(datos);
	}
}

int subMenu(){
	char datos[2][1];
	int flujo;
	flujo = menuTemas(datos);
	menuDif(datos);
	//ModuloMatriz(Datos);
	return flujo;
}
