#include <stdio.h>
#include <stdlib.h>
#include "listlinier_skill.h"
#include "boolean.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressList Alokasi (infotype X, infotype Y) {
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil, dan misalnya */
/* menghasilkan P, maka Skill_id(P)=X, Amount(P), Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *p = (ElmtList *)malloc(sizeof(ElmtList));
    if (p != Nil) {
        Skill_id(p) = X;
        Amount(p) = Y;
        Next(p) = Nil;
        return p;
    } else {
        return Nil;
    }
}

void Dealokasi (addressList P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressList P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotype X, infotype Y) {
/* Mencari apakah ada elemen list dengan Skill_id(P) = X dan Amount(P) = Y */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    addressList p = First(L);
    if (!IsEmptyList(L)) {
        while (((p) != Nil) && (Skill_id(p) != X) && (Amount(p) != Y)) {
            p = Next(p);
        }
    }
    return p;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X, infotype Y) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    addressList p;
    p = Alokasi(X,Y);
    if (p != Nil) {
        InsertFirst(L, p);
    }
}

void InsVLast (List *L, infotype X, infotype Y) {
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    addressList p;
    p = Alokasi(X,Y);
    if (p != Nil) {
        InsertLast(L, p);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X, infotype *Y) {
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai skill_id disimpan pada X, nilai amount disimpan pada Y, */
/*      dan alamat elemen pertama di-dealokasi */
    addressList p;
    p = First(*L);
    *X = Skill_id(p);
    *Y = Amount(p);
    First(*L) = Next(p);
}

void DelVLast (List *L, infotype *X, infotype *Y) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai skill_id disimpan pada X, nilai amount disimpan pada Y, */
/*      dan alamat elemen terakhir di-dealokasi */
    addressList p;
    DelLast(L, &p);
    *X = Skill_id(p);
    *Y = Amount(p);
    Dealokasi(p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressList P sebagai elemen pertama */
    if (First(*L) == Nil) {
        First(*L) = P;
        Next(P) = Nil;
    } else {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertLast (List *L, addressList P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (First(*L) == Nil) {
        InsertFirst(L, P);
    } else {
        addressList x;
        x = First(*L);
        while (Next(x) != Nil) {
            x = Next(x);
        }
        Next(x) = P;
        Next(P) = Nil;
    }
}

void InsertAfter (List *L, addressList P, addressList Prec) {
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}



/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (Next(First(*L)) == Nil) {
        CreateEmpty(L);
    } else {
        First(*L) = Next(First(*L));
    }
}

void DelLast (List *L, addressList *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    *P = First(*L);
    if (Next(First(*L)) == Nil) {
        CreateEmpty(L);
    } else {
        addressList preclast, last;
        preclast = *P;
        last = Next(*P);
        while (Next(last) != Nil) {
            last = Next(last);
            preclast = Next(preclast);
        }
        Next(preclast) = Nil;
        *P = last;
    }
}

void DelP (List *L, infotype X, infotype Y) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Skill_id(P)=X dan Amount(P)=Y  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Skill_id(P)=X dan Amount(P)=Y, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    addressList p;
    p = Search(*L, X, Y);
    if (p != Nil) {
        addressList prec;
        prec = First(*L);
        if (p == prec) {
            DelFirst(L, &p);
        } else {
            while (Next(prec) != p) {
                prec = Next(prec);
            }
            DelAfter(L, &p, prec);
        }
    }
    Dealokasi(p);
}



void DelAfter (List *L, addressList *Pdel, addressList Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (Next(Prec) != Nil) {
        Next(Prec) = Next(Next(Prec));
    } 
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    addressList p = First(L);
    printf("[");
    while (p != Nil) {
        printf("%d%d", Skill_id(p), Amount(p));
        if (Next(p) != Nil) {
            printf(",");
        }
        p = Next(p);
    }
    printf("]");
}

int NbElmtList (List L) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int jumlah = 0;
    addressList p;
    p = First(L);
    while (p != Nil) {
        jumlah++;
        p = Next(p);
    }
    return jumlah;
}
