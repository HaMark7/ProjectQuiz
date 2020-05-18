#include <stdio.h>
#include <stdlib.h>
#include "terkep.h"
#include "kerdes.h"
#include <time.h>

int main(){
    Terkep terkep;
    KERDES* k;
    int n=17;
    k=(KERDES*)malloc(n*sizeof(KERDES));
    int i;
    for(i=0;i<n;i++){
        k[i]=createKerdes();
    }
    //ReadTK("terkep02.be",&terkep);
    //Kirajzol(terkep,1);
    //ReadKerdes("kerdesek.be",k);
    //printf("%s\n",k[1].kerdes);
    //printf("%s\n",k[1].valaszok);
    //printf("%c\n\n",k[1].helyesek);
    Play(terkep);
    return 0;
}
