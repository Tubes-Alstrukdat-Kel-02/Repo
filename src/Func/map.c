#include <stdio.h>
#include "map.h" 

/* ********** KONSTRUKTOR ********** */
void CreateMap(TabMap *T)
/* I.S. Sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin */
{
    (*T).Neff = 0;
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
void SetStatus(TabMap *T, char x, IdxType i)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen status tabel ke i menjadi x */
/* Mengeset elemen status tabel ke i dengan x */
{
    (*T).Elmt[i].status = x;
}

void SetTeleport(TabMap *T, IdxType x, IdxType i)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen teleport tabel ke i menjadi x */
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
    for (i = 0; i < GetLastIdxMap(Tin); i++)
    {
        SetElMap(Tout, i, GetElmtMap(Tin, i));
        SetNeff(Tout, NbElmtMap(Tin));
    }
}

void SetElMap (TabMap *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    (*T).Elmt[i] = v;
}

void SetNeffMap (TabMap *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    (*T).Neff = N;
}

/* *** Banyaknya elemen *** */
int NbElmtMap (TabMap T)
/* Mengirimkan banyaknya elemen efektif tabel */
/*Mengirimkan nol jika tabel kosong */
{
    return (T.Neff);
}

int MaxNbElMap (TabMap T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return (IdxMax - IdxMin+1);
}

/* *** Mendapatkan index *** */
IdxType GetLastIdx (TabMap T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return (IdxMin + NbElmtMap(T)-1);
}

/* *** Mendapatkan elemen *** */
ElType GetElmtMap (TabMap T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return (T.Elmt[i]);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMap T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T)*/
{
    return ((i >= 1) && (i <= GetLastIdx(T)));
}

/* *** Menampilkan Output Ke Layar *** */
void ShowMap(TabMap T)
/* I.S. T terdefinisi, sembarang */
/* F.S. Map tertampil di layar */
/* Menampilkan map ke layar */
{
    int i = 0;
    for(i = 0; i <= T.Neff; i++)
    {
        printf("%c", T.Elmt[i].status);
    }
    printf("\n");
}