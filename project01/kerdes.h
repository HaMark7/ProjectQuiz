#ifndef KERDES_H_INCLUDED
#define KERDES_H_INCLUDED
#include <string.h>


typedef struct KERDES{
    char* kerdes;
    char* valaszok;
    char* helyesek;
    int meret;
}KERDES;

KERDES createKerdes();
void ReadKerdes(char* filename,KERDES* k);

#endif // KERDES_H_INCLUDED
