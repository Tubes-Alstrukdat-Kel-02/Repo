/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */

#include "boolean.h"

#ifndef ARRAY_H 
#define ARRAY_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct 
{
    char status;
    IdxType teleport;
} ElType;

typedef struct 
{
	ElType Elmt [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* banyaknya elemen efektif */
} TabMap;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabMap, cara deklarasi dan akses: */
/* Deklarasi : T : TabMap */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.Elmt[i] untuk mengakses elemen ke i
 * T.Elmt[i].status untuk mengakses status dari elemen ke i apakah ".", "*", atau "#"
 * T.Elmt[i].teleport untuk mengakses elemen teleport ke i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.Elmt[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.Elmt[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
/* ********** KONSTRUKTOR ********** */
void CreateMap(TabMap *T);
/* I.S. Sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
void SetStatus(TabMap *T, char x, IdxType i);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen status tabel ke i menjadi x */
/* Mengeset elemen status tabel ke i dengan x */

void SetTeleport(TabMap *T, IdxType x, IdxType i);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen teleport tabel ke i menjadi x */
/* Mengeset elemen teleport tabel ke i dengan x */

void CopyMap(TabMap Tin, TabMap *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Menyalin Tin ke Tout */

void SetElMap (TabMap *T, IdxType i, ElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */

void SetNeffMap (TabMap *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

int NbElmtMap (TabMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/*Mengirimkan nol jika tabel kosong */

int MaxNbElMap (TabMap T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

IdxType GetLastIdx (TabMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */

ElType GetElmtMap (TabMap T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMap T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T)*/

/* *** Menampilkan Output Ke Layar *** */
void ShowMap(TabMap T);
/* I.S. T terdefinisi, sembarang */
/* F.S. Map tertampil di layar */
/* Menampilkan map ke layar */

#endif