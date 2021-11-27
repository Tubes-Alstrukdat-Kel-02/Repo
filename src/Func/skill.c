#include "gameplay.h"
#include "skill.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void skill_menu(int playerTurn) {
  printf("Kamu memiliki skill :\n");
  if (NBElmtList(skill_list[playerTurn]) != 0) {
      show_skill_list(playerTurn);
  } else {
      printf("Maaf, anda tidak memiliki skill yang dapat dipakai.\n");
  }
  printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
  printf("Masukkan skill : ");
  scanf("%d", &no_pilihan);
  if ((no_pilihan > 0) && (no_pilihan < NBElmtList(skill_list[playerTurn])) ) {
      addressList p = SearchOrder(no_pilihan, playerTurn);
      switch (Skill_id(p)) {
      case (1) :
          //Pintu ga ke mana mana
          break;
      case (2) :
          //Mesin waktu
          break;
      case (3) :
          //Baling baling jambu
          break;
      case (4) :
          //Cermin pengganda
          break;
      case (5) :
          //Senter pembesar hoki
          break;
      case (6) :
          //Senter pengecil hoki
          break;
      case (7) :
          //Mesin penukar posisi
          break;
      inputCommand();
      }
  }
  else if (no_pilihan < 0) {
      no_pilihan = -no_pilihan;
      if (no_pilihan > NBElmtList(skill_list[playerTurn])) {
          printf("Tidak ada skill dengan nomor tersebut. Harap masukkan nomor yang terdapat pada skill list.\n");
          skill_menu(playerTurn);
      } else {
          addressList p = SearchOrder(no_pilihan, playerTurn);
          DelP(&skill_list[playerTurn], Skill_id(p));
          inputCommand();
      }
  }
  else if (no_pilihan > NBElmtList(skill_list[playerTurn])) {
      printf("Tidak ada skill dengan nomor tersebut. Harap masukkan nomor yang terdapat pada skill list.\n");
      skill_menu(playerTurn);
  }
  else {
      inputCommand();
  }
}

void check_jumlah_skill(int playerTurn) {
    if (NBElmtList(skill_list[playerTurn]) >= 10) {
        printf("Tidak mendapat skill karena sudah penuh (maksimal 10).\n");
    } else {
        int gacha_skill;
        srand(time(NULL));
        gacha_skill = (rand() % (100 + 1 - 1) + 1);
        if (gacha_skill <= 10) { //Pintu ga ke mana mana 10%
            InsVLast(&skill_list[playerTurn], 1, 0);
            printf("Anda mendapatkan skill Pintu Ga Ke Mana Mana!");
        } else if ((gacha_skill >= 11) && (gacha_skill <= 20)) { //Mesin waktu 10%
            int jumlah_mundur = roll_skill_langkah(10 /*diganti jadi MaxRoll*/);
            InsVLast(&skill_list[playerTurn], 2, jumlah_mundur);
            printf("Anda mendapatkan skill Mesin Waktu %d!", jumlah_mundur);
        } else if ((gacha_skill >= 21) && (gacha_skill <= 30)) { //Baling baling jambu 10%
            int jumlah_maju = roll_skill_langkah(10 /*diganti jadi MaxRoll*/);
            InsVLast(&skill_list[playerTurn], 3, jumlah_maju);
            printf("Anda mendapatkan skill Baling Baling Jambu %d!", jumlah_maju);
        } else if ((gacha_skill >= 31) && (gacha_skill <= 36)) { //Cermin pengganda 6%
            InsVLast(&skill_list[playerTurn], 4, 0);
            printf("Anda mendapatkan skill Cermin Pengganda!");
        } else if ((gacha_skill >= 37) && (gacha_skill <= 51)) { //Senter pembesar hoki 15%
            InsVLast(&skill_list[playerTurn], 5, 0);
            printf("Anda mendapatkan skill Senter Pembesar Hoki!");
        } else if ((gacha_skill >= 52) && (gacha_skill <= 66)) { //Senter pengecil hoki 15%
            InsVLast(&skill_list[playerTurn], 6, 0);
            printf("Anda mendapatkan skill Senter Pengecil Hoki!");
        } else if ((gacha_skill >= 67) && (gacha_skill <= 70)) { //Mesin penukar posisi 4%
            InsVLast(&skill_list[playerTurn], 7, 0);
            printf("Anda mendapatkan skill Mesin Penukar Posisi!");
        } else if ((gacha_skill >= 71) && (gacha_skill <= 100)) { //Teknologi Gagal 30%
            printf("Teknologi Gagal. Anda tidak mendapatkan skill.");
        }
    }
}

int roll_skill_langkah () {
    srand(time(NULL));
    return (rand() % (10 + 1 - 1) + 1);
}

addressList SearchOrder(int no_pilihan, int playerTurn) {
    int count = 1;
    addressList p;
    p = First(skill_list[playerTurn]);
    while (count != no_pilihan) {
        count++;
        p = Next(p);
    }
    return p;
}

void show_skill_list(int playerTurn) {
    addressList p;
    p = First(skill_list[playerTurn]);
    int count = 1;
    while (p != Nil) {
        if (Skill_id(p) == 1) {
            printf("%d. Pintu Ga Ke Mana Mana\n", count);
        } else if (Skill_id(p) == 2) {
            printf("%d. Mesin Waktu %d\n", count, Amount(p));
        } else if (Skill_id(p) == 3) {
            printf("%d. Baling Baling Jambu %d\n", count, Amount(p));
        } else if (Skill_id(p) == 4) {
            printf("%d. Cermin Pengganda\n", count);
        } else if (Skill_id(p) == 5) {
            printf("%d. Senter Pembesar Hoki\n", count);
        } else if (Skill_id(p) == 6) {
            printf("%d. Senter Pengecil Hoki\n", count);
        } else if (Skill_id(p) == 7) {
            printf("%d. Mesin Penukar Posisi\n", count);
        }
        count++;
        p = Next(p);
    }
}
