#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int EXIT = 0;
//A = [tema, dif]
char Datos[2][MAX] = {"a", "b"};

void menuTemas(char Array[][MAX]){
	char aux;
	printf("------TEMAS------ \n");
	printf("1. Animales \n2. Hogar \n3. Comida \n4. Volver\n");
	printf("Escoge un tema: ");
	scanf("%s", &aux);
	switch(aux){
		case '1':
			strcpy(Array[0], "A");
			break;
		case '2':
			strcpy(Array[0], "H");
			break;
		case '3':
			strcpy(Array[0], "C");
			break;
		/*case 4: funcion anterior
			menuPrincipal*/
		default:
			printf("Entrada incorrecta, Vuelva a intentarlo\n");
			menuTemas(Datos);
	}
}
void menuDif(char Array[][MAX]){
	char aux;
	printf("------DIFICULTAD------ \n");
	printf("1. Facil \n2. Media \n3. Dificil\n4. Volver\n");
	printf("Escoge una dificultad: ");
	scanf("%s", &aux);
	switch(aux){
		case '1':
			strcpy(Array[1], "F");
			break;
		case '2':
			strcpy(Array[1], "M");
			break;
		case '3':
			strcpy(Array[1], "D");
			break;
		case '4': 
			menuTemas(Datos);
		default:
			printf("Entrada incorrecta, Vuelva a intentarlo\n");
			menuDif(Datos);
	}
}

void subMenu(){
	menuTemas(Datos);
	menuDif(Datos);
	ModuloMatriz(Datos);
	
}
