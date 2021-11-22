#include "map.h"
#include <stdlib.h>
#include <stdio.h>

void CreateMap(TabMap *T)
/* I.S. Sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin */
{
    (*T).Neff = 0;
}

void SetState(TabMap *T, char x, IdxType i)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen status tabel ke i menjadi x */
/* Mengeset elemen status tabel ke i dengan x */
{
    (*T).Elmt[i].state = x;
}

void SetTeleport(TabMap *T, IdxType x, IdxType i)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen tujuan teleport tabel ke i menjadi x */
/* Mengeset elemen teleport tabel ke i dengan x */
{
    (*T).Elmt[i].teleport = x;
}

void CopyMap(TabMap Tin, TabMap *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Menyalin Tin ke Tout */
{
    int i;
    for (i = 0; i < GetLastIdx(Tin); i++)
    {
        SetEl(Tout, i, GetElmt(Tin, i));
        SetNeff(Tout, NbElmt(Tin));
    }
}

void PrintMap(TabMap T)
/* I.S. T terdefinisi, sembarang */
/* F.S. Map tertampil di layar */
/* Menampilkan map ke layar */
{
    int i = 0;
    for(i = 0; i <= T.Neff; i++)
    {
        printf("%c", T.Elmt[i].state);
    }
    printf("\n");
}

boolean CheckTeleport(TabMap T, IdxType x)
/* Mengecek apakah teleport telah ada atau belum */
{
    boolean check;
    int i = 0;
    check = false;
    while (i <= T.Neff)
    {
        if (T.Elmt[i].teleport == x)
        {
            check = true;
        }
        i++;
    }

    return check;
}
