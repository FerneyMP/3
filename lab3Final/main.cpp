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
    cout << "Por favor elija una opcion:\n1. Codificar\n2. Decodificar\n3. Salir  " << endl;  cin>>menu2;
    while ((menu2<'1') || (menu2>'2')){
         cout << "El valor no esta permitido, intente nuevamente  " ; cin>>menu2;
    }
    if (menu2 == '3'){
        cout<<"Gracias por usar nuestros servicios :)"<<endl;
        break;
    }
    else{
    cout<<"Semilla: "<<endl; cin>> Semilla; //validar

    cout<<"Nombre del archivo fuente: "<<endl; cin>> nombre_ar;
    cout<<"Nombre del archivo salida: "<<endl; cin>> nombre_ar2;}

    //   ---->  AGREGAR MÉTODO 1.

    break;
        }

    case '2':{  //Método 2
    cout << "Por favor elija una opcion:\n1. Codificar\n2. Decodificar\n3. Salir " << endl;  cin>>menu2;
    while ((menu2<'1') || (menu2>'3')){
         cout << "El valor no esta permitido, intente nuevamente  " ; cin>>menu2;
    }   
    // si es igual a 3 salirse
    if (menu2 == '3'){
        cout<<"Gracias por usar nuestros servicios :)"<<endl;
        break;
    }
    else{
    cout<<"Semilla: "<<endl; cin>> Semilla; //validar

    cout<<"Nombre del archivo fuente: "<<endl; cin>> nombre_ar;
    cout<<"Nombre del archivo salida: "<<endl; cin>> nombre_ar2;

    if (menu2=='1') codificacion(Semilla,nombre_ar+".txt",nombre_ar2+".dat");
    else if(menu2=='2') decodificacion(Semilla,nombre_ar+".dat",nombre_ar2+".txt");}

    break;

      }

 /* ---------------------------------------------------------CAJERO------------------------------------------------------------------------*/
    case '3':{   //Cajero

    /*! CLS ---> Borrar consola */

        //Variables controladoras de los menus
        short int MenuPrincipal = 0;
        short int MenuUsuario = 0;
        short int MenuIntermedio = 0;

        //Variables switch
        short int entradaPrincipal = 0;
        short int entradaUsuario = 0;

        short int semillaCajero=4;
        long int retirar;

        string usuario,clave, cajero, lectura, contrasena, cedula, saldo, datos, registro;

        while (MenuPrincipal == 0){
        //system("clear"); /*! Para Linux */
        //system("CLS"); /*! Para Windows */
        cout<< "Ingrese 1 para iniciar sesion como administrador\nIngrese 2 para iniciar sesion como  usuario\nIngrese 3 para salir"<<endl; cin>>entradaPrincipal;
        cout << endl;
        while ((entradaPrincipal<1)||(entradaPrincipal>3)){
             cout << "El valor no esta permitido, intente nuevamente  " ; cin>>entradaPrincipal;
        }

        //Reiniciar variables
        MenuUsuario = 0;
        MenuIntermedio = 0;


        //admin
        while (MenuIntermedio == 0){

            if (entradaPrincipal == 1){

                cout<<"Administrador: ";
                cin >> clave; cout << endl;
                char sn;
                char arr[4]={'s','S','n','N'};

                /*! Clave = codificar */
                cajero = codificacionCajero(semillaCajero, clave);
                //
                lectura = leer("sudo.dat",false);
               if(lectura == cajero){
                   cout << "Welcome Boss." << endl;
                   cout << "Desea registrar un usuario: ? \n[s/n] ";
                   cin >> sn; cout << endl;

                   while ((sn != arr[0]) && (sn != arr[1]) && (sn != arr[2]) && (sn != arr[3])){
                       cout << "El valor ingresado no esta permitido, intente nuevamente." << endl;
                       cout << "Desea registrar un usuario: ? \n[s/n]" << endl;
                       cin >> sn;
                   }

                   if(sn == 's' || sn == 'S'){
                       cout << "Ingrese la cedula: " << endl; cin >> cedula;
                       cout << "Ingrese la clave: " << endl; cin >> contrasena;
                       cout << "Ingrese el saldo: " << endl; cin >> saldo;
                       datos = '\n' + cedula + ',' + contrasena + ',' + saldo + '\n';
                       cout << datos << endl;
                       registro = codificacionCajero(semillaCajero, datos);
                       escribirCajero(registro,"usuario.dat",false);

                       //EN ESTE PUNTO SE DEBE ENCRIPTAR Y ACTUALIZAR EN EL ARCHIVO




                       //VALIDACIONES --->Isdigit (Cédula)
                       //Ocultar constraseña
                       //Saldo no ser negativo
                       //Cerrar el archivo, guardarlo
                   }
                   else cout << "Regresando..." << endl << endl;
               }
               else{
                   cout << "Clave incorrecta, No eres mi Boss." << endl;}
               break;
            }


            if (entradaPrincipal == 2){

                //VALIDACION USUARIO

                string lecturaUser, decodificarUser,complete;

                cout<< "Ingrese su cédula: "; cin>>usuario;
                cout<< "Ingrese su clave: "; cin>>clave; cout << endl;
                complete = usuario + "," + clave;

                 lecturaUser = leer("usuario.dat",false);
                 decodificarUser = decodificacionCajero(semillaCajero,lecturaUser);
                 //cout << decodificarUser << endl;
                 //decodificar contiene toda la informacion, y esto separado por salto de linea
                 //si utilizamos el .find con complete y eliminar todo lo que haya despues del salto de linea

                 if(decodificarUser.find(complete)!=string::npos){
                     //Si es diferente, pertenece al string (npos)
                     cout << "¡Bienvenido " << usuario << "!" <<endl << endl;

                     while (MenuUsuario == 0) {
                         cout<< "Ingrese 1 Consultar su saldo\nIngrese 2 para retirar dinero\nIngrese 0 para salir"<<endl;
                         cin >> entradaUsuario; cout << endl;
                         while ((entradaUsuario<0)||(entradaUsuario>2)){
                              cout << "El valor no esta permitido, intente nuevamente  " << endl << endl;
                              cin>>entradaUsuario;
                         }

                         while (entradaUsuario == 1) {
                             size_t posicion;
                             string copia, _saldo;

                             posicion = decodificarUser.find(complete);
                             bool encontrar=false;
                             int coma=0;

                             for(unsigned long long c = posicion; c < decodificarUser.size(); c++){
                                copia += decodificarUser[c];
                             }


                             for(unsigned long long int i=0; i<copia.length();++i){
                                 if (copia[i]==44){
                                     coma++;
                                     if (coma==2){
                                         encontrar = true;
                                     }
                                 }
                                 if(copia[i]==10){
                                     encontrar = false;
                                     break;
                                 }

                                 if (encontrar){
                                     _saldo+= copia[i+1];
                                 }
                             }
                             cout << "Su saldo es: "<<_saldo << endl;
                                            //
                             //Resta de saldo
                             long long int saldo_mod=atoi(_saldo.c_str())-1000; //string a int
                              _saldo=to_string(saldo_mod); //int a string

                              unsigned long long int iterar= posicion;
                             //for (unsigned long long int f = posicion; f < decodificarUser.length();  f++){
                             for (unsigned long long int g = 0; g < _saldo.length(); g++){
                                 decodificarUser[iterar+16] = _saldo[g];
                                 iterar++;
                             }
                            // }

                            cout << "Su saldo es: "<<_saldo  << endl;
                            break;
                         }

                         while (entradaUsuario == 2) {
                             cout << "Retira dinero" << endl << endl;
                             cout << "Thanks for using our services" << endl << endl;



                             MenuUsuario =1;
                             MenuIntermedio =1;
                             break;
                         }

                         while (entradaUsuario ==0) {

                             cout<<"Gracias por usar nuestros servicios :)"<<endl;
                             MenuUsuario =1;
                             MenuIntermedio =1;
                             break;
                         }


                     }// MenuUsuario
                }
                 else{
                     cout << "¡Lo sentimos!, usuario o clave incorrecta. Vuelve a intentarlo." << endl;}
                     //Si es igual, no pertenece al string

            } //Entrada Principal2

            if (entradaPrincipal == 3){

                cout<<"Gracias por usar nuestros servicios :)"<<endl;
                MenuPrincipal =1;
                break;
            }
        } //Menu intermedio
        } //Menu Principal
    } // Case 3
    } // Switch funcionalidades

    return 0;
}
