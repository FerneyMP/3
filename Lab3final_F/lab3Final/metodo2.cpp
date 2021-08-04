#include "metodo2.h"


bool codificacion(int semilla, string nombre, string nombre2)
{
    bool result=true;
    string texto, binario;

    try { //todo el codigo que haga saltar un excepcion


        //leer los datos del archivo y almacenarlo en la variable texto
        texto=leer(nombre, true); //modo de apertura natural (true)
        // convertir el archivo a su equivalente en binario
        binario= conversionTEXT_BIN(texto);
        //reglas de codificacion
        binario=reglas(binario,semilla,true);
        //binario a texto
        texto=binario_a_texto(binario); 
        escribir (texto, nombre2,false);

    }  catch (...) {// sin importar la excepcion pase al mismo codigo (...)
        result=false;
    }

    return result;
}

string codificacionCajero(int semilla, string texto)
{
    string binario;
    // convertir el archivo a su equivalente en binario
    binario= conversionTEXT_BIN(texto);
    //reglas de codificacion
    binario=reglas(binario,semilla,true);
    //binario a texto
    texto=binario_a_texto(binario);
    //se retorna el valor del texto codificado
    return texto;
}


bool decodificacion(int semilla, string nombre, string nombre2)
{
    bool result=true;
    string texto, binario;


    try { //todo el codigo que haga saltar un excepcion


        //leer los datos del archivo y almacenarlo en la variable texto
        texto=leer(nombre, true); //modo de apertura natural (true)
        // convertir el archivo a su equivalente en binario
        binario= conversionTEXT_BIN(texto);
        //reglas de codificacion
        binario=reglas(binario,semilla,false);
        //binario a texto
        texto=binario_a_texto(binario);
        escribir (texto, nombre2,false);

    }  catch (...) {// sin importar la excepcion pase al mismo codigo (...)
        result=false;
    }

    return result;
}

string decodificacionCajero(int semilla, string texto)
{
    string binario;
    //leer los datos del archivo y almacenarlo en la variable texto
    binario= conversionTEXT_BIN(texto);
    //reglas de codificacion
    binario=reglas(binario,semilla,false);
    //binario a texto
    texto=binario_a_texto(binario);
    return texto;
}

string conversionTEXT_BIN(string texto)
{
    string binario,aux;
    //recorrer el string texto
    for (unsigned long long i=0; i<texto.length();i++){
        //para cada una de los caracteres del string debe convertirlo a su equivalente numerico
        // y este a una trama de 8 bits
        aux=conversionINT_BIN(texto[i]);//int
        binario.append(aux); //cada dato se le concatena a binario
    }
    return binario;
}


//conversion a binario, divisiones susesivas entre dos
//evitar problemas con los caracteres mayores a 128 (bit a bit)
string conversionINT_BIN(int letra)
{
     string binario;
     for (int i=0; i<8;i++) binario.push_back(((letra<<i)&0b10000000)/128);
     //a binario se le concatena letra desplazado i veces (hacia la izq una vez )
     //se necesita solo el primer bit, se hace and(&) con el numero 10000000
     //(queda el mismo o puros ceros) (128 o 0) (1 o 0)
     //0b= el numero que sigue esta en binario

     return binario;
}


string reglas(string binario, int semilla, bool c_d)
{
     //partir el binario en bloques peques y luego aplicar reglas
     // semilla: a cuantos bits se les aplica las reglas
     //substr: retorna un string pero entre las dos posiciones que se le marque

    string pedazo,datos;
    for (unsigned long long i=0; i<binario.length();i++){
        //5 grupos de 4 bits dentro del archivo, se debe ejcutar 5 veces
        pedazo.push_back(binario[i]);
        if ((i+1)%semilla==0 || i==binario.length()-1){
            //bloque multiplos enteros o el ultimo bloque
            if (c_d)pedazo=codi_m2(pedazo);
            else pedazo=deco_m2(pedazo);
            datos.append(pedazo);
            pedazo.clear();
        }
    }
    return datos;
}


string codi_m2(string pedazo) //metodo 2
{

    string datos;
    datos.push_back(pedazo[pedazo.length()-1]);
    //a dato se le concatena la ultima posicion de pedazo

    for (unsigned long long i=0; i<pedazo.length()-1;i++){
        //cada bit se desplaza una posicion a la derecha
        //concatenar a datos lo que resta
        datos.push_back(pedazo[i]);
    }
    return datos;
}


string deco_m2(string pedazo) //metodo 2
{
    string datos;
    for (unsigned long long i=0; i<pedazo.length()-1;i++){
        datos.push_back(pedazo[i+1]);
}
    datos.push_back(pedazo[0]);
    return datos;
}


string binario_a_texto(string binario)
{
    string datos, pedazo;
    for (unsigned long long i=0; i<binario.length();i++){
        //partir en pedazos
        pedazo.push_back(binario[i]);
        //todo los caracteres tienes 8 bits
        if ((i+1)%8==0){
            datos.push_back(conv_letra(pedazo));
            pedazo.clear();
    }
  }
  return datos;
}


char conv_letra(string pedazo)
{
    char l=0;
    //recorrer el binario
    for (unsigned long long i=0, j=128; i<pedazo.length();i++,j/=2){
    //multiplicar por potencias de dos
    //128+64+32+16+8+4+2+1
    l+=j*pedazo[i];
    }

    return l;
}


/*
 * string ----- decodificacion
leer el archivo en modo binario
convetir a binario
aplicar las reglas de decodificacion (rotaciones a la izq para obtener el binario decodificado )
    se mueve una unidad a la izq
convertir a archiv de texto
escribir en modo convencional


*/
