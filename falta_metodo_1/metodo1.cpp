#include "funciones.h"
#include "metodo1.h"

unsigned long long size_text(const char *name)
{
    fstream txt; //objeto fstream
    unsigned long long tam=0;
    txt.open(name,fstream::in | fstream ::ate| fstream ::binary);//modo lectura y ate: posiciona el cursor al final del archivo
    //comprobar que se abrio
    if (txt.is_open())tam=txt.tellg(); //posicion del cursor=tamaño del archivo
    txt.close();
    return tam;
}

//funcion para codificar
bool code_decode(const char *read, const char *write, unsigned int n, bool method)
{
    unsigned long long tam=0;
    char *txt, *binario; //el binario podia ser cualquier tipo de vaiable
    bool band=true;

    tam=size_text(read);
    try {
        txt=new char [tam];
        binario=new char [8*tam];
        read_text(read,txt,tam);
        text2bin (txt,binario,tam);
        //for (int i=0; i<8*tam;i++) cout<<binario[i];
        //cout<<endl;

        delete[] binario;
        delete [] txt;

    }  catch (...) {
        cout<<"No se puede asignar tanta memoria :c"<<endl;
    }
    return band;
}

void read_text(const char *name, char *text, unsigned long long tam)
{
    fstream txt;
    txt.open(name,fstream::in | fstream ::binary);//modo lectura y ate: posiciona el cursor al final del archivo
    if (txt.is_open()){
        //read: guardar en un puntero de chars una cantidad de caracteres
        //modificar por referencia
        txt.read(text,tam);
    }
    txt.close();

}

void text2bin(char *text, char *bin, unsigned long long tam)
{
    for(unsigned long long i=0; i<tam; i++){ // recorrer todo el archivo y asi acceder mediante text[i] a una letra especifica, luego un for para convertirlo en binario de 8 cifas
        for (short j=0; j<8; j++){ //para cada una de las letras se genera un  binario

            /*PASAR DE MEMORIA A UN ARREGLO
            operadore bit a bit al principio, operadores de procesadores, a nivel de maquina, juega con la representacion en binario que se encuentra en binario
            desplazamientos logicos: corrimiento de toda la trama de bits en alguna direccion (izq<< der>>) se llena con cero
            and&: operacion logica entre los bits de 2 elementos del mismo tamaño 1&1=1, (mem&128)/128 da cero o 1
            */

            bin[8*i+j]=(((text[i]<<j&0b10000000))/128)+48; //cada que se pase de letra se esta guardando 8 posiciones despues
            //0b: binario puro
            //para visualizar los numeros se le +48, para guardar la representacion del numero en ascii
        }
    }
}


//afecta el complemento a2: representa numeros negativos y positivos, 1=-#

