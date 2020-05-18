#include <stdio.h>
#include "kerdes.h"
#include <string.h>

KERDES createKerdes(){
    KERDES k;
    k.kerdes=(char*)calloc(80,sizeof(char));
    k.valaszok=(char*)calloc(80,sizeof(char));
    k.helyesek=(char*)calloc(80,sizeof(char));
    return k;
}

void ReadKerdes(char* filename,KERDES* k){
    FILE* fin=fopen(filename, "rt");
    if(!fin)
    {
        printf("!!");
        exit(1);
    }
    int n;
    fscanf(fin,"%i",&n);
    char ent,corr;
    char* quest=malloc(80*sizeof(char));
    char* answ=malloc(80*sizeof(char));

    int i;
    fscanf(fin,"%c",&ent);
    for(i=0;i<n;++i){
        fscanf(fin,"%[^\n]\n%[^\n]\n%c%c",quest,answ,&corr,&ent);
        strcpy(k[i].kerdes,quest);
        strcpy(k[i].valaszok,answ);
        k[i].helyesek=corr;
        //printf("%s\n",k[i].kerdes);
        //printf("%s\n",k[i].valaszok);
        //printf("%c\n\n",k[i].helyesek);
    }
        //printf("%s\n",k[1].kerdes);
        //printf("%s\n",k[1].valaszok);
        //printf("%c\n\n",k[1].helyesek);
}
