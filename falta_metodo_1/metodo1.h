#ifndef METODO1_H
#define METODO1_H

//aqui se incluye todo lo relacionado al manejo de archivos de texto

//size_text: funcion para conocer el tamaño de un arch
unsigned long long size_text (const char *name);//se le pasa el nombre del archivo d texto
bool code_decode(const char *read, const char *write, unsigned int n, bool method);
void read_text (const char *name, char *text,unsigned long long tam);//nombre del archivo a leer, puntero en donde quiero guardar la infomacion
void text2bin ( char *text, char *bin, unsigned long long tam);

/*metodo1
 * leer
 * convertir a binario
 * aplicar reglas de la guia
 * binario a texto
 * esribir en el codificado
 */


#endif // METODO1_H
