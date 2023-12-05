#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include "definedstruct.h"
#include "generartexto.h"
#include "modulomatriz.h"
#include "registro.h"

int MAX;

//Se define el largo de la matriz a partir de la dificultad
int largoMatriz(char dif){

	switch(dif){
		case 'F':
			return 6;	
			break;
		case 'M':
			return 8;
			break;
		case 'D':
			return 10;
			break;

	}
}

void inicializarMatrix(struct casilla sopa[][MAX], int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n; j++){
		
			strcpy(sopa[i][j].dato, " ");
			sopa[i][j].ocupado = false;
		}
	}
}

void imprimeMatriz(struct casilla sopa[][MAX], int n){
	
	printf("[ ]");
	for(int i = 0; i<n; i++){
    	printf("[%d]", i);
    }
    printf("\n");
	for(int i=0;i<n;i++){
		printf("[%d]", i);
		for(int j=0;j<n; j++){
			if(sopa[i][j].ocupado){
				printf("[%c]", sopa[i][j].dato[0]);
			}
			else{
				printf("[\033[1;34m%c\033[0m]", sopa[i][j].dato[0]);
			}
			
			
		}
    	printf("\n");
    }

}

//Funcion que permite imprimir en pantalla la lista de palabras
void imprimeLista(struct string listaPalabras[MAX-1], int largoListaPalabras){
	printf("Palabras a buscar: \n");
	for(int i=0;i<(largoListaPalabras-1);i++){
		printf("-%s", listaPalabras[i].dato);

	}
	printf("%s\n", listaPalabras[largoListaPalabras-1].dato);
}

//Agrega elementos a un arreglo
void agregarElemento(char palabraEscogida[60], int i, struct casilla sopa[MAX][MAX], int j, int k){
	palabraEscogida[i] = sopa[j][k].dato[0];
}

//Corrobora que las palabra ingresada pertenezca a la lista
void obtenerPalabra(int posIni_i, int posIni_j, int posFin_i, int posFin_j, char dir, struct casilla sopa[MAX][MAX], int n, char temporal[60]){

	for(int i = 0; i<MAX; i++){
		agregarElemento(temporal, i, sopa, posIni_i, posIni_j);
		if(posIni_i==posFin_i && posIni_j == posFin_j){
			break;
		}
		if(dir=='1'){
			
			if(posIni_i >= 0){
				
				posIni_i--;
			}
			
		}
		if(dir=='2'){
		
			if(posIni_i <= n){
				
				posIni_i++;
			}
		}
		
		if(dir=='3'){
			
			if(posIni_j >= 0){
				posIni_j--;
				
			}
		}
		if(dir=='4'){
		
			if(posIni_j <= n){
				
				posIni_j++;
			}
		}

	}
}

//elimina la palabra de la lista 
void eliminaPalabra(struct string listaPalabras[MAX-1], char palabraEscogida[MAX], int i){
	for(int j = 0; j < strlen(palabraEscogida); j++){
		listaPalabras[i].dato[j] = '-';
	}
}

//elimina la palabra de la matriz
void eliminaPalabraMatriz(struct casilla sopa[][MAX], int n, int posIni_i, int posIni_j, char dir, char palabraEscogida[MAX]){

	for(int i = 0; i<strlen(palabraEscogida); i++){
		
		sopa[posIni_i][posIni_j].ocupado = false;
		
		if(dir=='1'){
			posIni_i--;
		}
		if(dir=='2'){
			posIni_i++;
		}
		
		if(dir=='3'){
			posIni_j--;
		}
		
		if(dir=='4'){
			posIni_j++;
		}
		
	}
}
	
//comprueba que la palabra ingresada pertenece a la lista
bool validarPalabra(char palabraEscogida[MAX], struct string listaPalabras[MAX-1], struct casilla sopa[][MAX], int n, int posIni_i, int posIni_j, int posFin_i, int posFin_j, char dir){
	for(int i = 0; i < MAX-1; i++){
		if(strcmp(palabraEscogida, listaPalabras[i].dato)==-13){
			eliminaPalabra(listaPalabras, palabraEscogida, i);
			eliminaPalabraMatriz(sopa, n, posIni_i, posIni_j, dir, palabraEscogida);
			return true;
		}else{
		}
	}
	return false;
}

//Verifica que aun queden palabras por buscar 
bool verificarPalabras(int aciertos, int largoListaPalabras){
	if( aciertos == largoListaPalabras){
		return false;
	}
	else{
		return true;
	}
}


//Funcion que permite la interaccion con el usuario 
int Jugar(struct casilla sopa[MAX][MAX], int n, struct string listaPalabras[MAX-1], int largoListaPalabras){
	int turnos = 0;
	int aciertos = 0;
	bool condicion = true;
	printf("-------------Inicio del juego-------------\n");
	while(condicion!=false){
		char posIni_i[MAX];
		char posIni_j[MAX];
		char posFin_i[MAX];
		char posFin_j[MAX];
		char dir[MAX];
		imprimeLista(listaPalabras, MAX-1);
		imprimeMatriz(sopa, MAX);
		printf("Turnos utilizados = %d\n", turnos);
		
		//Preguntamos por la posicion inicial y final de la palabra, además de la direccion
		printf("Ingresa la posicion inicial i de la palabra (de arriba hacia abajo): ");
		fgets(posIni_i, MAX, stdin);
		
		//Se revisa que la entrada sea la permitida
		while((isdigit(posIni_i[0])==0) || (posIni_i[0] < '0' || (posIni_i[0] > (n-1 + '0')))){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion inicial i de la palabra (de arriba hacia abajo): ");
			fgets(posIni_i, MAX, stdin);
		}
		printf("Ingresa la posicion inicial j de la palabra (de izquierda a derecha): ");
		fgets(posIni_j, MAX, stdin);	
		
		//Se revisa que la entrada sea la permitida
		while(isdigit(posIni_j[0])==0 || (posIni_j[0] < '0' || (posIni_j[0] > (n-1 + '0')))){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion inicial j de la palabra (de izquierda a derecha): ");
			fgets(posIni_j, MAX, stdin);
		}
		
		printf("Ingresa la posicion final i la palabra (de arriba hacia abajo): ");
		fgets(posFin_i, MAX, stdin);
		
		//Se revisa que la entrada sea la permitida
		while(isdigit(posFin_i[0])==0 || posFin_i[0] < '0' || posFin_i[0] > (n-1 + '0')){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion final i de la palabra (de arriba hacia abajo): ");
			fgets(posFin_i, MAX, stdin);
		}
		
		printf("Ingresa la posicion final j la palabra (de izquierda a derecha): ");
		fgets(posFin_j, MAX, stdin);
		
		//Se revisa que la entrada sea la permitida
		while(isdigit(posFin_j[0])==0 || posFin_j[0] < '0' || posFin_j[0] > (n-1 + '0')){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion final j la palabra (de izquierda a derecha): ");
			fgets(posFin_j, MAX, stdin);
		}
		
		printf("Arriba = 1 | Abajo = 2 | Izquierda = 3 | Derecha = 4\n");
		printf("Ingrese la direccion de la palabra: ");
		
		fgets(dir, MAX, stdin);
		while(isdigit(dir[0])==0 || dir[0] < '1' || dir[0] > '6'){
			printf("%c\n", dir[0]);
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingrese la direccion de la palabra: ");
			fgets(dir, MAX, stdin);
		}
		
		printf("Posicion inicial ingresada: [%c][%c]\n", posIni_i[0], posIni_j[0]);
		printf("Posicion final ingresada: [%c][%c]\n", posFin_i[0], posFin_j[0]);

		switch(dir[0]){
			case '1':
				printf("Direccion ingresada: Arriba\n");
				break;
			case '2':
				printf("Direccion ingresada: Abajo\n");
				break;
			case '3':
				printf("Direccion ingresada: Izquierda\n");
				break;
			case '4':
				printf("Direccion ingresasa: Derecha\n");
				break;	
			default:
				break;
		}

		turnos++;
		//variables auxiliares
		int posIni_i_aux = atoi(posIni_i);
		int posIni_j_aux = atoi(posIni_j);
		int posFin_i_aux = atoi(posFin_i);
		int posFin_j_aux = atoi(posFin_j);
		char palabraTemp[60]="";
		obtenerPalabra(posIni_i_aux, posIni_j_aux, posFin_i_aux, posFin_j_aux, dir[0], sopa, n, palabraTemp);
		if(validarPalabra(palabraTemp, listaPalabras, sopa, n, atoi(posIni_i), atoi(posIni_j), atoi (posFin_i), atoi (posFin_j), dir[0])){
			printf("\033[1;32mPalabra ingresada correcta\033[0m\n");
			aciertos++;
		}
		else{
			printf("\033[1;31mPalabra ingresada incorrecta\033[0m\n");
		}
		condicion = verificarPalabras(aciertos, MAX-1);
	}
	
	printf("-------------Fin del juego-------------\n");
	return turnos;
}


int moduloMatriz(char datos[2][1]){
	int largoListaPalabras;  
	//defino la dificultad aqui
	char dif = datos[1][0];
	MAX = largoMatriz(dif);
	struct casilla sopa[MAX][MAX];
	struct string escogidas[MAX-1];
	inicializarMatrix(sopa, MAX);
	GenerarTexto(datos,sopa,escogidas);
	//Jugar devuelve un int con los turnos utilizados
	int turnos = Jugar(sopa, MAX, escogidas, largoListaPalabras);
	printf("turnos finales: %d\n",turnos);
	int flujo = registro(turnos,MAX);
	return flujo;
}
