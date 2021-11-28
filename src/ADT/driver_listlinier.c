#include <stdio.h>
#include <stdlib.h>
#include "listlinier_skill.h"
#include "boolean.h"

int main()
{
    // untuk mengetest fungsi pada file "listlinier_skill.c"
    List L;
    CreateEmptyList(&L);
    if (IsEmptyList(L)) {
        printf("List awal empty.\n");
    }

    for (int i = 0; i < 4; i++) {
        InsVFirst_List(&L, i+1, i+1);
        InsVLast_List(&L, 10-i, 10-i);
    }

    printf("\nList setelah diisi : \n");
    PrintInfo_List(L);
    printf("\nJumlah elemen yang ada pada List : %d\n", NBElmtList(L));

    int X,Y;
    DelVFirst_List(&L, &X, &Y);
    printf("\nSkill_id first elemen yg didelete : %d\n", X);
    printf("Amount first elemen yg didelete : %d\n", Y);
    printf("List setelah first elemen didelete : \n");
    PrintInfo_List(L);
    printf("\n");

    int A,B;
    DelVLast_List(&L, &A, &B);
    printf("\nSkill_id last elemen yg didelete : %d\n", A);
    printf("Amount last elemen yg didelete : %d\n", B);
    printf("List setelah last elemen didelete : \n");
    PrintInfo_List(L);
    printf("\n");

    printf("\nAkan mencoba menambah angka 5-3 setelah angka 1-1.\n");
    addressList p = Alokasi_List(5, 3);
    addressList prec =  Search_List(L, 1, 1);
    InsertAfter_List(&L, p, prec);
    printf("List setelah 5-3 ditambah : \n");
    PrintInfo_List(L);
    printf("\n");

    printf("\nAkan mencoba menghapus address dengan isi 9-9.\n");
    DelP_List(&L, 9, 9);
    printf("List setelah 9-9 dihapus : \n");
    PrintInfo_List(L);
    printf("\n");

    printf("\nAkan mencoba menghapus elemen sesudah angka 10-10.\n");
    p = Search_List(L, 10, 10);
    DelAfter_List(&L, &prec, p);
    printf("Skill_id elemen yg didelete : %d\n", Skill_id(prec));
    printf("Amount elemen yg didelete : %d\n", Amount(prec));
    printf("List setelah elemen sesudah angka 10-10 dihapus : \n");
    PrintInfo_List(L);
    printf("\n");

    printf("\nMencoba membuat list menjadi empty.\n");
    CreateEmptyList(&L);
    printf("List setelah dicreate empty : \n");
    PrintInfo_List(L);
    printf("\n");

    return 0;
}