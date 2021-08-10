#ifndef METODO1_H
#define METODO1_H

unsigned long long size_text(const char *name);
bool code_decode(const char *read, const char *write, unsigned int n, bool method);
void read_text(const char *name,char *text, unsigned long long tam);
void text2bin(char *text, char *bin, unsigned long long tam);

#endif // METODO1_H
