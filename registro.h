#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int VerArchivo();
void IngresarNombre();
void CalculadoraPuntaje(int turno, int dificultad);
void ComparacionPuntajes();
int seguirJugando();
int registro(int turnos, int dificultad);

#endif