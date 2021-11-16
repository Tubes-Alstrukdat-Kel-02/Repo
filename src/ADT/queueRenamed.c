/* File : queue.c */

#include "queueRenamed.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return HeadQueue(Q)==Nil&&TailQueue(Q)==Nil;
}

boolean IsFullQueue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQueue */
{
	return NBElmtQueue(Q)==MaxElQueue(Q);
}

int NBElmtQueue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if(IsEmptyQueue(Q)){
		return 0;
	}else{
		if(HeadQueue(Q)<=TailQueue(Q)){
			return TailQueue(Q)-HeadQueue(Q)+1;
		}else{
			return MaxElQueue(Q)-HeadQueue(Q)+TailQueue(Q)+1;
		}
	}
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQueue=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T=(infotype*) malloc((Max+1)*sizeof(infotype));
	if((*Q).T!=NULL){
		HeadQueue(*Q)=Nil;TailQueue(*Q)=Nil;
		MaxElQueue(*Q)=Max;
	}else{
		MaxElQueue(*Q)=0;
	}
}

/* *** Destruktor *** */
void DeAlokasiQueue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQueue(Q) diset 0 */
{
	MaxElQueue(*Q)=0;
	free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void AddElmtQueue (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	if(IsEmptyQueue(*Q)){
		HeadQueue(*Q)=1;
		TailQueue(*Q)=1;
	}else{
		if(TailQueue(*Q)!=MaxElQueue(*Q)){
			TailQueue(*Q)++;
		}else{
			TailQueue(*Q)=1;
		}
	}
	InfoTailQueue(*Q)=X;
}

void DelElmtQueue (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	*X=InfoHeadQueue(*Q);
	if(NBElmtQueue(*Q)==1){
		HeadQueue(*Q)=Nil;
		TailQueue(*Q)=Nil;
	}else{
		if(HeadQueue(*Q)!=MaxElQueue(*Q)){
			HeadQueue(*Q)++;
		}else{
			HeadQueue(*Q)=1;
		}
	}
}
