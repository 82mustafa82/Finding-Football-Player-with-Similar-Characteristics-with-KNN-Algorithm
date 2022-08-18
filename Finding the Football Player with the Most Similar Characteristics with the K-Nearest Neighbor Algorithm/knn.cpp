#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Oyuncu
{
    char isim[30];
    char ulus[5];
    char mevki[5];
    char takim[20];
    char lig[20];
    int reyting, hiz, sut, pas, topSurme, savunma, fizik;
    double uzaklik;
};

struct Oyuncu* siniflandir(struct Oyuncu* oyuncular, int n, struct Oyuncu p)
{
    int uzaklik;
    struct Oyuncu* muadil;
    for (int i = 0; i < n; i++){
        oyuncular[i].uzaklik =
            sqrt((oyuncular[i].reyting - p.reyting) * (oyuncular[i].reyting - p.reyting) +
                 (oyuncular[i].hiz - p.hiz) * (oyuncular[i].hiz - p.hiz) +
                 (oyuncular[i].sut - p.sut) * (oyuncular[i].sut - p.sut) +
                 (oyuncular[i].pas - p.pas) * (oyuncular[i].pas - p.pas) +
                 (oyuncular[i].topSurme - p.topSurme) * (oyuncular[i].topSurme - p.topSurme) +
                 (oyuncular[i].savunma - p.savunma) * (oyuncular[i].savunma - p.savunma) +
                 (oyuncular[i].fizik - p.fizik) * (oyuncular[i].fizik - p.fizik)
                 );
    }
    uzaklik = oyuncular[0].uzaklik;
    if(oyuncular[0].uzaklik==0){
        uzaklik = oyuncular[1].uzaklik;
    }
    for (int i = 1; i < n; i++){
        if(oyuncular[i].uzaklik!=0){
            if(oyuncular[i].uzaklik < uzaklik){
                uzaklik = oyuncular[i].uzaklik;
                muadil = &oyuncular[i];
            }
        }
    }
    return muadil;
}

int main()
{
    FILE *f;
    char file_name[256];
    int ch;
    int oyuncuSayisi=0;
    int i;
    int j;

    if ((f = fopen("AIHW2 Data Set.csv", "r")) == NULL) {
        printf("cannot open file...\n");
        exit(EXIT_FAILURE);
    }
    ch = fgetc(f);
    while (ch != EOF){
        if(ch==10){
            oyuncuSayisi++;
        }
        ch = fgetc(f);
    }
    fclose(f);
    struct Oyuncu* oyuncular = (Oyuncu*)malloc(oyuncuSayisi*sizeof(struct Oyuncu));

    if ((f = fopen("AIHW2 Data Set.csv", "r")) == NULL) {
        printf("cannot open file...\n");
        exit(EXIT_FAILURE);
    }
    i = 0;
    ch = fgetc(f);
    while (ch != 10){
        ch = fgetc(f);
    }
    ch = fgetc(f);
    while (ch != EOF){
        oyuncular[i].reyting = 0;
        oyuncular[i].hiz = 0;
        oyuncular[i].sut = 0;
        oyuncular[i].pas = 0;
        oyuncular[i].topSurme = 0;
        oyuncular[i].savunma = 0;
        oyuncular[i].fizik = 0;
        j = 0;
        while (ch != 59){
            oyuncular[i].isim[j] = ch;
            ch = fgetc(f);
            j++;
        }
        oyuncular[i].isim[j] = '\0';
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].ulus[j] = ch;
            ch = fgetc(f);
            j++;
        }
        oyuncular[i].ulus[j] = '\0';
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].mevki[j] = ch;
            ch = fgetc(f);
            j++;
        }
        oyuncular[i].mevki[j] = '\0';
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].takim[j] = ch;
            ch = fgetc(f);
            j++;
        }
        oyuncular[i].takim[j] = '\0';
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].lig[j] = ch;
            ch = fgetc(f);
            j++;
        }
        oyuncular[i].lig[j] = '\0';
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].reyting = (oyuncular[i].reyting * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].hiz = (oyuncular[i].hiz * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].sut = (oyuncular[i].sut * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].pas = (oyuncular[i].pas * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].topSurme = (oyuncular[i].topSurme * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        j = 0;
        while (ch != 59){
            oyuncular[i].savunma = (oyuncular[i].savunma * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        j = 0;
        while (ch != 59 && ch != 10){
            oyuncular[i].fizik = (oyuncular[i].fizik * 10) + (ch-48);
            ch = fgetc(f);
            j++;
        }
        ch = fgetc(f);
        i++;
    }
    fclose(f);
    for(i = 0; i < oyuncuSayisi-1; i++){
        struct Oyuncu* muadil = siniflandir(oyuncular, oyuncuSayisi, oyuncular[i]);
        printf("%s oyuncusunun muadili : \n%s (%s, %s, %s, %s)\n\n", oyuncular[i].isim, muadil->isim, muadil->ulus, muadil->mevki, muadil->takim, muadil->lig);
    }

    return 0;
}
