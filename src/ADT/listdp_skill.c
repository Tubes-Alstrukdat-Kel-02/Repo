#include <stdio.h>
#include <stdlib.h>
#include "listdp_skill.h" 
#include "boolean.h" 

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (First(L) == Nil && Last(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressList Alokasi (infotype X, infotype Y) {
/* Mengirimkan addressList hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressList tidak nil. */
/* Misalnya: menghasilkan P, maka Skill_id(P)=X, Amount(P)=0, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    ElmtList *p = (ElmtList *)malloc(sizeof(ElmtList));
    if (p != Nil) {
        Skill_id(p) = X;
        Amount(p) = Y;
        Next(p) = Nil;
        Prev(p) = Nil;
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
addressList Search (List L, infotype X) {
/* Mencari apakah ada elemen list dengan Skill_id(P)=X */
/* Jika ada, mengirimkan addressList elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    addressList p = First(L);
    if (!IsEmptyList(L)) {
        while (((p) != Nil) && (Skill_id(p) != X)) {
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
/* F.S. Elemen pertama list dihapus: nilai skill_id disimpan pada X, nilai amount disimpan pada Y */
/*      dan alamat elemen pertama di-dealokasi */
    addressList p;
    DelFirst(L, &p);
    *X = Skill_id(p);
    *Y = Amount(p);
    Dealokasi(p);
}

void DelVLast (List *L, infotype *X, infotype *Y) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai skill_id disimpan pada X, nilai amount disimpan pada Y */
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
    if (IsEmptyList(*L)) {
        First(*L) = P;
        Last(*L) = P;
        Next(P) = Nil;
        Prev(P) = Nil;
    } else {
        InsertBefore(L, P, First(*L));
    }
}

void InsertLast (List *L, addressList P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmptyList(*L)) {
        Next(P) = Nil;
        Prev(P) = Nil;
        First(*L) = P;
        Last(*L) = P;
    } else {
        InsertAfter(L, P, Last(*L));
    }
}

void InsertAfter (List *L, addressList P, addressList Prec) {
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    if (Next(Prec) != Nil) {
        Prev(Next(Prec)) = P;
    } else {
        Last(*L) = P;
    }
    Next(Prec) = P;
    Prev(P) = Prec;
}

void InsertBefore (List *L, addressList P, addressList Succ) {
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    Prev(P) = Prev(Succ);
    if (Prev(Succ) != Nil) {
        Next(Prev(Succ)) = P;
    } else {
        First(*L) = P;
    }
    Prev(Succ) = P;
    Next(P) = Succ;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(First(*L));
    if (First(*L) == Nil) {
        CreateEmpty(L);
    } else {
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, addressList *P) {
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    Last(*L) = Prev(Last(*L));
    if (Last(*L) == Nil) {
        CreateEmpty(L);
    } else {
        Next(Last(*L)) = Nil;
    }
}

void DelP (List *L, infotype X) {
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressList P, dengan Skill_id(P)=X*/
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Skill_id(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    addressList p;
    p = Search(*L, X);
    if (p != Nil) {
        if (Prev(p) != Nil)
            DelAfter(L, &p, Prev(p));
        else if (Next(p) != Nil)
            DelBefore(L, &p, Next(p));
        else
            CreateEmpty(L);
        Dealokasi(p);
    }
}

void DelAfter (List *L, addressList *Pdel, addressList Prec) {
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    if (Next(*Pdel) != Nil) {
        Prev(Next(*Pdel)) = Prec;
    } else {
        Last(*L) = Prec;
    }
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}

void DelBefore (List *L, addressList *Pdel, addressList Succ) {
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    if (Prev(*Pdel) != Nil) {
        Next(Prev(*Pdel)) = Succ;
    } else {
        First(*L) = Succ;
    }
    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!IsEmptyList(L)) {
        addressList P = First(L);
        do {
            printf("%d%d", Skill_id(P), Amount(P));
            P = Next(P);
            if (P != Nil)
                printf(",");
        } while (P != Nil);
    }
    printf("]");
}

void PrintBackward (List L) {
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!IsEmptyList(L)) {
        addressList P = Last(L);
        do {
            printf("%d%d", Skill_id(P), Amount(P));
            P = Prev(P);
            if (P != Nil)
                printf(",");
        } while (P != Nil);
    }
    printf("]");
}

int NBElmtList (List L) {
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