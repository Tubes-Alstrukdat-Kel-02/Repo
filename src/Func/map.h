#ifndef MAP_H 
#define MAP_H

#include "../ADT/boolean.h"
#include "../ADT/array.h"

void CreateMap(TabMap *T);
/* I.S. Sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin */

void SetState(TabMap *T, char x, IdxType i);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen status tabel ke i menjadi x */
/* Mengeset elemen status tabel ke i dengan x */

void SetTeleport(TabMap *T, IdxType x, IdxType i);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen tujuan teleport tabel ke i menjadi x */
/* Mengeset elemen teleport tabel ke i dengan x */

void CopyMap(TabMap Tin, TabMap *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Menyalin Tin ke Tout */

void PrintMap(TabMap T);
/* I.S. T terdefinisi, sembarang */
/* F.S. Map tertampil di layar */
/* Menampilkan map ke layar */

boolean CheckTeleport(TabMap T, IdxType x);
/* Mengecek apakah teleport telah ada atau belum */

#endif