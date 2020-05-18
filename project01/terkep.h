#ifndef TERKEP_H_INCLUDED
#define TERKEP_H_INCLUDED
#include "kerdes.h"

typedef struct Terkep{
    int hossz;
    int magas;
    char** ertek;
}Terkep;

Terkep CreateTK(int hossz,int magas);

void ReadTK(Terkep* terkep,int lvl);

void Kirajzol(Terkep terkep,int episode);

void Play(Terkep terkep);

#endif // TERKEP_H_INCLUDED
