#ifndef Kisi_h
#define Kisi_h

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct KISI
{
    char** isim;
    double* bakiye;
    float* bahis;
    short* sayi;
    void (*delete)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi new_Kisi();
void delete_Kisi(const Kisi);

#endif
