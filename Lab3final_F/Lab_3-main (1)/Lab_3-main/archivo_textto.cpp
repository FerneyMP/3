#include "archivo_textto.h"
//fstream lectura, escritura

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

//Función que recibe un caracter(en su representación ASCII) y lo convierte en número binario
int *Char_a_bool(char c)
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
    ptr = invertir_binario(binario);
    return ptr;
}

//Función que invierte el arreglo de binarios ..
int *invertir_binario(int b[])
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


void leer_archivo(string name)
{
    //----> FASE 1: Lectura del archivo
    long long int tamanio = 0;
    //int contador_bits=0;
    int conteo=0, conteo2=0;
    string datos;
    fstream natural(name+".txt", fstream::in);
    int *parte1;
    //----> FASE 3:
    fstream PRUEBA("prueba.txt", fstream::out); // MODIFICAR DESPUÉS ******************************************************

    if(natural.is_open()){
        cout << "\nEl archivo ha sido abierto correctamente.." << endl << endl;
        while(!natural.eof()){
            tamanio = natural.tellg();
            datos.push_back(natural.get());
        }
        datos.pop_back();
    }
    else cout << name << +".txt no pudo ser abierto, puede que no exista dicho archivo o haya un error de redaccion.." << endl;
    //----> FASE 2: Conversión del archivo en binario
    //idea: por cada iteración en el ciclo, invocar la función caracter a entero, luego entero a bool e ir escribiendo sobre
    // el archivo ...... idea2: un arreglo que almacene strings .....
    while(conteo <= tamanio-1){
        for (int i=0; i<=7; i++){
            parte1= Char_a_bool(datos[conteo2]); //imprime 0 y debería ser la posición 0 del arreglo
            //hasta este parte1, se convierte el dato string, traído del archivo y convierte cada caracter a binario ..
            cout << *(parte1+i);
            //----> FASE 3:
            PRUEBA << *(parte1+i);
        }
        conteo++;
        conteo2++;
    }
    natural.close();
    PRUEBA.close();
}


//ideas parte2
//int *parte2= new int[8]{};
// esto dentro del for ....
//parte2[i]=*parte1;
//bool_a_char(parte2);
//HABILITAR PARTE2, PARA SEGUIR TRABAJANDO MÁS ADELANTE. DEBO MEJORAR ESTA PARTE DEL ALGORITMO


void conversion_metodo1()
{
    //Fase 1: Lectura del archivo binario
    fstream prueba("prueba.txt", fstream::in);
    string datos;
    int semilla, tamanio;
    int contador=0;
    //system("clear");
    cout << "\nIngrese el valor de la semilla: "; cin >> semilla;
    tamanio = prueba.tellg();
    char *cadena = new char[tamanio]{};
    if(prueba.is_open()){
        cout << "\nEl archivo ha sido abierto correctamente.." << endl << endl;
        while(!prueba.eof()){
            datos.push_back(prueba.get());
            cadena[contador] = datos[contador];
            contador++;
        }
    }
    //Fase 2: codificación del archivo binario
    /*
       Para codificar se convierte el archivo a binario, luego se separa en bloques de n bits. En el primer
       bloque se cambian todos los 1 por 0 y viceversa. Para los grupos siguientes se debe contar el
       número de 1s y 0s en el grupo anterior y hacer cambios según la siguiente regla:

        Si hay igual cantidad de 1s y 0s se invierte cada bit del grupo.
        Si hay mayor cantidad de 0s se invierte cada 2 bits.
        Si hay mayor cantidad de 1s se invierte cada 3 bits.
    */
    //DESARROLLAR FUNCIÓN PARA QUE CUENTE LA CANTIDAD DE 0s Y 1s
    //INCLUIR SEMILLA DADO QUE CORRESPONDE A SER LOS BLOQUES DE BITS
    int ceros=0, unos=0;
    ceros_unos_count(semilla, cadena,ceros,unos);
    for(int bloque1=0; bloque1<=semilla; bloque1++){
        if(cadena[bloque1]=='0'){
            cadena[bloque1]=1;
        }
        else if(cadena[bloque1]=='1'){
            cadena[bloque1]=0;
        }
    }
    if (ceros==unos){
        // invertir cada bit.
        // recorrer todo el arreglo
        for(int bloque_igual_cantidad=1; bloque_igual_cantidad<=semilla; bloque_igual_cantidad++){
            if(cadena[semilla+bloque_igual_cantidad]=='0'){
                cadena[semilla+bloque_igual_cantidad] = 1;
            }
            else if(cadena[semilla+bloque_igual_cantidad]=='1'){
                cadena[semilla+bloque_igual_cantidad] = 0;
            }
        }
    }
    else if(ceros>unos){
        // invertir cada 2 bits.
        for(int bloque_mayor_ceros=1; bloque_mayor_ceros<=semilla; bloque_mayor_ceros= bloque_mayor_ceros+2){
            if(cadena[semilla+bloque_mayor_ceros]=='0'){
                cadena[semilla+bloque_mayor_ceros]=1;
            }
            else if(cadena[semilla+bloque_mayor_ceros]=='1'){
                cadena[semilla+bloque_mayor_ceros]=0;
            }
        }

    }
    else if(ceros<unos){
        // invertir cada 3 bits.
        for(int bloque_mayor_unos=1;bloque_mayor_unos<=semilla; bloque_mayor_unos= bloque_mayor_unos+3){
            if(cadena[semilla+bloque_mayor_unos]=='0'){
                cadena[semilla+bloque_mayor_unos]=1;
            }
            else if(cadena[semilla+bloque_mayor_unos]=='1'){
                cadena[semilla+bloque_mayor_unos]=0;
            }
        }
    }
    //Fase 3: escribir en el archivo ..
    char *codificado1;
    codificado1 = cadena;
    fstream codificado("codificado.dat", fstream::out);
    for(int fin=0; fin<tamanio; fin++){
       codificado << *(codificado1+fin);
    }
    delete[] cadena;
}

void ceros_unos_count(int semilla, char cadena[], int &ceros, int &unos) //parametros por referencia
{

    for (int i=0; i<=semilla; i++){
        if(cadena[i]=='0'){
            ceros+= ceros;
        }
        else if(cadena[i]=='1'){
            unos+= unos;
        }
    }
}

