#ifndef MAP_H 
#define MAP_H

#include "../ADT/boolean.h"
#include "../ADT/array.h"

extern TabInt Layout_Map;
extern int nbPlayer;
extern char playerName[5][30];
extern int playerLocation[5];

void MAP();
/* Akan mencetak map dengan letak pemain untuk setiap pemain */

void CreateMap(TabInt *T);
/* I.S. Sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin */

void SetMap(TabInt *T, IdxType i, int x);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen tabel ke i menjadi x */
/* Mengeset elemen  tabel ke i dengan x */

void SetTeleport(TabInt *T, IdxType i, IdxType x);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen teleport tabel ke i menjadi x */
/* Mengeset elemen telport tabel ke i dengan x */

void PrintPosPlayer(TabInt T, int PlayerLoc);

void PrintTeleport(TabInt T, int x);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen tujuan teleport tabel ke i menjadi x */
/* Mengeset elemen teleport tabel ke i dengan x */

void PrintMap(TabInt T);
/* I.S. T terdefinisi, sembarang */
/* F.S. Map tertampil di layar */
/* Menampilkan map ke layar */

boolean CheckTeleport(TabInt T, IdxType x);
/* Mengecek apakah teleport telah ada atau belum */

#endif