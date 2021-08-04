#include "metodo2.h"
#include "funciones_principales.h"

bool codificacion(int semilla, string n_arhivo, string n_archivo2)
{
    bool result = true;
    string texto, binario;
    try {
        texto = leer_string(n_arhivo, true);
        binario = Char_a_bool(texto);
        binario = reglas_codifica(binario, semilla);
        texto = binario_texto(binario);
        escribir(texto,n_archivo2, false);
    }  catch (...) {
        result = false;
    }
    return true;
}

string reglas_codifica(string binario, int semilla)
{
    string pedazo;
    for(unsigned long long i=0; i<binario.length(); i++){
        pedazo.push_back(binario[i]);
        if((i+1)%semilla==0 || i==binario.length()-1){
            pedazo = metodo2(pedazo);
            cout << pedazo << endl;
            pedazo.clear();
        }
    }
}

string metodo2(string pedazo)
{
    string datos;
    datos.push_back(pedazo[pedazo.length()-1]);
    for(unsigned long long i=0; i<pedazo.length(); i++){
        datos.push_back(pedazo[i]);
    }
    return datos;
}

string binario_texto(string binario)
{
    string datos, pedazo;
    for(unsigned long long i=0; i<binario.length(); i++){
        pedazo.push_back(binario[i]);
        if((i+1)%8==0){
            datos.push_back(conv_letra(pedazo));
            pedazo.clear();
        }
    }
    return datos;
}

char conv_letra(string pedazo)
{
    char l=0;
    for(unsigned long long i=0, j=128; i<pedazo.length(); i++,j/=2){
        l+=j*pedazo[i];
        return l;
    }
}
