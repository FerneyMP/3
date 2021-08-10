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
        string retirar;
        unsigned long long int _retirar = 0;
        string usuario,clave, cajero, lectura, contrasena, cedula, saldo, datos, registro;

        while (MenuPrincipal == 0){
        //system("clear"); /*! Para Linux */
        //system("CLS"); /*! Para Windows */
        cout<< "\nIngrese 1 para iniciar sesion como administrador\nIngrese 2 para iniciar sesion como  usuario\nIngrese 3 para salir"<<endl; cin>>entradaPrincipal;
        cout << endl;
        while ((entradaPrincipal<1)||(entradaPrincipal>3)){
             cout << "El valor no esta permitido, intente nuevamente  " ; cin>>entradaPrincipal;
        }

        //Reiniciar variables/
        MenuUsuario = 0;
        MenuIntermedio = 0;


        //admin
        while (MenuIntermedio == 0){

            if (entradaPrincipal == 1){

                cout<<"Administrador: ";cin >> clave;
                cout << endl;
                char sn, arr[4]={'s','S','n','N'};

                /*! Clave = codificar */
                cajero = codificacionCajero(semillaCajero, clave);
                //
                lectura = leer("sudo.dat",false);
               if(lectura == cajero){
                   cout << "Welcome Boss." << endl;
                   cout << "Desea registrar un usuario: ? [s/n] ";
                   cin >> sn; cout << endl;

                   while ((sn != arr[0]) && (sn != arr[1]) && (sn != arr[2]) && (sn != arr[3])){
                       cout << "El valor ingresado no esta permitido, intente nuevamente." << endl;
                       cout << "Desea registrar un usuario: ? [s/n]" << endl;
                       cin >> sn;
                   }

                   if(sn == 's' || sn == 'S'){

                       cout << "Ingrese la cedula: "; cin >> cedula; //solo 10 numeros
                       validar(cedula, 1);
                       cout << "Ingrese la clave: " ; cin >> contrasena; //solo 4 numeros
                       validar(contrasena, 2);
                       cout << "Ingrese el saldo: " ; cin >> saldo; //no negativos
                       validar(saldo, 3);
                       datos = '\n' + cedula + ',' + contrasena + ',' + saldo + '\n';

                       //validar que el usuaro no este registrado

                       registro = codificacionCajero(semillaCajero, datos);
                       escribirCajero(registro,"usuario.dat",true);
                   }
                   else cout << "Regresando..." << endl << endl;
               }
               else{
                   cout << "Clave incorrecta, No eres mi Boss. ";
                   cout << endl;}

               break;
            }


            if (entradaPrincipal == 2){

                //VALIDACION USUARIO

                string lecturaUser, decodificarUser,complete;

                cout<< "Ingrese su cedula: "; cin>>usuario;
                validar(usuario, 1);
                cout<< "Ingrese su clave: "; cin>>clave;
                validar(clave, 2);


                complete = usuario + "," + clave;

                 lecturaUser = leer("usuario.dat",false);
                 decodificarUser = decodificacionCajero(semillaCajero,lecturaUser);
                 //cout << decodificarUser << endl;
                 //decodificar contiene toda la informacion, y esto separado por salto de linea
                 //si utilizamos el .find con complete y eliminar todo lo que haya despues del salto de linea

                 if(decodificarUser.find(complete)!=string::npos){
                     //Si es diferente, pertenece al string (npos)
                     cout << "Bienvenido " << usuario << "!" <<endl << endl;


                     while (MenuUsuario == 0) {
                         cout<< "Ingrese 1 Consultar su saldo\nIngrese 2 para retirar dinero\nIngrese 0 para salir"<<endl;
                         cin >> entradaUsuario; cout << endl;
                         while ((entradaUsuario<0)||(entradaUsuario>2)){
                              cout << "El valor no esta permitido, intente nuevamente  " << endl << endl;
                              cin>>entradaUsuario;
                         }

                         while (entradaUsuario == 1) { // Consultar saldo
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
                             }  //Saldo sin restar

                             cout << "Su saldo es: "<<_saldo << endl;
                             unsigned long long int saldo_mod=stoll(_saldo);
                             if (saldo_mod < 1000){
                                 cout << "Saldo insuficiente para esta operacion" << endl;
                                 break;
                             }
                             else{ //Resta de saldo

                                 // Mediante estas dos lineas se hace el proceso de restar el saldo
                             saldo_mod -= 1000; //string a int

                             decodificarUser.erase(posicion+16,posicion+_saldo.length());
                             _saldo=to_string(saldo_mod); //int a string

                             // Con este ciclo for se modifica el string con la infomación completa del archivo usuario

                             /* SE MODIFICA ESTO
                             unsigned long long int iterar= posicion;
                             for (unsigned long long int g = 0; g < _saldo.length(); g++){
                                 decodificarUser[iterar+16] = _saldo[g];
                                 iterar++;
                             }                             
                             */

                             unsigned long long int iterar2 = 0;
                             for (unsigned long long g = posicion+16; g < (posicion+16+_saldo.length()); g++){
                                 decodificarUser.push_back(_saldo[iterar2]);
                                 iterar2++;
                             }

                             cout << "Esta transaccion ha tenido un costo de 1000 COP.\nSu nuevo saldo es: "<<_saldo  << endl << endl;
                             // Se escribe la información actualizada en usuario.dat
                             registro = codificacionCajero(semillaCajero, decodificarUser);
                             escribirCajero(registro,"usuario.dat",false);
                            }

                            break;
                         }

                         while (entradaUsuario == 2) { // Retirar saldo

                             // PEDIRLE AL USUARIO EL VALOR QUE DESEA             ☑
                             // RETIRAR EL DINERO               ----> VALIDAR
                             // RESTARLE POR LA TRANSACCIÓN     ----> VALIDAR     ☑
                             // IMPRIMIR EL SALDO QUE QUEDA EN LA CUENTA          ☑
                             // AGRADECER                                         ☑
                             // ESCRIBIR EN EL ARCHIVO                            ☑

                             size_t posicion, posicion2;
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
                             }  //Saldo sin restar

                             cout << "Por favor escriba la cantidad de dinero que desea retirar: ";
                             cin >> retirar;
                             validar(retirar, 3); //string a puntero
                             //_retirar = atoi(retirar.c_str());
                             _retirar = stoll(retirar);
                             unsigned long long int saldo_mod = stoll(_saldo);  //-----CORREGIR, preguntar NELSON

                             if (_retirar > saldo_mod){
                                 cout << "El valor que desea retirar es mayor al saldo actual." << endl;
                                 MenuUsuario =1;
                                 MenuIntermedio =1;
                                 break;
                             }

                             else if ((saldo_mod - _retirar) < 1000){
                                 cout << "La transaccion no se puede realizar.\nEl costo de esta operacion es de 1000 COP." << endl;
                                 MenuUsuario =1;
                                 MenuIntermedio =1;
                                 break;
                             }

                             //Resta de saldo
                             else if ((saldo_mod - _retirar) >= 1000){
                                // Mediante estas dos lineas se hace el proceso de restar el saldo

                                saldo_mod -= _retirar+1000; //Hace la resta del saldo

//CONDICIONAL
                                decodificarUser.erase(posicion+16, _saldo.length());

                                _saldo = to_string(saldo_mod); //int a string

                                posicion2 = (posicion + 16) + (_saldo.length());

                                decodificarUser.insert(posicion+16, _saldo);

                                decodificarUser.insert(posicion2,"\n");

                               /* string prueba=("Hola es una prueba");
                                string prueba1 = (" :)");
                                string _saldo = (" 1234");*/

                                //size_t posicion, posicion2;

                                //posicion = prueba.length();

                                //prueba.insert(posicion,_saldo);

                                //posicion2 = posicion + _saldo.length();

                               // prueba.insert(posicion2,"\n");


                                /*
                                unsigned long long int iterar2 = 0;
                                for (unsigned long long g = posicion+16; g < (posicion+16+_saldo.length()); g++){
                                    decodificarUser.push_back(_saldo[iterar2]);
                                    iterar2++;
                                }*/

                                //insert(tam, string)

                                /*for (unsigned long long int g = 0; g < _saldo.length(); g++){
                                    decodificarUser[iterar+16] = 8;

                                    //decodificarUser[iterar+16] = _saldo[g];
                                    iterar++;
                                }*/

                                // Con este ciclo for se modifica el string con la infomación completa del archivo usuario

                                cout << "Esta transaccion ha tenido un costo de 1000 COP.\nSu nuevo saldo es: "<<_saldo  << endl << endl;
                                // Se escribe la información actualizada en usuario.dat
                                registro = codificacionCajero(semillaCajero, decodificarUser);
                                escribirCajero(registro,"usuario.dat",false);
                                cout << "Thanks for using our services" << endl << endl;
                                MenuUsuario =1;
                                MenuIntermedio =1;
                                break;
                             }
                         }
//Borrar todo el último ---> saldo push.back(_saldo) --->erase(posIni,posFin) if caso \n o length
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
