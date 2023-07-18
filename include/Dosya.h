#ifndef Dosya_h
#define Dosya_h
#include "Kisi.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct DOSYA
{
    int satir;
    int satir_sayilar;
    short* sansli_sayi;
    float* bahis;
    double* bakiye;
    char** isimler;
    short* sansli_sayilar;
    void (*delete)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya new_Dosya();
void delete_Dosya(const Dosya);

#endif