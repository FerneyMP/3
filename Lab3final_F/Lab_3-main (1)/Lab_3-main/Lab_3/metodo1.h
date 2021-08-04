#ifndef METODO1_H
#define METODO1_H
#include "funciones_principales.h"

void leer_archivo(string name);
void conversion_metodo1(int semilla, string n_archivo, string n_archivo2);
void escribir_archivo();

//idea: función que cuenta la cantidad de ceros y unos dentro del archivo binario ..
void ceros_unos_count(int semilla, char cadena[], int &ceros, int &unos);
#endif // METODO1_H
