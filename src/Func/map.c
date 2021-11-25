#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include "gameplay.h"

TabInt Layout_Map;
int nbPlayer;
char playerName[5][30];
int playerLocation[5];


void MAP()
/* Akan mencetak map dengan letak pemain untuk setiap pemain */
{
    int i;
    for (i = 0; i < nbPlayer; i++)
    {
        printf("%s : ", playerName[i]);
        PrintPosPlayer(Layout_Map, playerLocation[i]);
        printf(" %d\n", playerLocation[i]);
    }
}

void CreateMap(TabInt *T)
/* I.S. Sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin */
{
    (*T).Neff = 0;
}

void SetMap(TabInt *T, IdxType i, int x)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen status tabel ke i menjadi x */
/* Mengeset elemen status tabel ke i dengan x */
{
    (*T).TI[i] = x;
}

void SetTeleport(TabInt *T, IdxType i, IdxType x)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen teleport tabel ke i menjadi x */
/* Mengeset elemen telport tabel ke i dengan x */
{
    (*T).TI[i] = x;
}

void PrintTeleport(TabInt T, int x)
/* I.S. T terdefinisi, sembarang */
/* F.S. Teleport tertampil ke layar */
/* Menampilkan teleport ke layar */
{
    int i = 0;
    for(i = 0; i < x; i++)
    {
        if (T.TI[i] != 0)
        {
            printf("%d %d\n", i+1, T.TI[i]);
        }
    }
}

void PrintMap(TabInt T)
/* I.S. T terdefinisi, sembarang */
/* F.S. Map tertampil di layar */
/* Menampilkan map ke layar */
{
    int k = 0;
    for(k = 0; k < T.Neff; k++)
    {
        if (T.TI[k] != 0)
        {
            printf(".");
        }
        else
        {
             printf("#");
        }
    }
    printf("\n");
}

void PrintPosPlayer(TabInt T, int PlayerLoc)
{
    int i = 0;
    for(i = 0; i < T.Neff; i++)
    {
        if (T.TI[i] == PlayerLoc)
        {
            printf("*");
        }
        else if (T.TI[i] == 0)
        {
            printf("#");
        }
        else
        {
            printf(".");
        }
    }
}

boolean CheckTeleport(TabInt T, IdxType x)
/* Mengecek apakah teleport telah ada atau belum */
{
    boolean check;
    int i = 0;
    check = false;
    while (i <= T.Neff && !check)
    {
        if (T.TI[i] == x)
        {
            check = true;
        }
        i++;
    }

    return check;
}

