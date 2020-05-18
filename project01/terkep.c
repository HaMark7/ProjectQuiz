#include <stdio.h>
#include "terkep.h"
#include "kerdes.h"
#include <windows.h>
#include <time.h>

Terkep CreateTK(int n,int m){
    Terkep t;
    t.hossz=n;
    t.magas=m;
    t.ertek=(Terkep**)(calloc(n,sizeof(Terkep*)));
    int i;
    for(i=0;i<t.hossz;++i){
        t.ertek[i]=(Terkep*)(calloc(m,sizeof(Terkep)));
    }
    return t;
}

void ReadTK(Terkep* terkep,int lvl){
    const char* file;
    if(lvl==0){
        file="terkep01.be";
    }
    else{
        file="terkep.be";
    }
    FILE* fin=fopen(file, "rt");
    if(!fin){
        printf("!!!!");
        exit(1);
    }
    int n,m;
    fscanf(fin,"%i %i\n",&n,&m);
    *terkep = CreateTK(n,m);
    int i,j;
    for(i=0;i<terkep->hossz;++i){
        for(j=0;j<=terkep->magas;++j){
            fscanf(fin,"%c",&terkep->ertek[i][j]);
        }
    }
    fclose(fin);
}
void Kirajzol(Terkep terkep,int episode){
    int terulet=0;
    int stop=0;
    if(episode<=25){
    ReadTK(&terkep,0);
    int i,j;
    printf("Level 1.\n\n");
    for(i=0;i<terkep.hossz;++i) //sor
    {
        for(j=0;j<terkep.magas;++j){ //oszlop
                if(terkep.ertek[i][j]=='1'){ ///hatar
                printf(". ");
                }
                else
                if(terkep.ertek[i][j]=='2'){ ///belso terulet
                  terulet++;
                    if(stop<episode){
                        printf(". ");
                        stop++;
                    }
                    else
                        printf("  ");
                }
                else
                if(terkep.ertek[i][j]=='0'){ ///feher zona
                    printf("  ");
                }
        }
        printf("\n");
        }
    }
    else{
    ReadTK(&terkep,1);
    int i,j;
    printf("Level 2.\n\n");
    for(i=0;i<terkep.hossz;++i) //sor
    {
        for(j=0;j<terkep.magas;++j){ //oszlop
                if(terkep.ertek[i][j]=='1'){ ///hatar
                printf(". ");
                }
                else
                if(terkep.ertek[i][j]=='2'){ ///belso terulet
                  terulet++;
                    if(stop<episode){
                        printf(". ");
                        stop++;
                    }
                    else
                        printf("  ");
                }
                else
                if(terkep.ertek[i][j]=='0'){ ///feher zona
                    printf("  ");
                }
        }
        printf("\n");
        }
    }
}

void Play(Terkep t){
    srand(time(0));
    KERDES* k;
    int n=17;
    k=(KERDES*)malloc(n*sizeof(KERDES));
    int j;
    for(j=0;j<n;j++){
        k[j]=createKerdes();
    }
    ReadKerdes("kerdesek.be",k);
    int episode=0;
    int i;
    while(1){
        srand(time(0));
        i=(rand()%17-1+1)+1;
        Kirajzol(t,episode);
        printf("\nKerdes: \n");
        printf("%s\n\n",k[i].kerdes);
        printf("%s\n",k[i].valaszok);

    //printf("%i ", t.lvl);
        char option = getch();
    if(option==k[i].helyesek){///helyes
        episode+=5;
    }
    else{ ///hibas
        episode-=5;
    }
    Sleep(1000);
    system("CLS");
    }
}
