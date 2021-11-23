 /* Implementasi mesin_kata.h*/

#include "mesin_kata.h"
#include <stdio.h>

/* State Mesin Kata */
boolean EndKata;
Kata CKata; 

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

{
    while (CC == BLANK)
    {
        ADV();
    }
}


void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    do
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    } while ((CC != BLANK) && (CC != MARK) && (i <= 50));
    CKata.Length = i;
}  

void STARTKATA(FILE *file)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(file);
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        SalinKata();
    }
    IgnoreBlank();
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK)
    {
        EndKata = true;
    }
    else
    {
        SalinKata();
    }
    IgnoreBlank();
}

int StrToInt(Kata w) {
    int x = 0;
    int i;
    for (i = 0; i < w.Length; i++) {
        x = 10*x + ((int)w.TabKata[i]-48);
    }
    return x;
}
