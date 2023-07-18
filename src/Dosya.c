/*
*
* @author   Yusuf Yesin
* @since    22/04/2022
* <p>
*           1. Ogretim C Grubu
* </p>
*/
#include "Dosya.h"

Dosya new_Dosya()
{
    Dosya this;
    this = (Dosya)malloc(sizeof(struct DOSYA));
    this->delete = &delete_Dosya;

    FILE *fp;
    char buff[255];
    char ch = ' ';
    this->satir = -1;
    this->satir_sayilar = -1;
    char* token;
    const char s[2] = "#";

    fp = fopen("./doc/Kisiler.txt", "r");
    while(ch != EOF)
    {
        ch = fgetc(fp);
        fgets(buff, 255, (FILE*)fp);
        this->satir++;
    }

    this->sansli_sayi = (short*)malloc(sizeof(short)*this->satir);
    this->bahis = (float*)malloc(sizeof(float)*this->satir);
    this->bakiye = (double*)malloc(sizeof(double)*this->satir);
    this->isimler = malloc(sizeof(char*)*this->satir);
    for (size_t i = 0; i < this->satir; i++)
    {
        this->isimler[i] = malloc(30*sizeof(char));
    }
    

    fclose(fp);
    fp = fopen("./doc/Kisiler.txt", "r");
    for (size_t i = 0; i < this->satir; i++)
    {
        fgets(buff, 255, (FILE*)fp);
        token = strtok(buff, s);
        strcpy(this->isimler[i], token);
        token = strtok(NULL, s);
        this->bakiye[i] = atof(token);
        token = strtok(NULL, s);
        this->bahis[i] = atof(token);
        token = strtok(NULL, s);
        this->sansli_sayi[i] = atoi(token);
    }
    fclose(fp);
    fp = fopen("./doc/Sayilar.txt", "r");
    ch = ' ';
    while(ch != EOF)
    {
        ch = fgetc(fp);
        fgets(buff, 255, (FILE*)fp);
        this->satir_sayilar++;
    }
    
    this->sansli_sayilar = (short*)malloc(sizeof(short)*this->satir_sayilar);
    fclose(fp);
    fp = fopen("./doc/Sayilar.txt", "r");
    for (size_t i = 0; i < this->satir_sayilar; i++)
    {
        fgets(buff, 255, (FILE*)fp);
        this->sansli_sayilar[i] = atoi(buff);
    }
    fclose(fp);


    return this;
}
void delete_Dosya(const Dosya this)
{
    if(this == NULL) return;
    free(this);
}