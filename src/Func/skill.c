#include "gameplay.h"
#include "skill.h"
#include "map.h"
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
  printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n\n");
  printf("Masukkan skill : ");
  scanf("%d", &no_pilihan);
  if ((no_pilihan > 0) && (no_pilihan <= NBElmtList(skill_list[playerTurn])) ) {
      addressList p = searchOrder(no_pilihan, playerTurn);
      switch (Skill_id(p)) {
      case (1) : //Pintu ga ke mana mana
          if (/*insert cek buff immune teleport*/playerTurn == playerTurn) {
              pintuGaKeMana2();
              break;
          } else {
              printf("Skill tidak dapat digunakan. Anda sudah memiliki buff Imunitas Teleport.\n\n");
              skill_menu(playerTurn);
              break;
          }
      case (2) : //Mesin waktu
          mesinWaktu(Amount(p));
          break;
      case (3) : //Baling baling jambu
          baling2Jambu(Amount(p));
          break;
      case (4) : //Cermin pengganda
          if (NBElmtList(skill_list[playerTurn]) <= 9 /*nanti ditambah kriteria 1/turn*/) {
              cerminGanda(playerTurn);
              DelP(&skill_list[playerTurn], Skill_id(p), Amount(p));
              break;
          } else {
              printf("Skill tidak dapat digunakan. Hanya dapat digunakan saat jumlah skill < 10 dan hanya 1 per turn.\n\n");
              skill_menu(playerTurn);
              break;
          }
      case (5) : //Senter pembesar hoki
          if (/*buff SBesarH aktif*/playerTurn == playerTurn) {
              printf("Skill tidak dapat digunakan. Anda sudah memiliki buff Senter Pembesar Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else if (/*buff SKecilH aktif*/playerTurn == playerTurn) {
              printf("Skill tidak dapat digunakan. Anda sudah memiliki buff Senter Pengecil Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else {
              senterPembesarHoki();
              break;
          }
      case (6) : //Senter pengecil hoki
          if (/*buff SBesarH aktif*/playerTurn == playerTurn) {
              printf("Skill tidak dapat digunakan. Anda sudah memiliki buff Senter Pembesar Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else if (/*buff SKecilH aktif*/playerTurn == playerTurn) {
              printf("Skill tidak dapat digunakan. Anda sudah memiliki buff Senter Pengecil Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else {
              senterPengecilHoki();
              break;
          }          
      case (7) : //Mesin penukar posisi
          mesinPenukarPosisi(playerTurn);
          DelP(&skill_list[playerTurn], Skill_id(p), Amount(p));
          break;
      inputCommand();
      }
  }
  else if (no_pilihan < 0) {
      no_pilihan = -no_pilihan;
      if (no_pilihan > NBElmtList(skill_list[playerTurn])) {
          printf("Tidak ada skill dengan nomor tersebut. Harap masukkan nomor yang terdapat pada skill list.\n\n");
          skill_menu(playerTurn);
      } else {
          addressList p = searchOrder(no_pilihan, playerTurn);
          int id = Skill_id(p);
          int amount = Amount(p);
          DelP(&skill_list[playerTurn], Skill_id(p), Amount(p));
          switch(id) {
          case (1) :
              printf("%s berhasil membuang skill Pintu Ga Ke Mana Mana!\n", playerName[playerTurn]);
              break;
          case (2) :
              printf("%s berhasil membuang skill Mesin Waktu %d!\n", playerName[playerTurn], amount);
              break;
          case (3) :
              printf("%s berhasil membuang skill Baling Baling Jambu %d!\n", playerName[playerTurn], amount);
              break;
          case (4) :
              printf("%s berhasil membuang skill Cermin Pengganda!\n", playerName[playerTurn]);
              break;
          case (5) :
              printf("%s berhasil membuang skill Senter Pembesar Hoki!\n", playerName[playerTurn]);
              break;
          case (6) :
              printf("%s berhasil membuang skill Senter Pengecil Hoki!\n", playerName[playerTurn]);
              break;
          case (7) :
              printf("%s berhasil membuang skill Mesin Penukar Posisi!\n", playerName[playerTurn]);
              break;
          }
          inputCommand();
      }
  }
  else if (no_pilihan > NBElmtList(skill_list[playerTurn])) {
      printf("Tidak ada skill dengan nomor tersebut. Harap masukkan nomor yang terdapat pada skill list.\n\n");
      skill_menu(playerTurn);
  }
  else {
      inputCommand();
  }
}

void check_jumlah_skill(int playerTurn) {
    if (NBElmtList(skill_list[playerTurn]) >= 10) {
        printf("Tidak mendapat skill karena sudah penuh (maksimal 10).\n\n");
    } else {
        gacha_skill(playerTurn);
    }
}

int roll_skill_langkah (int maxRoll) {
    srand(time(NULL));
    return (rand() % (maxRoll + 1 - 1) + 1);
}

addressList searchOrder(int no_pilihan, int playerTurn) {
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

void gacha_skill(int playerTurn) {
    int gacha_skill;
    srand(time(NULL));
    gacha_skill = (rand() % (100 + 1 - 1) + 1);
    if (gacha_skill <= 10) { //Pintu ga ke mana mana 10%
        InsVLast(&skill_list[playerTurn], 1, 0);
        printf("Anda mendapatkan skill Pintu Ga Ke Mana Mana!\n");
    } else if ((gacha_skill >= 11) && (gacha_skill <= 20)) { //Mesin waktu 10%
        int jumlah_mundur = roll_skill_langkah(10 /*diganti jadi MaxRoll*/);
        InsVLast(&skill_list[playerTurn], 2, jumlah_mundur);
        printf("Anda mendapatkan skill Mesin Waktu %d!\n", jumlah_mundur);
    } else if ((gacha_skill >= 21) && (gacha_skill <= 30)) { //Baling baling jambu 10%
        int jumlah_maju = roll_skill_langkah(10 /*diganti jadi MaxRoll*/);
        InsVLast(&skill_list[playerTurn], 3, jumlah_maju);
        printf("Anda mendapatkan skill Baling Baling Jambu %d!\n", jumlah_maju);
    } else if ((gacha_skill >= 31) && (gacha_skill <= 36)) { //Cermin pengganda 6%
        InsVLast(&skill_list[playerTurn], 4, 0);
        printf("Anda mendapatkan skill Cermin Pengganda!\n");
    } else if ((gacha_skill >= 37) && (gacha_skill <= 51)) { //Senter pembesar hoki 15%
        InsVLast(&skill_list[playerTurn], 5, 0);
        printf("Anda mendapatkan skill Senter Pembesar Hoki!\n");
    } else if ((gacha_skill >= 52) && (gacha_skill <= 66)) { //Senter pengecil hoki 15%
        InsVLast(&skill_list[playerTurn], 6, 0);
        printf("Anda mendapatkan skill Senter Pengecil Hoki!\n");
    } else if ((gacha_skill >= 67) && (gacha_skill <= 70)) { //Mesin penukar posisi 4%
        InsVLast(&skill_list[playerTurn], 7, 0);
        printf("Anda mendapatkan skill Mesin Penukar Posisi!\n");
    } else if ((gacha_skill >= 71) && (gacha_skill <= 100)) { //Teknologi Gagal 30%
        printf("Teknologi Gagal. Anda tidak mendapatkan skill.\n");
    }
}

void pintuGaKeMana2() {

}

void mesinWaktu(int langkah) {

}

void baling2Jambu(int langkah) {

}

void cerminGanda(int playerTurn) {
    gacha_skill(playerTurn);
    time_t start, end;
    time(&start);
    do time(&end); while(difftime(end, start) <= 1);
    gacha_skill(playerTurn);
    //insert boolean cerminGanda = 1 agar tidak bisa dipakai lg di turn ini (mungkin masuk di buff)
}

void senterPembesarHoki() {

}

void senterPengecilHoki() {

}

void mesinPenukarPosisi(int playerTurn) {
    printf("\n%s memakai skill Mesin Penukar Posisi. Berikut merupakan lokasi setiap pemain :\n\n", playerName[playerTurn]);
    MAP();
    printf("\n");
    printf("Pilih pemain yang ingin ditukar posisinya dengan anda :\n");
    for(int i = 0; i < nbPlayer; i++) {
        if (i != playerTurn) {
            printf("%d. %s\n", i+1, playerName[i]);
        } 
    }
    printf("\nMasukkan pemain (angka) : ");
    scanf("%d", &switch_place);
    switch_place = switch_place - 1;
    while ((switch_place >= nbPlayer) || (switch_place < 0) || (switch_place == playerTurn)) {
        printf("Masukkan tidak valid. Mohon masukkan angka pemain yang valid.\n");
        printf("Masukkan pemain (angka) : ");
        scanf("%d", &switch_place);
    }
    int loc_temp_1 = playerLocation[playerTurn];
    int loc_temp_2 = playerLocation[switch_place];
    playerLocation[playerTurn] = loc_temp_2;
    playerLocation[switch_place] = loc_temp_1;
    printf("Berikut merupakan posisi player terbaru setelah skill diaktifkan :\n\n");
    MAP();
}
