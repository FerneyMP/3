#ifndef METODO1_H
#define METODO1_H

#include "funciones.h"
unsigned long long size_text(const char *name);
bool codifica_M1(char *archivo_1, char *archivo_2m, int n);
void read_text(const char *name,char *text, unsigned long long tam);
void text2bin(char *text, char *bin, unsigned long long tam);
//Funciones para Aplicar las reglas
void escribir(char *nombre, char *datos, unsigned long long int tamano, bool tipo);
void metodo_1(char *bin, int semilla, unsigned long long tam);
unsigned int reglas(char *pedazo, int semilla, unsigned int cantidad);
void bin2text(char *binario, char *text, unsigned long long tam);
char bloque2char(char *pedazo);

#endif // METODO1_H
