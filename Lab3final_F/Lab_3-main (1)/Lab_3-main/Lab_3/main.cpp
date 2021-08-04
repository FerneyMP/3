#include "funciones_principales.h"
#include "metodo1.h"
#include "metodo2.h"

int main()
{

    //Pruebas de conversión de char a bool
    /*
    char c = 'h';
    int *a;
    a=Char_a_bool(c);
    for(int u=0;u<=7;u++) cout << *(a+u) << endl;
    // Fin de prueba.. FUNCIONA

    //Pruebas de conversión de bool a entero

    int b[8]={0,1,1,0,1,1,1,1};
    bool_a_char(b);
    */
    // Finde prueba .. FUNCIONA


    //Ejecución de prueba función leer_archivo ..

    string archivo;
    cout << "Escriba el nombre del archivo: "; cin >> archivo;
    leer_char(archivo, false);
    //leer(archivo)
    //leer_archivo(archivo);
    //conversion_metodo1();






    // DESARROLLO DEL PROGRAMA ..

    // ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

    /*
    bool opciones = false;
    while (opciones == false)
        switch (menu_entrada()) {
        case 1:
            cout << "Funciona con 1." << endl;
            opciones = true;
            break;
        case 2:
            cout << "Funciona con 2." << endl;
            opciones = true;
            break;
        case 3:
            cout << "Funciona con 3." << endl;
            opciones = true;
            break;
        default:
            cout << "Opcion no valida, intente nuevamente.." << endl;
            opciones = true;
        }*/

    return 0;
}
