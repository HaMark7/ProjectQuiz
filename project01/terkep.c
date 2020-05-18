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
        file="terkep01.be"; ///elso palya
    }
    else{
        file="terkep.be"; ///masodik palya
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
        }///palya beolvasas
    }
    fclose(fin);
}
void Kirajzol(Terkep terkep,int episode){
    int terulet=0;
    int stop=0;
    if(episode<=30){ ///elso palya
    ReadTK(&terkep,0);
    int i,j;
    printf("Level 1.\n\n");
    printf("Jelmagyarazat:\nhatar: .\nelfoglalt terulet: o\n\n\n");
    for(i=0;i<terkep.hossz;++i) //sor
    {
        for(j=0;j<terkep.magas;++j){ //oszlop
                if(terkep.ertek[i][j]=='1'){ ///hatar
                printf(". ");
                }
                else
                if(terkep.ertek[i][j]=='2'){ ///belso zona
                  terulet++;
                    if(stop<episode){
                        printf("o "); ///elfoglalt terulet
                        stop++;
                    }
                    else
                        printf("  "); ///el nem foglalt terulet
                }
                else
                if(terkep.ertek[i][j]=='0'){ ///feher zona
                    printf("  ");
                }
        }
        printf("\n");
        }
    }
    else{ ///masodik palya
    ReadTK(&terkep,1);
    int i,j;
    printf("Level 2.\n\n");
    printf("Jelmagyarazat:\nhatar: .\nelfoglalt terulet: o\n\n\n");
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
                        printf("o "); ///elfoglalt terulet
                        stop++;
                    }
                    else
                        printf("  "); ///el nem foglalt terulet
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
    int n=50; ///kerdesek szama
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
        i=(rand()%49); ///random kerdesek
        Kirajzol(t,episode);
        printf("\n\n");
        printf("(nagy betuket hasznalj)");
        printf("\n\n");
        printf("\nKerdes: \n");
        printf("%s\n\n",k[i].kerdes);
        printf("%s\n",k[i].valaszok);

        char option = getch();

    if(option==k[i].helyesek){///helyes
        episode+=5; ///terulet foglalas
    }
    else{ ///hibas
        episode-=5; ///terulet vesztes
    }
    Sleep(800);
    system("CLS");
    }
}
