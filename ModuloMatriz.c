#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX 10

//Datos de entrada de ejemplo

char Datos[2]= {'A', 'D'};

struct casilla{
	char Letra;
	bool ocupado;
	};	

//Se define el largo de la matriz a partir de la dificultad

int largoMatriz(char dif){

	switch(dif){
		case 'F':
			return 5;	
			break;
		case 'M':
			return 7;
			break;
		case 'D':
			return 9;
			break;

	}
}

void rellenaMatrix(struct casilla sopa[][MAX], int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n; j++){
		
			sopa[i][j].Letra = 'A';
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
			printf("[%c]", sopa[i][j].Letra);
			
		}
    	printf("\n");
    }

}
//Funcion que permite imprimir en pantalla la lista de palabras
void imprimeLista(char listaPalabras[MAX][MAX], int n){
	printf("Palabras a buscar: \n");
	printf("[");
	for(int i=0;i<(n-1);i++){
		
		printf("%s, ", listaPalabras[i]);

	}
	printf("%s] \n", listaPalabras[n-1]);
}

//Agrega elementos a un arreglo
void agregarElemento(char palabraEscogida[MAX], int i, struct casilla sopa[][MAX], int j, int k){
	palabraEscogida[i] = sopa[j][k].Letra;
	printf("agregarElemento\n");
	printf("%c\n", palabraEscogida[i]);
}

//Corrobora que las palabra ingresada pertenezca a la lista (*por terminar*)
void validarPalabras(int posIni_i, int posIni_j, int posFin_i, int posFin_j, char dir, struct casilla sopa[][MAX]){

	/*char palabraEscogida[MAX];
	printf("HOlA\n");
	printf("%d", posIni_i);

	for(int i = 0; i<MAX; i++){
		agregarElemento(palabraEscogida, i, sopa, posIni_i, posIni_j);
		if(dir=='1'){
			posIni_i--;
			if(posIni_i==posFin_i){
				break;
			}
		}
		if(dir=='2'){
			posIni_i++;
			if(posIni_i==posFin_i){
				break;
			}
		}
		if(dir=='3'){
			posIni_i--;
			posIni_j++;
			if(posIni_i==posFin_j ){
				break;
			}
		}
		if(dir=='1'){
			posIni_i--;
			if(posIni_i==posFin_j){
				break;
			}
		}
		if(dir=='1'){
			posIni_i--;
			if(posIni_i==posFin_j){
				break;
			}
		}
		if(dir=='1'){
			posIni_i--;
			if(posIni_i==posFin_j){
				break;
			}
		}
		if(dir=='1'){
			posIni_i--;
			if(posIni_i==posFin_j){
				break;
			}
		}

		printf("HOLA\n");
	}
	printf("%s\n", palabraEscogida);
*/
}

//Verifica que aun queden palabras por buscar (*por terminar*)
bool verificarPalabras(char Palabras[MAX][MAX], int n){
	if(Palabras[0]==Palabras[n-1]){
		return false;
	}
	else{
		return true;
	}
}

//Funcion que permite la interaccion con el usuario (*por terminar*)
//Jugar(Matriz principal, largo de la matriz, listado de palabras)
void Jugar(struct casilla sopa[][MAX], int n, char listaPalabras[MAX][MAX]){
	int turnos = 0;
	while(verificarPalabras(listaPalabras, 5)){
		char posIni_i[MAX];
		char posIni_j[MAX];
		char posFin_i[MAX];
		char posFin_j[MAX];
		char dir[MAX];
		printf("Turnos utilizados = %d\n", turnos);
		
		//Preguntamos por la posicion inicial y final de la palabra, además de la direccion
		printf("Ingresa la posicion inicial i de la palabra: ");
		fgets(posIni_i, MAX, stdin);
		
		//Se revisa que la entrada sea la permitida
		while((isdigit(posIni_i[0])==0) || (posIni_i[0] < '0' || (posIni_i[0] > (n-1 + '0')))){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion inicial i de la palabra: ");
			fgets(posIni_i, MAX, stdin);
		}
		printf("Ingresa la posicion inicial j de la palabra: ");
		fgets(posIni_j, MAX, stdin);	
		
		//Se revisa que la entrada sea la permitida
		while(isdigit(posIni_j[0])==0 || (posIni_j[0] < '0' || (posIni_j[0] > (n-1 + '0')))){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion inicial j de la palabra: ");
			fgets(posIni_j, MAX, stdin);
		}
		
		printf("Ingresa la posicion final i la palabra: ");
		fgets(posFin_i, MAX, stdin);
		
		//Se revisa que la entrada sea la permitida
		while(isdigit(posFin_i[0])==0 || posFin_i[0] < '0' || posFin_i[0] > (n-1 + '0')){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion final i de la palabra: ");
			fgets(posFin_i, MAX, stdin);
		}
		
		printf("Ingresa la posicion final j la palabra: ");
		fgets(posFin_j, MAX, stdin);
		
		//Se revisa que la entrada sea la permitida
		while(isdigit(posFin_j[0])==0 || posFin_j[0] < '0' || posFin_j[0] > (n-1 + '0')){
			printf("Entrada incorrecta, Vuelve a intentarlo \n");
			printf("Ingresa la posicion final j la palabra: ");
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

		scanf("%c", posIni_i);
		turnos++;
		validarPalabras(atoi(posIni_i),atoi(posIni_j), atoi (posFin_i), atoi (posFin_j), dir[0], sopa);
	
	}
}

void main(){
	
	//lista de ejemplo
	char listaPalabras[5][MAX] = {"ciervo", "elefante", "caballo", "perro", "gato"};
	int n;	
	char dif = Datos[1];
	n = largoMatriz(dif);
	struct casilla sopa[n][n];
	rellenaMatrix(sopa, n);
	imprimeLista(listaPalabras, 5);
	imprimeMatriz(sopa, n);
	Jugar(sopa, n, listaPalabras);
}
