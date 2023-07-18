/*
*
* @author   Yusuf Yesin
* @since    22/04/2022
* <p>
*           1. Ogretim C Grubu
* </p>
*/
#include "Oyun.h"

int main()
{
    system("CLS");
    Oyun oyun = new_Oyun();

    oyun->delete(oyun);
    
    system("pause");
    return 0;
}