/* File : listlinier_skill.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressList dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

#define Nil 0

typedef int infotype;
typedef struct tElmtlist *addressList;
typedef struct tElmtlist { 
	infotype skill_id;
	infotype amount;
	addressList next;
} ElmtList;
typedef struct {
	addressList First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressList P dapat diacu Skill_id(P), Amount(P), Next(P) */
/* Elemen terakhir list : jika addressListnya Last, maka Next(Last)=Nil */

#define Skill_id(P) (P)->skill_id
#define Amount(P) (P)->amount
#define Next(P) (P)->next
#define First(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressList Alokasi (infotype X, infotype Y);
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Skill_id(P)=X, Amount(P), Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (addressList P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotype X, infotype Y);
/* Mencari apakah ada elemen list dengan Skill_id(P) = X dan Amount(P) = Y */
/* Jika ada, mengirimkan addressList elemen tersebut. */ 
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X, infotype Y);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X, infotype Y);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X, infotype *Y);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai skill_id disimpan pada X, nilai amount disimpan pada Y,  */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X, infotype *Y);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai skill_id disimpan pada X, nilai amount disimpan pada Y, */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */

void InsertLast (List *L, addressList P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void InsertAfter (List *L, addressList P, addressList Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (List *L, addressList *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */

void DelP (List *L, infotype X, infotype Y);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Skill_id(P)=X dan Amount(P)=Y  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Skill_id(P)=X dan Amount(P)=Y, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfter (List *L, addressList *Pdel, addressList Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int NBElmtList (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif