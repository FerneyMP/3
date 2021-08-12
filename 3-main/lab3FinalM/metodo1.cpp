#include "metodo1.h"
unsigned long long size_text(const char *name)
{
    fstream txt;
    unsigned long long tam=0;

    txt.open(name,fstream::in | fstream::ate | fstream::binary);
    if(txt.is_open()) tam=txt.tellg();
    txt.close();
    return tam;
}

void read_text(const char *name, char *text, unsigned long long tam)
{
    fstream txt;

    txt.open(name,fstream::in | fstream::binary);
    if(txt.is_open()) txt.read(text,tam-1);
    txt.close();
}

bool codifica_M1(char *archivo_1, char *archivo_2, int semilla)
{
    unsigned long long tam;
    char *txt, *bin;
    //bool band = true;
    tam=size_text(archivo_1); //Tamaño del archivo

    try {
        txt = new char[tam];
        bin = new char[8*tam];

        read_text(archivo_1,txt,tam);
        text2bin(txt,bin,tam);
        metodo_1(bin, semilla, 8*tam);
        bin2text(bin,txt,tam);
        escribir(archivo_2, txt, tam, false);

        delete bin;
        delete txt;
    } catch (...) {
        cout << "No se puede asignar tanta memoria, texto muy largo" << endl;
    }
    return true;
}

void text2bin(char *text, char *bin, unsigned long long tam)
{
    for(unsigned long long i=0; i<tam-1; i++){
        for(short j=0; j<8; j++) bin[8*i+j]=(((text[i]<<j)&0b10000000)/128)+48;
    }
    //bin[8*tam] = '\0';
}

void metodo_1(char *bin, int semilla, unsigned long long tam)
{
    char *pedazo;
    unsigned int unos;
    pedazo = new char [semilla+1];
    pedazo[semilla]='\0';
    for (unsigned long long i=0, j=0, bloques=0; i<tam; i++, j++){
        pedazo[j]= bin[i];
        if ((i+1)%semilla==0 || i==tam-1){
            unos = reglas(pedazo, semilla, unos);
            j=-1;
            for(int k=0; k<semilla;k++){
                if(pedazo[k]!=-1) bin[semilla*bloques+k] = char (pedazo[k]+48);
                pedazo[k]=-1;
            }
            bloques++;
        }
    }
    delete pedazo;
}

unsigned int reglas(char *pedazo, int semilla, unsigned int cantidad)
{
    static bool band= true;
    unsigned int unos= 0;
    if(band || semilla -cantidad == cantidad ){
        for(int i=0; i<semilla; i++){
            unos+=pedazo[i];
            if(pedazo[i]!=-1) pedazo[i] = 1-pedazo[1];
      }
        band = false;
    }
    else if (semilla - cantidad > cantidad){
        for(int i=0; i<semilla; i++){
            unos+=pedazo[i];
            if(i%2==1 && pedazo[i]!=-1) pedazo[i] = 1-pedazo[1];
        }
    }
    else{
        for(int i=0; i<semilla; i++){
            unos+=pedazo[i];
            if((i+1)%3==1 && pedazo[i]!=-1) pedazo[i] = 1-pedazo[1];
        }
    }
    return unos;
}
void bin2text(char *binario, char *text, unsigned long long tam)
{
    char *pedazo;
    pedazo = new char [9];
    pedazo[8]='\0';
    for(unsigned long long i=0, j=0, k=0; i<8*tam; i++, j++){
        pedazo[j] = binario[i];
        if((i+1)%8==0){
                text[k] = bloque2char(pedazo);
                k++;
                j=-1;
        }
    }
    delete pedazo;
}

char bloque2char(char *pedazo)
{
    int k=128, l=0;

    for(int i=0; i<=7; i++, k/=2) l+=pedazo[i]*k;
    return char(l);
}

void escribir(char *nombre, char *datos, unsigned long long int tamano, bool tipo){
    fstream text;
    if(tipo){
        text.open(nombre, fstream::out);
        text << datos;
    }
    else{
        text.open(nombre, fstream::out | fstream::binary);
        text.write(datos, tamano);
    }
    text.close();
}
