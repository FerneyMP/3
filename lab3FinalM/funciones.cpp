#include "funciones.h"

void leer_menu()
{
    //Se usa la librería fstream para abrir un archivo en modo lectura..
    fstream menu_ent("menu.txt", fstream::in);
    string datos;
    // Condicional que evalúa si se abre el archivo
    if(menu_ent.is_open()){
        //Ciclo while que recorre todo el archivo linea por linea y la imprime en pantalla
        while(!menu_ent.eof()){
            getline(menu_ent,datos);
            cout << datos << endl;
        }
    }
    else cout << "EL archivo no pudo ser abierto.. :/" << endl;
    //Se cierra el archivo después de haber sido leído
    menu_ent.close();
}


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
        fstream text (nombre, fstream::out |fstream::binary);
        text<<texto;
        text.close();
    }

}
void escribirCajero(string texto, string nombre, bool modo)
{
    //clasico // decodificados
    if (modo){ //true ----vizualizar en archivos normales (naturales)
        fstream text (nombre, fstream::out);
        text<<texto;
        text.close();
    }

    //binario--- escribir la informacion codificada en los txt
    else{ //false
        fstream text (nombre, fstream::out |fstream::binary|fstream::app);
        //|fstream::app
        //seekg una variable ---> del archivo

        text << texto;
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
        datos.pop_back();
    }        
        else cout<< "El archivo no pudo ser abierto "   <<endl;
    }

    text.close();
    return datos;

}

void validar(string NUM, short int modo){
    bool flagg=true;
    bool flag=true;

    if (modo==1){
        while(flagg){
        if (NUM.length()==10){
            flag= ValidarDigitos(NUM,true);
            if (flag==true) {
                flagg=false;
                cout<<"Ingreso de cedula exitoso "<<endl;
            }
             else {
                cout<<"La cedula debe contener unicamente 10 digitos\nIngrese la cedula: ";
                cin >> NUM;
            }
        }
        else {
            cout<<"La cedula debe contener unicamente 10 digitos\nIngrese la cedula: ";
            cin >> NUM;
        }
        }
    }

    if (modo==2){
        while(flagg){
        if (NUM.length()==4){
            flag= ValidarDigitos(NUM,true);
            if (flag==true) {
                flagg=false;
                cout<<"Ingreso de clave exitoso "<<endl;
            }
             else {
                cout<<"La clave debe contener unicamente 4 digitos\nIngrese la clave: ";
                cin >> NUM;
            }
        }
        else {
            cout<<"La clave debe contener unicamente 4 digitos\nIngrese la clave: ";
            cin >> NUM;
        }
        }
    }

    if (modo==3){
        while(flagg){
            flag= ValidarDigitos(NUM,false);
            if (flag==true) {
                cout<<"Ingreso de saldo exitoso "<<endl;
                flagg=false;
            }
             else {
                cout<<"El saldo debe contener unicamente digitos\nIngrese el saldo: ";
                cin >> NUM;
            }
        }
    }
}

bool ValidarDigitos (string numero , bool met){
    if (met){
        bool flag1=true;
        int tam=numero.length();
        for (int i=0;i<tam;i++){
            if(numero[i]<48||numero[i]>57){
                flag1=false;
                break;
            }
        }
        return flag1;
    }
    else{
        bool flag1=true;
        long long int tam=numero.length();
        for (int i=0;i<tam;i++){
            if(numero[i]<48||numero[i]>57){
                flag1=false;
                break;
            }
        }
        return flag1;
    }
};
