#include "metodo_2.h"


bool decodificacion(int semilla, string nombre, string nombre2)
{
    bool result=true;
    string texto, binario;


    try { //todo el codigo que haga saltar un excepcion


        //leer los datos del archivo y almacenarlo en la variable texto
        texto=leer(nombre, false); //modo de apertura binaria
        // convertir el archivo a su equivalente en binario
        binario= conversionTEXT_BIN(texto);
        //reglas de decodificacion
        binario=reglas(binario,semilla);
        //binario a texto
        texto=binario_a_texto(binario);
        //escribir el texto ya decodificado (guardar en archivo natural)
        escribir (texto, nombre2,true);

    }  catch (...) {// sin importar la excepcion pase al mismo codigo (...)
        result=false;
    }

    return result;
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


string reglas(string binario, int semilla)
{
     //partir el binario en bloques peques y luego aplicar reglas
     // semilla: a cuantos bits se les aplica las reglas
     //substr: retorna un string pero entre las dos posiciones que se le marque

    string pedazo,datos;
    for (unsigned long long i=0; i<binario.length();i++){
        pedazo.push_back(binario[i]);
        if ((i+1)%semilla==0 || i==binario.length()-1){
            //bloque multiplos enteros o el ultimo bloque
            pedazo=m2(pedazo);
            datos.append(pedazo);
            pedazo.clear();
        }
    }
    return datos;
}


string m2(string pedazo) //metodo 2
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


