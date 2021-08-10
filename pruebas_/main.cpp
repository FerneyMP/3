#include <iostream>

using namespace std;
bool EncontrarSaldo(string sald_, unsigned long long pos);

int main()
{
    //Variables controladoras de los menus
    short int MenuPrincipal = 0;
    short int MenuUsuario = 0;
    short int MenuIntermedio = 0;

    short int entradaPrincipal = 0;
    short int entradaUsuario = 0;

    /*! PRUEBAS Para ocultar contraseña */
/*
    char caracter;
    string password;
    cout << "Ingrese la clave: ";
    caracter = getchar();

    while (caracter != 13) {
        password.push_back(caracter);
        cout << "*";
        caracter = getchar();
    }*/

    string prueba=("Hola es una prueba ");
    string prueba1 = (" :)");

    string _saldo = ("1234\n");  //CASO 1
    string _saldo1=("45000");    //CASO 2

    size_t posicion, posicion2, posicion3, posicionFinal;

    int caso[2] = {1,2};

    if (caso[0] == 1){

        posicion = prueba.length(); //Tamaño del arreglo ORIGINAL

        posicionFinal = _saldo.length(); //Tamaño del arreglo CASO 1

        //cout << posicionFinal << " Vs. " << _saldo.length() << endl;

        //                          String, posición
        bool work_ = EncontrarSaldo(_saldo, posicionFinal);


        if (work_){
            prueba.insert(posicion, _saldo);  // si hay salto de línea
        }
        else{
            prueba.insert(posicion, _saldo1); // si NO hay salto de línea
        }
    }

    if (caso[1] == 2){

        posicion = prueba.length();

        posicionFinal = _saldo1.length();

        bool work_ = EncontrarSaldo(_saldo1, posicionFinal);


        if (work_){
            prueba.insert(posicion, _saldo);
        }
        else{
            prueba.insert(posicion, _saldo1);
        }

    }

    /*
    posicion3 =  5;

    prueba.insert(posicion,_saldo);

    posicion2 = posicion + _saldo.length();

    prueba.insert(posicion3,"F ");*/


    cout << prueba << endl;
















    //cout << "Si hay salto de linea ;)" << endl;
/*
    while (MenuPrincipal == 0){
        cout<< "Ingrese 1 para iniciar sesion como administrador\nIngrese 2 para iniciar sesion como  usuario\nIngrese 3 para salir"<<endl;
        cout << endl;
        cin >>entradaPrincipal;
        cout << endl;

        //Reiniciar variables
        MenuUsuario = 0;
        MenuIntermedio = 0;

        while(MenuIntermedio == 0){
            if(entradaPrincipal == 1){
                cout << "Ejecuta lo de administrador " << endl << endl;
                break;
            }

            if (entradaPrincipal == 2){

                while (MenuUsuario == 0){

                    cout<< "Ingrese 1 Consultar su saldo\nIngrese 2 para retirar dinero\nIngrese 0 para salir"<<endl << endl;
                    cin>>entradaUsuario;
                    cout << endl;

                    while (entradaUsuario == 1){
                        cout << "Saldo " << endl << endl;
                        //MenuIntermedio =1;
                        break;
                    }


                    while (entradaUsuario == 2){
                        cout << "Retira dinero" << endl << endl;
                        cout << "Thanks for using our services" << endl << endl;
                        MenuUsuario =1;
                        MenuIntermedio =1;
                        break;
                    }


                    while (entradaUsuario ==0){
                        cout << "Thanks for using our services" << endl << endl;
                        MenuUsuario =1;
                        MenuIntermedio =1;
                        break;
                    }
                }
            }


            if (entradaPrincipal == 3){
                cout << "Thanks for using our services" << endl << endl;
                MenuPrincipal =1;
                break;
            }
        }
    }*/
    return 0;
}

bool EncontrarSaldo(string sald_, unsigned long long int pos){
    bool salto_linea = false;

    if(sald_[pos-1] == '\n'){
        salto_linea = true;
    }

    if(sald_[pos] == '\n'){
        salto_linea = true;
    }
    return salto_linea;
}
