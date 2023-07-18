/*
*
* @author   Yusuf Yesin
* @since    22/04/2022
* <p>
*           1. Ogretim C Grubu
* </p>
*/
#include "Oyun.h"
#include "Dosya.h"
#include "Kisi.h"
#include "windows.h"

void gotoxy ( byte x, byte y )
{
  COORD coord = {x, y};
  SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
}
void kursoruGizle()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO         cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(out, &cursorInfo);
}
Oyun new_Oyun()
{
    Oyun this;
    this = (Oyun)malloc(sizeof(struct OYUN));
    this->delete = &delete_Oyun;

    Kisi k = new_Kisi();
    Dosya d = new_Dosya();

    this->masa_bakiye = 0;
    this->en_buyuk = 0;
    this->en_buyuk_isim[30];
    this->tur = 0;

    for (this->tur = 0;this->tur < d->satir_sayilar;this->tur++)
    {
        this->en_buyuk = 0;
        for (int i = 0; i < d->satir; i++)
        {
            if(k->bakiye[i] >= 1000)
            {
                if(k->sayi[i] == d->sansli_sayilar[this->tur])
                {
                    this->masa_bakiye -= k->bakiye[i]*k->bahis[i]*9;
                    k->bakiye[i] += k->bakiye[i]*k->bahis[i]*9;
                }
                else if(k->sayi[i] != d->sansli_sayilar[this->tur])
                {
                    this->masa_bakiye += k->bakiye[i]*k->bahis[i];
                    k->bakiye[i] -= k->bakiye[i]*k->bahis[i];
                }
                if (k->bakiye[i] > this->en_buyuk)
                {
                    this->en_buyuk = k->bakiye[i];
                    strcpy(this->en_buyuk_isim, k->isim[i]);
                }
            }    
        }
        kursoruGizle();
        Sleep(3);
        gotoxy(40,5);  printf("#############################################\n");
        gotoxy(40,6);  printf("##"); 
        gotoxy(55,6);  printf("SANSLI SAYI: "); printf("%d", d->sansli_sayilar[this->tur]); printf("     ");
        gotoxy(83,6);  printf("##");
        gotoxy(40,7);  printf("#############################################");
        gotoxy(40,8);  printf("#############################################");
        gotoxy(40,9);  printf("##");
        gotoxy(55,9);  printf("TUR: "); printf("%d", this->tur + 1); printf("     ");
        gotoxy(83,9);  printf("##");
        gotoxy(47,10); printf("MASA BAKIYE: "); printf("%.2f", this->masa_bakiye); printf("       ");
        gotoxy(40,10); printf("##");
        gotoxy(83,10); printf("##");
        gotoxy(40,11); printf("##");    
        gotoxy(83,11); printf("##");
        gotoxy(40,12); printf("##");
        printf("-----------------------------------------");
        gotoxy(83,12); printf("##");
        gotoxy(40,13); printf("##");
        gotoxy(55,13); printf("EN ZENGIN KISI");
        gotoxy(83,13); printf("##");
        gotoxy(40,14); printf("##");
        gotoxy(55,14); printf("%s", this->en_buyuk_isim); printf("            ");
        gotoxy(83,14); printf("##");
        gotoxy(40,15); printf("##");
        gotoxy(47,15); printf("BAKIYESI: "); printf("%.2f", this->en_buyuk); printf("            ");
        gotoxy(83,15); printf("##");
        gotoxy(40,16); printf("##");    
        gotoxy(83,16); printf("##");
        gotoxy(40,17); printf("#############################################");
        if(this->en_buyuk < 1000)
        {
            gotoxy(40,5);  printf("                                             \n");
            gotoxy(40,6);  printf("                                             \n");
            gotoxy(40,7);  printf("                                             \n");
            gotoxy(55,13); printf("OYUN BITTI            ");
            gotoxy(55,14); printf("                      ");
            gotoxy(47,15); printf("                      ");
            gotoxy(40,17); printf("#############################################\n");
        }
    }

    k->delete(k);
    d->delete(d);
    return this;
}
void delete_Oyun(const Oyun this)
{
    if (this == NULL) return;
    free(this);
}