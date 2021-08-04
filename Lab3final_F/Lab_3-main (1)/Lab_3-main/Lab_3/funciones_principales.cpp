#include "funciones_principales.h"

//Función tipo entero que proporiona un menú amigable al usuario y retorna una de las opción para el programa.
int menu_entrada()
{
    int funcionalidades;
    cout << "              Bienvenido! " << endl;
    leer_menu();
    cout << "Por favor elija una opcipn: " << endl;
    cout << "1. Codificado " << endl;
    cout << "2. Decodificado " << endl;
    //cout << "Por favor elija una opcipn: " << endl;
    //cout << "Por favor elija una opcipn: " << endl;
    cin >> funcionalidades;
    return funcionalidades;
}


// Función para leer un archivo en específico, dicho archivo imprime en pantalla un menú
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

void escribir(string texto, string nombre, bool modo)
{
    if(modo){
        fstream text(nombre, fstream::out);
        text << texto;
        text.close();
    }
    else{
        fstream text(nombre, fstream::out | fstream::binary);
        text << texto;
        text.close();
    }
}

//Función que recibe un caracter(en su representación ASCII) y lo convierte en número binario
int *Char2bool(char c)
{
    int change;
    int *ptr;
    //int *retorno=new int;  ----> Usar?
    change = int(c); // -> Para convertir el caracter en entero..
    int binario[8]={0,0,0,0,0,0,0,0};
    //For que convierte el caracter ingresado en un número binario mediante divisiones sucesivas
    for(int i=0;i<=7;i++){
        binario[i] = change%2;
        change/=2;
    }

    //Incluir la función que invierte...
    ptr = invertir2binario(binario);
    return ptr;
}

//Función que invierte el arreglo de binarios ..
int *invertir2binario(int b[])
{
    static int invertido[8]={0,0,0,0,0,0,0,0};
    int contador=0;
    //ciclo For que invierte las posciones del número binario
    for(int retorno=7; retorno>=0; retorno--){
        invertido[contador]=b[retorno];
        contador++;
    }
    return invertido;
}

string Char_a_bool(string texto)
{
    string binario, aux;
    for(unsigned long long i=0; i<texto.length(); i++){
        aux = invertir_binario(texto[i]);
        binario.append(aux);
    }
    return binario;
}

//Función que invierte el arreglo de binarios mediante ..
string invertir_binario(char letra)
{
    string binario;
    for(int i=0; i<8; i++){
        binario.push_back(((letra<<i)&0b10000000)/128);
    }
    return binario;
}

char *leer_char(string nombre, bool modo)
{
    //----> FASE 1: Lectura del archivo
    char *ptr;
    char *cadena = nullptr;
    string datos;
    fstream text;
    unsigned long long tamanio;
    if(modo){
        text.open(nombre+".txt", fstream::in);
        if(text.is_open()){
            cout << "\nEl archivo ha sido abierto correctamente.." << endl << endl;
            while(!text.eof()){
                datos.push_back(text.get());
            }
            datos.pop_back();
        }
        else cout << nombre << +".txt no pudo ser abierto, puede que no exista dicho archivo o haya un error de redaccion.." << endl;
    }
    else{
        text.open(nombre, fstream::in | fstream::binary | fstream::ate);
        if(text.is_open()){
            tamanio = text.tellg();
            cadena = new char[tamanio+1];
            cadena[tamanio] = '\0';
            text.seekg(0);
            for(unsigned long long i=0; i<tamanio; i++){
                cadena[i] = text.get();
            }
        }
        else cout << nombre << +".txt no pudo ser abierto, puede que no exista dicho archivo o haya un error de redaccion.." << endl;
    }
    ptr = cadena;
    text.close();
    delete[] cadena;
    return ptr;
}

string leer_string(string nombre, bool modo)
{
    //----> FASE 1: Lectura del archivo
    string datos;
    fstream text;
    unsigned long long tamanio;
    if(modo){
        text.open(nombre+".txt", fstream::in);
        if(text.is_open()){
            cout << "\nEl archivo ha sido abierto correctamente.." << endl << endl;
            while(!text.eof()){
                datos.push_back(text.get());
            }
            datos.pop_back();
        }
        else cout << nombre << +".txt no pudo ser abierto, puede que no exista dicho archivo o haya un error de redaccion.." << endl;
    }
    else{
        text.open(nombre, fstream::in | fstream::binary | fstream::ate);
        if(text.is_open()){
            cout << "\nEl archivo ha sido abierto correctamente.." << endl << endl;
            tamanio = text.tellg();
            text.seekg(0);
            for(unsigned long long i=0; i<tamanio; i++){
                datos.push_back(text.get());
            }
        }
        else cout << nombre << +".txt no pudo ser abierto, puede que no exista dicho archivo o haya un error de redaccion.." << endl;
    }
    text.close();
    return datos;
}



/*

//Función que recibe un número binario y lo convierte en caracter(representación ASCII)
int bool_a_char(int b[])
{
    int potencia=0, acumulador=0, *ptr;
    char resultado;

    // Incluir la función que invierte...
    ptr = invertir_binario(b);

    // Ciclo for que multiplica cada posición del arreglo binario por potencias de 2
    //ascendentemente, además, suma cada posición del arreglo ya multiplicado y le da la
    //representación ASCII del caracter en cuestión
    for(int i=0; i<=7; i++){
        ptr[i]= ptr[i]*pow(2,potencia);
        potencia++;
        acumulador += ptr[i];
    }
    resultado = char(acumulador);
    cout << acumulador << endl;
    cout << resultado << endl;
    return acumulador;
}
*/

