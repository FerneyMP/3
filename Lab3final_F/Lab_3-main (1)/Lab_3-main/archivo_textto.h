#ifndef ARCHIVO_TEXTTO_H
#define ARCHIVO_TEXTTO_H
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int menu_entrada();
void leer_menu();

//idea: función que crea un archivo txt y codifica la información ... aún por desarrollar.
void creacion_codificado();

//idea: función para convertir un caracter(representación ASCII) a un número binario ... preguntar si está correcto...
int *Char_a_bool(char c);

//idea: función que invierte las posiciones de un arreglo binario
int *invertir_binario(int b[]);

//idea: función para convertir un número binario a un caracter(representación ASCII)..
int bool_a_char(int b[]);

//seguir desarollando los prototipos hacia abajo ..
// ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

//Funciones para el primer método (caracter):
// En leer archivo se convierte e invierte de caracter a binario, luego, en conversión se toma el archivo modificado en
// leer archivo y se codifica, ambas funciones son necesarias para el primer método de codificación
void leer_archivo(string name);
void conversion_metodo1();

//idea: función que cuenta la cantidad de ceros y unos dentro del archivo binario ..
void ceros_unos_count(int semilla, char cadena[], int &ceros, int &unos);


#endif // ARCHIVO_TEXTTO_H
