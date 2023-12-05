#ifndef GENERARTEXTO_H
#define GENERARTEXTO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include "definedstruct.h"
#include "generartexto.h"
#include "registro.h"

#define max 1

int largoMatriz(char dif);
void rellenaMatrix(struct casilla sopa[][max], int n);
void imprimeMatriz(struct casilla sopa[][max], int n);
void imprimeLista(struct string listaPalabras[max-1], int largoListaPalabras);
void agregarElemento(char palabraEscogida[max], int i, struct casilla sopa[][max], int j, int k);
void obtenerPalabra(int posIni_i, int posIni_j, int posFin_i, int posFin_j, char dir, struct casilla sopa[][max], int n, char palabraEscogida[max]);
void eliminaPalabra(struct string listaPalabras[max-1], char palabraEscogida[max], int i);
void eliminaPalabraMatriz(struct casilla sopa[][max], int n, int posIni_i, int posIni_j, char dir, char palabraEscogida[max]);
bool validarPalabra(char palabraEscogida[max], struct string listaPalabras[max-1], int largoListaPalabras, struct casilla sopa[][max], int n, int posIni_i, int posIni_j, int posFin_i, int posFin_j, char dir);
bool verificarPalabras(int aciertos, int largoListaPalabras);
void arreglarRecibidas(struct string recibidas[max-1]);
int Jugar(struct casilla sopa[][max], int n, struct string listaPalabras[max-1], int largoListaPalabras);
int moduloMatriz(char datos[2][1]);

#endif