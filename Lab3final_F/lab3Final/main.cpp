#include "funciones.h"
#include "metodo2.h"
#include <stdio.h>

int main()
{
    char funcionalidades,menu2;
    short int Semilla;
    string nombre_ar, nombre_ar2;

    cout << "              Bienvenido! " << endl;
    leer_menu();

    cout << "Por favor elija una opcion: " << endl;
    cout << "1. Metodo 1\n2. Metodo 2\n3. Cajero \n4. Salir " << endl;  cin >> funcionalidades;
    while ((funcionalidades<'1') || (funcionalidades>'4')){
         cout << "El valor no esta permitido, intente nuevamente  " ; cin>>funcionalidades;
    }
    switch (funcionalidades){

    case '1':{  //Método 1
    cout << "Por favor elija una opcion:\n1. Codificar\n2. Decodificar " << endl;  cin>>menu2;
    while ((menu2<'1') || (menu2>'2')){
         cout << "El valor no esta permitido, intente nuevamente  " ; cin>>menu2;
    }

    cout<<"Semilla: "<<endl; cin>> Semilla; //validar

    cout<<"Nombre del archivo fuente: "<<endl; cin>> nombre_ar;
    cout<<"Nombre del archivo salida: "<<endl; cin>> nombre_ar2;

    //   ---->  AGREGAR MÉTODO 1.

    break;
        }

    case '2':{  //Método 2
    cout << "Por favor elija una opcion:\n1. Codificar\n2. Decodificar" << endl;  cin>>menu2;
    while ((menu2<'1') || (menu2>'2')){
         cout << "El valor no esta permitido, intente nuevamente  " ; cin>>menu2;
    }   

    cout<<"Semilla: "<<endl; cin>> Semilla; //validar

    cout<<"Nombre del archivo fuente: "<<endl; cin>> nombre_ar;
    cout<<"Nombre del archivo salida: "<<endl; cin>> nombre_ar2;

    if (menu2=='1') codificacion(Semilla,nombre_ar+".txt",nombre_ar2+".dat");
    else if(menu2=='2') decodificacion(Semilla,nombre_ar+".dat",nombre_ar2+".txt");
    break;

      }

    case '3':{   //Cajero

    /*! CLS ---> Borrar consola */

        short int menu,menu_usuario,metodo=2, semillaCajero=4;
        long int retirar;
        bool bandera=true,bandera2=true, banderaInicial=true;
        string usuario,clave, cajero, lectura, contrasena, cedula, saldo, datos, registro;

        while (bandera){
        //system("clear"); /*! Para Linux */
        //system("CLS"); /*! Para Windows */
        cout<< "Ingrese 1 para iniciar sesion como administrador\nIngrese 2 para iniciar sesion como  usuario\nIngrese 3 para salir"<<endl; cin>>menu;
        while ((menu<1)||(menu>3)){
             cout << "El valor no esta permitido, intente nuevamente  " ; cin>>menu;
        }

        switch (menu){

          case 1:{          //admin
           cout<<"Administrador: "<<endl;
           cin >> clave;
           char sn;

           /*! Clave = codificar */
           cajero = codificacionCajero(semillaCajero, clave);
           //
           lectura = leer("sudo.dat",false);

           // CICLO PARA VOLVER AL MENÚ

           if(lectura == cajero){
               cout << "Welcome Boss." << endl;
               cout << "Desea registrar un usuario: ? \n[s/n]" << endl;
               cin >> sn;
               /*!CORREGIR VALIDACION

               while ((sn!= 's') || (sn!= 'n')){
                   cout << "El valor ingresado no esta permitido, intente nuevamente." << endl;
                   cout << "Desea registrar un usuario: ? \n[s/n]" << endl;
                   cin >> sn;
               }*/
               if (sn == 's' || sn == 'S'){

                   cout << "Ingrese la cedula: " << endl; cin >> cedula;
                   cout << "Ingrese la clave: " << endl; cin >> contrasena;
                   cout << "Ingrese el saldo: " << endl; cin >> saldo;
                   datos = '\n' + cedula + ',' + contrasena + ',' + saldo;
                   cout << datos << endl;
                   registro = codificacionCajero(semillaCajero, datos);
                   escribirCajero(registro,"usuario.dat",false);
                   //VALIDACIONES --->Isdigit (Cédula)
                   //Ocultar constraseña
                   //Saldo no ser negativo
                   //Cerrar el archivo, guardarlo
               }
           }
           else
               cout << "Clave incorrecta, No eres mi Boss." << endl;

           break;

            }
          case 2:{         // usuario
            cout<<"caso2"<<endl;
            while(banderaInicial){
                string lecturaUser, decodificarUser,complete;

                 cout<< "Ingrese su cédula"<<endl; cin>>usuario;
                 cout<< "Ingrese su clave"<<endl; cin>>clave;
                 complete = usuario + "," + clave;

                 /*! SI EL ADMINISTRADOR QUIERE REGISTRAR UN USUARIO QUE YA EXISTE */
                 /* 1.abrir el archivo                         ✔
                  * 2.decodificarlo                            ✔
                  * 3.guardar la información en un string      ✔
                  * 4.buscar la información del usuario
                  * 5.comparar que si corresponda
                  */

                 lecturaUser = leer("usuario.dat",false);
                 decodificarUser = decodificacionCajero(semillaCajero,lecturaUser);
                 //cout << decodificarUser << endl;
                 //decodificar contiene toda la informacion, y esto separado por salto de linea
                 //si utilizamos el .find con complete y eliminar todo lo que haya despues del salto de linea

                 if(decodificarUser.find(complete)!=string::npos){
                     //Si es diferente, pertenece al string (npos)
                     cout << "¡Bienvenido " << usuario << "!" <<endl;
                     cout<< "Ingrese 1 Consultar su saldo\nIngrese 2 para retirar dinero\nIngrese 0 para salir"<<endl; cin>>menu_usuario;
                     while(bandera2){
                             //validar

                              switch(menu_usuario){
                              case 1:{
                               cout<<"caso1"<<endl;

                               size_t posicion;
                               string copia, _saldo;
                               posicion = decodificarUser.find(complete);
                               //cout << decodificarUser.size() << endl;
                               for(unsigned long c = posicion; c < decodificarUser.size(); c++){
                                  copia += decodificarUser[c];
                               }
                               for(unsigned long d = 1; ( (d<copia.find('\n')) || (d<copia.find('\0')) ); d++){
                                  _saldo += copia[complete.size()+d];
                               }
                               cout << complete.size() << endl;
                               cout << _saldo <<endl;

                               //funcion para separar y mostrar  cout<<"Saldo restante:"<<endl;
                               //bandera2 = false;
                               //banderaInicial = false;

                               //string *ptr;
                               //ptr = strtok(decodificarUser, "\n");
                               //strtok -->funcion que sirve para dividir la linea <stdio.h> argumetos (decodificarUser, "\n")
                               // hasta el salto de linea
                               //puntero = strtok(linea, ","); puntero = strtok(NULL, "\n");
                               // strcpy almacena en la primera variable el puntero strtok
                               // strcpy(Bnombre, puntero)
                               //system("pause");
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
                               bandera2 = false;
                               banderaInicial = false;

                                break;

                                }

                              default:{
                                   cout<<"Opcion no valida"<<endl;
                                   bandera2 = false;
                                   banderaInicial = false;
                                   break;
                              }

                              }
                          }
                 }
                 else{
                     cout << "¡Lo sentimos!, usuario o clave incorrecta. Vuelve a intentarlo." << endl;
                     //Si es igual, no pertenece al string
                     banderaInicial = false;
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

    break;

         }       
    case '4':
        cout << "¡Gracias por utilizar nuestros servicios!. Vuelva pronto :)" << endl;
        break;
        }
    return 0;
}
