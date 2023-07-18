/*
*
* @author   Yusuf Yesin
* @since    22/04/2022
* <p>
*           1. Ogretim C Grubu
* </p>
*/
#include "Kisi.h"
#include "Dosya.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Kisi new_Kisi()
{
    Kisi this;
    this = (Kisi)malloc(sizeof(struct KISI));
    this->delete = &delete_Kisi;

    Dosya d = new_Dosya();
    this->sayi = (short*)malloc(sizeof(short)*d->satir);
    this->bahis = (float*)malloc(sizeof(float)*d->satir);
    this->bakiye = (double*)malloc(sizeof(double)*d->satir);
    this->isim = (char**)malloc(sizeof(char*)*d->satir);
    for (size_t j = 0; j < d->satir; j++)
    {
        this->isim[j] = malloc(sizeof(char)*30);
    }
    for (size_t i = 0; i < d->satir; i++)
    {
        this->sayi[i] = d->sansli_sayi[i];
        this->bahis[i] = d->bahis[i];
        this->bakiye[i] = d->bakiye[i];
        strcpy(this->isim[i], d->isimler[i]);
    }

    d->delete(d);
    return this;
}
void delete_Kisi(const Kisi this)
{
    if(this == NULL) return;
    free(this);
}