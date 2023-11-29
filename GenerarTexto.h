#ifndef GENERARTEXTO_H
#define GENERARTEXTO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct string{
    char dato[60];
};

struct casilla{
    char dato[60];
    bool ocupado;
};

//rellena aleatoriamente un arreglo de ints
void rellenarAleatorios(int *arreglo,int tamaño, int tope);
//funcion que ver el largo de una palabra contenida en un array char de largo 60
int largoPalabra(char palabra[60]);
//funcion que seleccionar, de for,a aleatoria, palabras para la sopa de letras
void seleccionarPalabras(struct string escogidas[], char ruta[100], int numeroPalabras, int tope);
//colocar palabras en 4 direcciones
bool ponerHorizontalD(char recibido[60],struct casilla sopa[TAMAÑO_MATRIZ][TAMAÑO_MATRIZ], int fila, int columna);
bool ponerHorizontalI(char recibido[60],struct casilla sopa[TAMAÑO_MATRIZ][TAMAÑO_MATRIZ], int fila, int columna);
bool ponerVerticalInf(char recibido[60],struct casilla sopa[][TAMAÑO_MATRIZ], int fila, int columna);
bool ponerVerticalSup(char recibido[60],struct casilla sopa[][TAMAÑO_MATRIZ], int fila, int columna);
//funcion que devuelve true si se pudo poner la palabra en alguna de las 4 direcciones
bool ponerPalabra(char recibido[60],struct casilla sopa[][TAMAÑO_MATRIZ], int fila, int columna);
//funcion que coloca palabras en la sopa, haciendo uso de ponerPalabra como recurso
void colocarPalabras(struct string escogidas[],struct casilla sopa[][TAMAÑO_MATRIZ],int numeroPalabras);
//funcion que rellena la sopa con letras aleatorias
void rellenarLetrasAleatorias(struct casilla sopa[][TAMAÑO_MATRIZ]);
//funcion que reemplaza las palabras repetidas por otras
void arreglarEscogidas(struct string escogidas[],char tema, int numeroPalabras);

void generarTexto(char datos[][1],struct casilla sopa[TAMAÑO_MATRIZ][TAMAÑO_MATRIZ],struct string escogidas[numeroPalabras]);

#endif
