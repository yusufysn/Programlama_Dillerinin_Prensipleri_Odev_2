#ifndef Oyun_H
#define Oyun_H

#include "Dosya.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct OYUN
{
    double masa_bakiye;
    double en_buyuk;
    char en_buyuk_isim[30];
    int tur;
    void (*delete)(struct OYUN*);
};
typedef struct OYUN* Oyun;
Oyun new_Oyun();
void delete_Oyun(const Oyun this);

#endif