#include "archivos.h"


void crear_txt(string name){
    fstream text (name,fstream::out); //abre modo escritura, si no exite  lo crea
    text.close();//cambios reflejados luego de cerrar el archivo y asi acceder a ello
}

void escribir(string texto, string nombre, bool modo)
{
    //clasico // decodificados
    if (modo){ //true ----vizualizar en archivos normales (naturales)
        fstream text (nombre, fstream::out);
        text<<texto;
        text.close();
    }

    //binario--- escribir la informacion codificada en los txt
    else{ //false
        fstream text (nombre, fstream::out |fstream::binary );
        text<<texto;
        text.close();
    }

}

//realizar la lectura del archivo de texto clasico y binario
string leer(string nombre, bool modo)// lectura del archivo de texto
{
    string datos; //datos2 //guardar en datos lo que voy a leer
    fstream text;
    unsigned long long  tam;

    if (modo){
        //nos basamos en el caracter de fin de candena
        text.open (nombre,fstream::in);
        //modo lectura, no se inventa en el archivo, errores de comprobacion
        if (text.is_open()){ //true-abrio
            // terminan con eof
            while(!text.eof())datos.push_back(text.get());
            datos.pop_back(); //elimina el ultimo caracter
        }
        else cout<< "El archivo no pudo ser abierto "   <<endl;
    }

    else{
        //modo binario .dat
        //nos basamos en el tamano (numero de caracteres) del archivo de texto en general y no en oef
        //manejar el cursor de lectura

        text.open (nombre,fstream::in|fstream:: binary|fstream:: ate); //abrimos modo binario y posicionando el cursor al final del .txt
        if  (text.is_open()){
        tam=text.tellg();//posicionado al final del archivo
        text.seekg(0);// devolver el curso de lectura al principio y hacia la derecha

        for (unsigned long long i=0;i<tam;i++)datos.push_back(text.get()); //recorrer internamente el .txt caracter a caracter
        //leer un caracter por caracter (capturar)
        //concatenar caracter a caracter a lo que tengamos en el string
    }
        else cout<< "El archivo no pudo ser abierto "   <<endl;
    }

    text.close();
    return datos;

}


