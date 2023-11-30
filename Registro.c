//para ejecutar el archivo: gcc -o Registro Registro.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Abre el archivo en modo de lectura, comprueba si existe y muestra su contenido en la consola.
void VerArchivo() {
    FILE *archivo;
    char caracter;

    archivo = fopen("highscore.txt", "r"); // Abre el archivo highscore.txt en modo de lectura
    if (archivo == NULL) {
        printf("No hay puntuaciones registradas\n"); // Imprime un mensaje si el archivo no existe, creando el archivo por primera vez
    } else {
        printf("Las mejores puntuaciones son:\n");
        while ((caracter = fgetc(archivo)) != EOF) { //Ciclo que imprime cada caracter en la consola hasta que alcanza el final del archivo.
            printf("%c", caracter);
        }
        fclose(archivo); // Cierra el archivo después de leerlo
    }
}

//Abre el archivo, solicita al usuario que ingrese su nombre en 3 caracteres y luego lo guarda en el archivo.
void IngresarNombre() {
    FILE *archivo;
    char nombre[4];
    char caracter;
    int i = 0;

    archivo = fopen("highscore.txt", "a"); // Abre el archivo highscore.txt en modo "append"
    printf("\nIntroduce tu nombre (solo 3 caracteres, no números):\n");

    while (i < 3) { //ciclo while para registrar cada carácter e identificar si el usuario escribió un char
        caracter = getchar();

        // Verifica si el carácter no es un número y es una letra
        if (!isdigit(caracter) && isalpha(caracter)) {
            nombre[i++] = caracter;
        } else {
            printf("\nCarácter/es no válido/s. \nIntroduce solo letras y asegúrate de que el nombre tenga 3 caracteres:\n");
            while ((caracter = getchar()) != '\n'); // Limpia el buffer de entrada
            i = 0; // Reinicia la posición del nombre
            printf("\nIntroduce tu nombre (solo 3 caracteres, no números):\n");
        }
    }

    nombre[i] = ' '; // Agrega un espaciador que separará el nombre con su puntuación.

    printf("Tu nombre es: %s\n",nombre);
    fprintf(archivo, "%s", nombre); // Escribe el nombre registrado en el archivo highscore.txt 
    fclose(archivo); // Cierra el archivo después de escribir
}

//Calcula una puntuación en función de una exponencial y la guarda en el archivo.
void CalculadoraPuntaje(int turno, int dificultad) {

    // Abre el archivo en modo "a" (append)
    FILE *archivo = fopen("highscore.txt", "a");

    double puntuacion; //defino la puntuación de tipo double

    if (turno == dificultad) { 
        puntuacion = 1000; // Caso cuando el usuario acierte todas las palabras sin un turno adicional
    } else {
        puntuacion = 1000 * exp(-(turno / 11.0)); // Caso cuando el usuario tenga uno o más turnos adicionales 
    }

    // Escribe la puntuación en el archivo
    fprintf(archivo, "%.1f\n", puntuacion);

    // Cierra el archivo
    fclose(archivo);
}

void ComparacionPuntajes() {
    FILE *archivo = fopen("highscore.txt", "r");
    double puntajes[5]; // Defino la lista con los 5 mejores puntajes
    /*Array bidimensional para almacenar los tres caracteres del nombre 
    y los inscritos en el archivo highscore.txt*/
    char nombres[5][4];  
    int aux = 0;

    // Envío el puntero al principio del archivo
    fseek(archivo, 0, SEEK_SET);

    // Ciclo para lectura de puntajes y nombres del archivo
    while (aux < 5 && fscanf(archivo, "%3s %lf", nombres[aux], &puntajes[aux]) == 2) {
        aux++;
    }

    // Cierra el archivo
    fclose(archivo);

    // Ciclo for para ordenar los puntajes de manera descendente
    for (int i = 0; i < aux; i++) {
        for (int j = i + 1; j < aux; j++) {
            if (puntajes[i] < puntajes[j]) {
                // Intercambio de puntajes[i] y puntajes[j]
                double temp = puntajes[i];
                puntajes[i] = puntajes[j];
                puntajes[j] = temp;

                // Intercambio de nombres[i] y nombres[j]
                char temp_nombre[4];
                strcpy(temp_nombre, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], temp_nombre);
            }
        }
    }

    // Eliminar el sexto peor puntaje si es que hay al menos seis puntajes
    if (aux >= 6) {
        puntajes[5] = 0; // Elimino el sexto puntaje
    }

    // Abrir el archivo en modo de escritura para sobrescribir el contenido
    archivo = fopen("highscore.txt", "w");

    // Escribir los puntajes ordenados en el archivo
    for (int i = 0; i < aux; i++) {
        fprintf(archivo, "%s %.1f\n", nombres[i], puntajes[i]);
    }

    // Cerrar el archivo después de escribir
    fclose(archivo);
}

int main() { //Ejecutar funciones anteriores
    VerArchivo();
    IngresarNombre();
    FuncionDeTurnos(1, 1); // Ejemplo de prueba
    ComparacionPuntajes();
    return 0;
}
