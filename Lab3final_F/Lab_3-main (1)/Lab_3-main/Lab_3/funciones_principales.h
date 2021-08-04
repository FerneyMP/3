#ifndef FUNCIONES_PRINCIPALES_H
#define FUNCIONES_PRINCIPALES_H
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int menu_entrada();

void leer_menu();

//idea: función que crea un archivo txt y codifica la información ... aún por desarrollar.
void creacion_codificado();

//idea: función para convertir un caracter(representación ASCII) a un número binario ...
//Método 1
int *Char2bool(char c);
//Método 2
string Char_a_bool(string texto);

//idea: función que invierte las posiciones de un arreglo binario
//Método 1
int *invertir2binario(int b[]);
//Método 2
string invertir_binario(char letra);

//idea: función para convertir un número binario a un caracter(representación ASCII)..
//Método 1
int bool_a_char(int b[]);


void escribir(string texto, string nombre, bool modo);

char *leer_char(string nombre, bool modo);

string leer_string(string nombre, bool modo);

#endif // FUNCIONES_PRINCIPALES_H
