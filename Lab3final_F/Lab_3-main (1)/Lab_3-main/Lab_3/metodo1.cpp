#include "metodo1.h"



//ideas parte2
//int *parte2= new int[8]{};
// esto dentro del for ....
//parte2[i]=*parte1;
//bool_a_char(parte2);
//HABILITAR PARTE2, PARA SEGUIR TRABAJANDO MÁS ADELANTE. DEBO MEJORAR ESTA PARTE DEL ALGORITMO


void conversion_metodo1(int semilla, string n_archivo, string n_archivo2)
{
    //Fase 1: Lectura del archivo binario    
    char *texto;
    //char *binario = new char[8]{};
    texto = leer_char(n_archivo, true); // archivo modo lectura
    for(unsigned long long i=0; i<8; i++){

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
    /*int ceros=0, unos=0;
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
    fstream codificado;
    codificado.open("codificado.dat", ios::out);
    for(int fin=0; fin<tamanio; fin++){
       codificado << *(codificado1+fin);
    }
    codificado.close();
    delete[] cadena;*/
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

/*
void leer_archivo(string name)
{

    long long int tamanio = 0;
    //int contador_bits=0;
    int conteo=0, conteo2=0;
    string datos;
    fstream lectura(name+".txt", fstream::in);
    int *parte1;
    //----> FASE 3:
    fstream PRUEBA("prueba.txt", fstream::out); // MODIFICAR DESPUÉS ******************************************************

    if(lectura.is_open()){

        while(!lectura.eof()){
            tamanio = lectura.tellg();
            datos.push_back(lectura.get());
        }
        datos.pop_back();
    }

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
    lectura.close();
    PRUEBA.close();
}
*/
