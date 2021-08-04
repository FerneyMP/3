#include "funciones.h"

bool val(string usuario, string clave)
{
    string aux;
    if (usuario=="administrador"){
        aux= decodificar(semilla,"sudo.txt");
        if (aux==clave) return true;
        else return false;
    }
    else{
        aux= decodificar(semilla,"usuario.dat");


    }



}
