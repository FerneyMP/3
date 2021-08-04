#include "funciones.h"


//sudo.txt clave encriptada del administrdor
//usuario.dat datos encriptados del usuario
//coficiado, por cualquier metodo
//no usar librerias de contenedores

//actualizar cada que se accede



/*bool opciones = false;
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



int main()
{
    short int menu,menu_usuario,metodo=2, semilla=4;
    long int retirar;
    bool bandera=true,bandera2=true, validacion;
    string usuario,clave;

    while (bandera){

    cout<< "Ingrese 1 para iniciar sesion como administrador\nIngrese 2 para iniciar sesion como  usuario\nIngrese 3 para salir"<<endl; cin>>menu;
    while ((menu!=1) || (menu!=2) ||(menu!=3)){
         cout << "El valor no esta permitido, intente nuevamente  " ; cin>>menu;

    }

    switch (menu){

      case 1:{          //admin
       cout<<"caso1"<<endl;      
        break;

        }

      case 2:{         // usuario

        cout<<"caso2"<<endl;
        while(true){
             cout<< "Ingrese su cédula"<<endl; cin>>usuario;
             cout<< "Ingrese su clave"<<endl; cin>>clave;
             validacion= val(usuario,clave);
            // clave.clear();

             if (validacion){

                 //restarle 1000 al saldo (crear funcion para retirar)


                 while(bandera2){
                     cout<< "Ingrese 1 para consultar su saldo\nIngrese 2 para retirar dinero\nIngrese 0 para salir"<<endl; cin>>menu_usuario;
                    //validar

                     switch(menu_usuario){
                     case 1:{
                      cout<<"caso1"<<endl;
                      //funcion para separar y mostrar  cout<<"Saldo restante:"<<endl;
                       break;

                       }

                     case 2:{
                      cout<<"caso2"<<endl;
                          while (true){

                          cout<<"Ingrese la cantidad que desea retirar"<<endl; cin>>retirar;
                          //que validacion usar para cuando la canridad no sea valida??

                          if (retirar>0){
                              //(crear funcion para retirar)

                              cout<<"Retiro de:"<< retirar <<"COP" <<endl;
                               //funcion para separar y mostrar

                              retirar=0;
                              break;

                          }

                          else if (retirar==0){
                           cout<<"Saldo insuficiente:"<<endl;
                           break;
                          }

                        }

                       break;

                       }

                     default:{
                          cout<<"opcion no valida"<<endl;
                          break;
                     }

                     }
                 }

             }

        }






        break;
      }

      case 3:{
        cout<<"Gracias por usar nuestros servicios :)"<<endl;
        bandera=false;
        break;

      }
     }
   }
       return 0;
}

//validacion como usuario administrador
        //abrir sudo.txt y comparar con lo ingresado (encriptado)

//registro (una vez validado)
        // cedula,clave, saldo COP

//consultar saldo
//retirar dinero (especificar)
//ambos cuestan 1000 COP y se actualiza el saldo (cerrar archivo)

//TODAS LAS TRANSACCIONES EN EL CAJERO DEBEN TENER LA INFORMACION ENCRIPATADA





/*
 *
 * #include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    //Este es el primer taller de ficheros
    int clave, opcion, Bclave, Nclave, sueldo;
    string nombre;
    ofstream Guardar;
    ifstream Leer;
    ofstream Temp;
    Guardar.open("Fichero.txt",ios::app);
    while(true){

        cout << "1. Guardar Registro" << endl;
        cout << "2. Leer Registros" << endl;
        cout << "3. Buscar Registro" << endl;
        cout << "4. Eliminar Registro" << endl;
        cout << "5. Modificar Registro" << endl;
        cout << "6. EXAMPLE" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese un nombre" << endl;
                cin.get();
                getline(cin,nombre);
                cout << "Ingrese Clave" << endl;
                cin >> clave;
                cout << "Ingrese Sueldo" << endl;
                cin >> sueldo;
                Guardar << nombre << "," << clave << "," << sueldo << endl;
                system("pause");
                system("CLS");
                break;
            }
            case 2: {
                Leer.open("Fichero.txt");
                char linea[100];
                Leer.getline(linea, sizeof(linea));
                while (!Leer.eof()) {
                    for(int i=0; i<3;i++){
                        char *puntero;
                        if(i==0){
                            char Bnombre[50];
                            puntero = strtok(linea, ",");
                            strcpy(Bnombre, puntero);
                            nombre = Bnombre;
                        }
                        if(i==1){
                            puntero = strtok(NULL, ",");
                            clave = atoi(puntero);
                        }
                        if(i==2){
                            puntero = strtok(NULL, ",");
                            sueldo = atoi(puntero);
                        }
                    }
                    cout << "Nombre:  " << nombre << endl;
                    cout << "Clave :  " << clave <<endl;
                    cout << "Sueldo:  " << sueldo <<endl;
                    cout << endl;
                    Leer.getline(linea, sizeof(linea));
                }
                Leer.close();
                system("pause");
                system("CLS");
                break;
            }
            case 3: {
                Leer.open("Fichero.txt");
                Leer>>nombre;
                bool encontrado = false;
                cout << "Ingrese clave a buscar"<<endl;
                cin >> Bclave;
                while (!Leer.eof()) {
                    Leer >> clave >> sueldo;
                    if(clave == Bclave){
                        encontrado = true;
                        cout << "Nombre:  "<<nombre<<endl;
                        cout << "Clave :  "<<clave<<endl;
                        cout << "Sueldo:  "<<sueldo<<endl;
                        cout << endl;
                    }
                    Leer >> nombre;
                }
                if(!encontrado){
                    cout << "El registro no existe" << endl;
                }
                Leer.close();
                system("pause");
                system("CLS");
                break;

            }
            case 4: {
                Leer.open("Fichero.txt");
                Temp.open("Temp.txt");
                Leer>>nombre;
                bool encontrado = false;
                cout << "Ingrese clave a eliminar"<<endl;
                cin >> Bclave;
                while (!Leer.eof()) {
                    Leer >> clave >> sueldo;
                    if(clave == Bclave){
                        encontrado = true;
                        cout << "Nombre:  "<<nombre<<endl;
                        cout << "Clave :  "<<clave<<endl;
                        cout << "Sueldo:  "<<sueldo<<endl;
                        cout << endl;
                        cout << "Eliminado"<<endl;
                    }else {
                        Temp << nombre <<" "<<clave<<" "<<sueldo<<endl;
                    }
                    Leer >> nombre;
                }
                if(!encontrado){
                    cout << "El registro no existe" << endl;
                }
                Leer.close();
                Temp.close();
                Guardar.close();
                remove("Fichero.txt");
                rename("Temp.txt", "Fichero.txt");
                Guardar.open("Fichero.txt",ios::app);
                system("pause");
                system("CLS");
                break;

            }
            case 5: {
                Leer.open("Fichero.txt");
                Temp.open("Temp.txt");
                Leer>>nombre;
                bool encontrado = false;
                cout << "Ingrese clave del registro a modificar"<<endl;
                cin >> Bclave;
                while (!Leer.eof()) {
                    Leer >> clave >> sueldo;
                    if(clave == Bclave){
                        encontrado = true;
                        cout << "Nombre:  "<<nombre<<endl;
                        cout << "Clave :  "<<clave<<endl;
                        cout << "Sueldo:  "<<sueldo<<endl;
                        cout << endl;
                        cout << "Ingrese nueva Clave"<<endl;
                        cin >> Nclave;
                        Temp << nombre <<" "<<Nclave<<" "<<sueldo<<endl;
                        cout << "MODIFICADO" << endl;

                    }else {
                        Temp << nombre <<" "<<clave<<" "<<sueldo<<endl;
                    }
                    Leer >> nombre;
                }
                if(!encontrado){
                    cout << "El registro no existe" << endl;
                }
                Leer.close();
                Temp.close();
                Guardar.close();
                remove("Fichero.txt");
                rename("Temp.txt", "Fichero.txt");
                Guardar.open("Fichero.txt",ios::app);
                system("pause");
                system("CLS");
                break;

            }
            case 6:
                string A,B,C;
                int v;
                Leer.open("Fichero.txt");
                Leer>>A;
                while (!Leer.eof()) {
                    Leer>>B;
                    Leer>>C;
                    cout << "El enrutador: " << A << " Y el enrutador: " << B << " Tienen un valor: " << C << endl;
                    Leer >> A;
                }
                Leer.close();
                system("PAUSE");
                system("CLS");
                break;
}

    }
    return 0;
}



*/
