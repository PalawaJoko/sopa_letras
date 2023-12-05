#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definedstruct.h"
#include "generartexto.h"

int TAMAÑO_MATRIZ;
int numeroPalabras;


//rellena aleatoriamente un arreglo de ints
void rellenarAleatorios(int *arreglo,int tamaño, int tope){
	for(int i =0; i<tamaño; i++){
		arreglo[i] = rand() %tope;
	}
	arreglo[tamaño-1]=arreglo[tamaño-1]-1;
}
//funcion que ver el largo de una palabra contenida en un array char de largo 60
int largoPalabra(char palabra[60]){
	int contador = 0;
	while(palabra[contador]!='\n'){
		contador++;
	}
	return contador-1;
}
//funcion que seleccionar, de for,a aleatoria, palabras para la sopa de letras
void seleccionarPalabras(struct string escogidas[], char ruta[100], int numeroPalabras, int tope){
	struct string almacen[16];
	char capturado[60];
	int contador = 0;
	//Abro el archivo y guardo sus datos en una array de char
	FILE *archivo;
	archivo = fopen(ruta,"rt");
	while(feof(archivo)!=1){
		fgets(capturado,60,archivo);
		strcpy(almacen[contador].dato,capturado);
		contador++;
	}
	fclose(archivo);
	//creo un arreglo de numeros aleatorios
	int *arregloAleatorio = (int*)malloc(sizeof(int)*numeroPalabras);
	rellenarAleatorios(arregloAleatorio,numeroPalabras,tope);
	//Escogo una palabra del almacen usando un indexado aleatorio
	for(int i = 0; i<numeroPalabras; i++){
		int numero = arregloAleatorio[i];
		char palabra[60];
		//guardo la palabra escogida al azar
		strcpy(palabra,almacen[numero].dato);
		//la asigno las palabras escogidas finales
		strcpy(escogidas[i].dato,palabra);
	}
}
//colocar palabras en 4 direcciones
bool ponerHorizontalD(char recibido[60],struct casilla sopa[TAMAÑO_MATRIZ][TAMAÑO_MATRIZ], int fila, int columna){
	int largo = largoPalabra(recibido);
	char palabra[largo];
	int contador = 0;
	while(recibido[contador]!='\n'){
		palabra[contador]=recibido[contador];
		contador++;
	}
	if((TAMAÑO_MATRIZ-columna)<largo){
		return false;
	}
	contador = 0;
	while(contador<largo){
		if(sopa[fila][columna+contador].ocupado==false){
			sopa[fila][columna+contador].dato[0]=palabra[contador];
			sopa[fila][columna+contador].ocupado=true;
			contador++;
		}else{
			if(sopa[fila][columna+contador].dato[0]==palabra[contador]&&sopa[fila][columna+contador].dato[0]!=' '){
				sopa[fila][columna+contador].dato[0]=palabra[contador];
				contador++;
			}else{
				return false;
			}
		}
	}
	return true;
}

bool ponerHorizontalI(char recibido[60],struct casilla sopa[TAMAÑO_MATRIZ][TAMAÑO_MATRIZ], int fila, int columna){
	int largo = largoPalabra(recibido);
	char palabra[largo];
	int contador = 0;
	while(recibido[contador]!='\n'){
		palabra[contador]=recibido[contador];
		contador++;
	}
	if(TAMAÑO_MATRIZ-(TAMAÑO_MATRIZ-columna)<largo){
		return false;
	}
	contador = 0;
	while(contador<largo){
		if(sopa[fila][columna-contador].ocupado==false){
			sopa[fila][columna-contador].dato[0]=palabra[contador];
			sopa[fila][columna-contador].ocupado=true;
			contador++;
		}else{
			if(sopa[fila][columna-contador].dato[0]==palabra[contador]&&sopa[fila][columna+contador].dato[0]!='a'){
				sopa[fila][columna-contador].dato[0]=palabra[contador];
				contador++;
			}else{
				return false;
			}
		}
	}
	return true;
}

bool ponerVerticalInf(char recibido[60],struct casilla sopa[][TAMAÑO_MATRIZ], int fila, int columna){
	int largo = largoPalabra(recibido);
	char palabra[largo];
	int contador = 0;
	while(recibido[contador]!='\n'){
		palabra[contador]=recibido[contador];
		contador++;
	}
	if((TAMAÑO_MATRIZ-fila)<largo){
		return false;
	}
	contador = 0;
	while(contador<largo){
		if(sopa[fila+contador][columna].ocupado==false){
			sopa[fila+contador][columna].dato[0]=palabra[contador];
			sopa[fila+contador][columna].ocupado=true;
			contador++;
		}else{
			if(sopa[fila+contador][columna].dato[0]==palabra[contador]&&sopa[fila+contador][columna].dato[0]!=' '){
				sopa[fila+contador][columna].dato[0]=palabra[contador];
				contador++;
			}else{
				return false;
			}
		}
	}
	return true;
}

bool ponerVerticalSup(char recibido[60],struct casilla sopa[][TAMAÑO_MATRIZ], int fila, int columna){
	int largo = largoPalabra(recibido);
	char palabra[largo];
	int contador = 0;
	while(recibido[contador]!='\n'){
		palabra[contador]=recibido[contador];
		contador++;
	}
	if((TAMAÑO_MATRIZ-(TAMAÑO_MATRIZ-fila))<largo){
		return false;
	}
	contador = 0;
	while(contador<largo){
		if(sopa[fila-contador][columna].ocupado==false){
			sopa[fila-contador][columna].dato[0]=palabra[contador];
			sopa[fila-contador][columna].ocupado=true;
			contador++;
		}else{
			if(sopa[fila-contador][columna].dato[0]==palabra[contador]&&sopa[fila+contador][columna].dato[0]!=' '){
				sopa[fila-contador][columna].dato[0]=palabra[contador];
				contador++;
			}else{
				return false;
			}
		}
	}
	return true;
}
//funcion que devuelve true si se pudo poner la palabra en alguna de las 4 direcciones
bool ponerPalabra(char recibido[60],struct casilla sopa[][TAMAÑO_MATRIZ], int fila, int columna){
	bool colocado;
	if(colocado = ponerHorizontalD(recibido,sopa,fila,columna)==false){
		if(colocado = ponerHorizontalI(recibido,sopa,fila,columna)==false){
			if(colocado = ponerVerticalInf(recibido,sopa,fila,columna)==false){
				if(colocado = ponerVerticalSup(recibido,sopa,fila,columna)==false){
					return false;
				}
			}
		}
	}
	return true;
}
//funcion que coloca palabras en la sopa, haciendo uso de ponerPalabra como recurso
void colocarPalabras(struct string escogidas[],struct casilla sopa[][TAMAÑO_MATRIZ],int numeroPalabras){
	int fila[numeroPalabras],columna[numeroPalabras];
	rellenarAleatorios(fila,numeroPalabras,TAMAÑO_MATRIZ);
	rellenarAleatorios(columna,numeroPalabras,TAMAÑO_MATRIZ);
	for(int i=0; i<numeroPalabras;i++){
		bool colocado = false;
		if(ponerPalabra(escogidas[i].dato,sopa,fila[i],columna[i])==false){
			int contador = 1;
			while(colocado!=true){
				int f,c;
				f= fila[i]+contador;
				c= columna[i]+contador;
				colocado = ponerPalabra(escogidas[i].dato,sopa,f-1,c);
				if(colocado==false){
					colocado = ponerPalabra(escogidas[i].dato,sopa,fila[f],c);
				}
				contador++;
			}
		}
	}
}
//funcion que rellena la sopa con letras aleatorias
void rellenarLetrasAleatorias(struct casilla sopa[][TAMAÑO_MATRIZ]){
	char listaLetras[27]="abcdeaghijelmnopqrstuvwioz";
	for(int i=0; i<TAMAÑO_MATRIZ; i++){
		for(int j=0; j<TAMAÑO_MATRIZ; j++){
			int random = rand()%26;
			if(sopa[i][j].ocupado==false){
				sopa[i][j].dato[0]=listaLetras[random];
				sopa[i][j].ocupado=true;
			}
		}
	}
}
//funcion que reemplaza las palabras repetidas por otras
void arreglarEscogidas(struct string escogidas[],char tema, int numeroPalabras){
	int contador = 0;
	char *almacenA[5]= {"leon\n","cerdo\n","perro\n","vaca\n","huemul\n"};
	char *almacenH[5]= {"nido\n","sofa\n","sillon\n","techo\n","cama\n"};
	char *almacenC[5]= {"res\n","maiz\n","mole\n","trigo\n","fideo\n"};
	//reemplazo de palabras
	for(int i =0; i<numeroPalabras; i++){
		for(int j=i; j<numeroPalabras; j++){
			if(strcmp(escogidas[i].dato,escogidas[j].dato)==0 && i!=j){
				if(tema == 'A'){
					strcpy(escogidas[j].dato,almacenA[contador]);
					contador++;
				}
				if(tema == 'H'){
					strcpy(escogidas[j].dato,almacenH[contador]);
					contador++;
				}
				if(tema == 'C'){
					strcpy(escogidas[j].dato,almacenC[contador]);
					contador++;
				}
			}
		}
	}
}
//funcion principal del Modulo, recibe el tema, la dificultad, rellena la sopa de letras y devuelve la lista de palabras utilizadas
void GenerarTexto(char datos[2][1],struct casilla sopa[TAMAÑO_MATRIZ][TAMAÑO_MATRIZ],struct string escogidas[TAMAÑO_MATRIZ-1]){
	char tema = datos[0][0];
	char dificultad = datos[1][0];
	char ruta[100];
	int tope;
	//buscamos la ruta del archivo donde estan las palabras
	switch(tema){
		case 'A':
			char caminoa[100]="Animales.txt";
			strcpy(ruta,caminoa);
			break;
		case 'H':
			char caminoh[100]="Hogar.txt";
			strcpy(ruta,caminoh);
			break;
		case 'C':
			char caminoc[100]="Comida.txt";
			strcpy(ruta,caminoc);
			break;
	}
	//vemos cuantas palabras elegir
	switch(dificultad){
		case 'F':
			numeroPalabras=5;
			tope = 7;
			TAMAÑO_MATRIZ = 6;
			if(tema=='H'){
				tope = 6;
			}
			break;
		case 'M':
			numeroPalabras=7;
			tope = 13;
			TAMAÑO_MATRIZ = 8;
			break;
		case 'D':
			numeroPalabras=9;
			tope = 16;
			TAMAÑO_MATRIZ = 10;
			break;
	}
	//creo un arreglo para capturar todas las palabras del texto
	seleccionarPalabras(escogidas,ruta,numeroPalabras,tope);
	arreglarEscogidas(escogidas,tema,numeroPalabras);
	colocarPalabras(escogidas,sopa,numeroPalabras);
	rellenarLetrasAleatorias(sopa);
}
