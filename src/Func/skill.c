#include "gameplay.h"
#include "skill.h"
#include "map.h"
#include "roll.h"
#include "buff.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

extern int HalfMaxRoll;

void skill_menu(int playerTurn) {
  printf("Kamu memiliki skill :\n");
  if (NBElmtList(skill_list[playerTurn]) != 0) {
      show_skill_list(playerTurn);
  } else {
      printf("Maaf, anda tidak memiliki skill yang dapat dipakai.\n");
      inputCommand();
  }
  printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n\n");
  printf("Masukkan skill : ");
  scanf("%d", &no_pilihan);
  if ((no_pilihan > 0) && (no_pilihan <= NBElmtList(skill_list[playerTurn])) ) {
      addressList p = searchOrder(no_pilihan, playerTurn);
      switch (Skill_id(p)) {
      case (1) :   //Pintu ga ke mana mana
          if (BuffImmune[playerTurn] != 1) {
              pintuGaKeMana2(playerTurn);
              DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
              break;
          } else {
              printf("\nSkill tidak dapat digunakan. Anda sudah memiliki buff Imunitas Teleport.\n\n");
              skill_menu(playerTurn);
              break;
          }
      case (2) :   //Mesin waktu
          mesinWaktu(playerTurn, Amount(p), p);
          break;
      case (3) :   //Baling baling jambu
          baling2Jambu(playerTurn, Amount(p), p);
          break;
      case (4) :   //Cermin pengganda
          if ((NBElmtList(skill_list[playerTurn]) <= 9) && (BuffCermin[playerTurn] != 1)) {
              cerminGanda(playerTurn);
              DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
              break;
          } else {
              printf("\nSkill tidak dapat digunakan. Hanya dapat digunakan saat jumlah skill < 10 dan hanya 1 per turn.\n\n");
              skill_menu(playerTurn);
              break;
          }
      case (5) :   //Senter pembesar hoki
          if (BuffPembesar[playerTurn] == 1) {
              printf("\nSkill tidak dapat digunakan. Anda sudah memiliki buff Senter Pembesar Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else if (BuffPengecil[playerTurn] == 1) {
              printf("\nSkill tidak dapat digunakan. Anda sudah memiliki buff Senter Pengecil Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else {
              senterPembesarHoki(playerTurn);
              DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
              break;
          }
      case (6) :   //Senter pengecil hoki
          if (BuffPembesar[playerTurn] == 1) {
              printf("\nSkill tidak dapat digunakan. Anda sudah memiliki buff Senter Pembesar Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else if (BuffPengecil[playerTurn] == 1) {
              printf("\nSkill tidak dapat digunakan. Anda sudah memiliki buff Senter Pengecil Hoki.\n\n");
              skill_menu(playerTurn);
              break;
          } else {
              senterPengecilHoki(playerTurn);
              DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
              break;
          }          
      case (7) :   //Mesin penukar posisi
          mesinPenukarPosisi(playerTurn);
          DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
          break;
      inputCommand();
      }
  }
  else if (no_pilihan < 0) {
      no_pilihan = -no_pilihan;
      if (no_pilihan > NBElmtList(skill_list[playerTurn])) {
          printf("\nTidak ada skill dengan nomor tersebut. Harap masukkan nomor yang terdapat pada skill list.\n\n");
          skill_menu(playerTurn);
      } else {
          addressList p = searchOrder(no_pilihan, playerTurn);
          int id = Skill_id(p);
          int amount = Amount(p);
          DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
          switch(id) {
          case (1) :
              printf("\n%s berhasil membuang skill Pintu Ga Ke Mana Mana!\n", playerName[playerTurn]);
              break;
          case (2) :
              printf("\n%s berhasil membuang skill Mesin Waktu %d!\n", playerName[playerTurn], amount);
              break;
          case (3) :
              printf("\n%s berhasil membuang skill Baling Baling Jambu %d!\n", playerName[playerTurn], amount);
              break;
          case (4) :
              printf("\n%s berhasil membuang skill Cermin Pengganda!\n", playerName[playerTurn]);
              break;
          case (5) :
              printf("\n%s berhasil membuang skill Senter Pembesar Hoki!\n", playerName[playerTurn]);
              break;
          case (6) :
              printf("\n%s berhasil membuang skill Senter Pengecil Hoki!\n", playerName[playerTurn]);
              break;
          case (7) :
              printf("\n%s berhasil membuang skill Mesin Penukar Posisi!\n", playerName[playerTurn]);
              break;
          }
          inputCommand();
      }
  }
  else if (no_pilihan > NBElmtList(skill_list[playerTurn])) {
      printf("\nTidak ada skill dengan nomor tersebut. Harap masukkan nomor yang terdapat pada skill list.\n\n");
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
    if (gacha_skill <= 10) {   //Pintu ga ke mana mana 10%
        InsVLast_List(&skill_list[playerTurn], 1, 0);
        printf("Anda mendapatkan skill Pintu Ga Ke Mana Mana!\n");
    } else if ((gacha_skill >= 11) && (gacha_skill <= 20)) {   //Mesin waktu 10%
        int jumlah_mundur = roll_skill_langkah(MaxRoll);
        InsVLast_List(&skill_list[playerTurn], 2, jumlah_mundur);
        printf("Anda mendapatkan skill Mesin Waktu %d!\n", jumlah_mundur);
    } else if ((gacha_skill >= 21) && (gacha_skill <= 30)) {   //Baling baling jambu 10%
        int jumlah_maju = roll_skill_langkah(MaxRoll);
        InsVLast_List(&skill_list[playerTurn], 3, jumlah_maju);
        printf("Anda mendapatkan skill Baling Baling Jambu %d!\n", jumlah_maju);
    } else if ((gacha_skill >= 31) && (gacha_skill <= 36)) {   //Cermin pengganda 6%
        InsVLast_List(&skill_list[playerTurn], 4, 0);
        printf("Anda mendapatkan skill Cermin Pengganda!\n");
    } else if ((gacha_skill >= 37) && (gacha_skill <= 51)) {   //Senter pembesar hoki 15%
        InsVLast_List(&skill_list[playerTurn], 5, 0);
        printf("Anda mendapatkan skill Senter Pembesar Hoki!\n");
    } else if ((gacha_skill >= 52) && (gacha_skill <= 66)) {   //Senter pengecil hoki 15%
        InsVLast_List(&skill_list[playerTurn], 6, 0);
        printf("Anda mendapatkan skill Senter Pengecil Hoki!\n");
    } else if ((gacha_skill >= 67) && (gacha_skill <= 70)) {   //Mesin penukar posisi 4%
        InsVLast_List(&skill_list[playerTurn], 7, 0);
        printf("Anda mendapatkan skill Mesin Penukar Posisi!\n");
    } else if ((gacha_skill >= 71) && (gacha_skill <= 100)) {   //Teknologi Gagal 30%
        printf("Teknologi Gagal. Anda tidak mendapatkan skill.\n");
    }
}

void pintuGaKeMana2(int playerTurn) {
    BuffImmune[playerTurn] = 1;
    printf("\n%s memakai skill Pintu Ga Ke Mana Mana.\n", playerName[playerTurn]);
    printf("%s mendapatkan buff imunitas teleport!\n", playerName[playerTurn]);
}

void mesinWaktu(int playerTurn, int langkah, addressList p) {
    printf("\n%s memakai skill Mesin Waktu %d.\n\n", playerName[playerTurn], langkah);
    int loop_pilih_target = 1;
    while (loop_pilih_target == 1) {
        printf("Pilih pemain yang ingin dimundurkan :\n");
        for(int i = 0; i < nbPlayer; i++) {
            if (i != playerTurn) {
                printf("%d. %s\n", i+1, playerName[i]);
            } 
        }
        printf("Tekan 0 untuk kembali ke menu skill.\n");
        printf("\nMasukkan pemain (angka) : ");
        scanf("%d", &target_player);
        if ((target_player > nbPlayer) || (target_player < 0) || ((target_player-1) == playerTurn)) {
            printf("\nMasukan tidak valid. Mohon masukkan nomor pemain yang valid.\n\n");
        } else if (target_player == 0) {
            loop_pilih_target = 0;
            printf("\n");
            skill_menu(playerTurn);
        } else {
            target_player = target_player - 1;
            int moveLocation = playerLocation[target_player] - langkah;
            int checkMoveLocation;
            for (int i = 0; i < Layout_Map.Neff; i++) {
                if (moveLocation == Layout_Map.TI[i] && moveLocation != 0) {
                    checkMoveLocation = 1;
                }
            }
            if (checkMoveLocation == 1) {
                loop_pilih_target = 0;
                moveOtherPlayer(target_player, moveLocation);
                printf("\n%s dimundurkan sebanyak %d langkah!\n", playerName[target_player], langkah);
                printf("%s sekarang berada pada petak %d.\n", playerName[target_player], moveLocation);
                int teleportLocation = GetElmt(Teleporter, moveLocation-1);
                if ((teleportLocation != 0) && (BuffImmune[playerTurn] == 0)) {
                    printf("Ada teleporter pada petak %d! %s teleport ke petak %d", moveLocation, playerName[target_player], teleportLocation);
                    moveOtherPlayer(target_player, teleportLocation);
                } else if ((teleportLocation != 0) && (BuffImmune[playerTurn] == 1)) {
                    printf("Ada teleporter pada petak %d! Anda memiliki buff Imunitas Teleport.\n", moveLocation);
                    int loop_check = 1;
                    while (loop_check == 1) {
                        printf("\nGunakan buff Imunitas Teleport? (Y/N) : ");
                        char check;
                        scanf("%s", &check);
                        if ((check == 'Y') || (check == 'y')) {
                            pilihan_teleport = 1;
                            loop_check = 0;
                        } else if ((check == 'N') || (check == 'n')) {
                            pilihan_teleport = 0;
                            loop_check = 0;
                        } else {
                            printf("Masukan tidak valid. Mohon hanya masukkan (Y/N).\n");
                        }
                    }
                    switch(pilihan_teleport) {
                    case (1):
                        printf("\n%s menggunakan buff Imunitas Teleport! %s tetap berada pada petak %d.\n", playerName[target_player], playerName[target_player], moveLocation);
                        BuffImmune[target_player] = 0;
                        break;
                    case (0):
                        printf("\n%s tidak menggunakan buff Imunitas Teleport! %s teleport ke petak %d.\n", playerName[target_player], playerName[target_player], teleportLocation);
                        moveOtherPlayer(target_player, teleportLocation);
                        break;
                    }
                    DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
                } else {
                    printf("Tidak ada teleporter pada petak %d\n", moveLocation);
                }
            } else {
                printf("\nPlayer yang anda pilih tidak bisa dimundurkan!\n\n");
            }
        }
    }
}

void baling2Jambu(int playerTurn, int langkah, addressList p) {
    printf("\n%s memakai skill Baling Baling Jambu %d.\n\n", playerName[playerTurn], langkah);
    int loop_pilih_target = 1;
    while (loop_pilih_target == 1) {
        printf("Pilih pemain yang ingin dimajukan :\n");
        for(int i = 0; i < nbPlayer; i++) {
            if (i != playerTurn) {
                printf("%d. %s\n", i+1, playerName[i]);
            } 
        }
        printf("Tekan 0 untuk kembali ke menu skill.\n");
        printf("\nMasukkan pemain (angka) : ");
        scanf("%d", &target_player);
        if ((target_player > nbPlayer) || (target_player < 0) || ((target_player-1) == playerTurn)) {
            printf("\nMasukan tidak valid. Mohon masukkan nomor pemain yang valid.\n\n");
        } else if (target_player == 0) {
            loop_pilih_target = 0;
            printf("\n");
            skill_menu(playerTurn);
        } else {
            target_player = target_player - 1;
            int moveLocation = playerLocation[target_player] + langkah;
            int checkMoveLocation;
            for (int i = 0; i < Layout_Map.Neff; i++) {
                if (moveLocation == Layout_Map.TI[i] && moveLocation != 0) {
                    checkMoveLocation = 1;
                }
            }
            if (checkMoveLocation == 1) {
                loop_pilih_target = 0;
                moveOtherPlayer(target_player, moveLocation);
                printf("\n%s dimajukan sebanyak %d langkah!\n", playerName[target_player], langkah);
                printf("%s sekarang berada pada petak %d.\n", playerName[target_player], moveLocation);
                int teleportLocation = GetElmt(Teleporter, moveLocation-1);
                if ((teleportLocation != 0) && (BuffImmune[playerTurn] == 0)) {
                    printf("Ada teleporter pada petak %d! %s teleport ke petak %d", moveLocation, playerName[target_player], teleportLocation);
                    moveOtherPlayer(target_player, teleportLocation);
                } else if ((teleportLocation != 0) && (BuffImmune[playerTurn] == 1)) {
                    printf("Ada teleporter pada petak %d! Anda memiliki buff Imunitas Teleport.\n", moveLocation);
                    int loop_check = 1;
                    while (loop_check == 1) {
                        printf("\nGunakan buff Imunitas Teleport? (Y/N) : ");
                        char check;
                        scanf("%s", &check);
                        if ((check == 'Y') || (check == 'y')) {
                            pilihan_teleport = 1;
                            loop_check = 0;
                        } else if ((check == 'N') || (check == 'n')) {
                            pilihan_teleport = 0;
                            loop_check = 0;
                        } else {
                            printf("Masukan tidak valid. Mohon hanya masukkan (Y/N).\n");
                        }
                    }
                    switch(pilihan_teleport) {
                    case (1):
                        printf("\n%s menggunakan buff Imunitas Teleport! %s tetap berada pada petak %d.\n", playerName[target_player], playerName[target_player], moveLocation);
                        BuffImmune[target_player] = 0;
                        break;
                    case (0):
                        printf("\n%s tidak menggunakan buff Imunitas Teleport! %s teleport ke petak %d.\n", playerName[target_player], playerName[target_player], teleportLocation);
                        moveOtherPlayer(target_player, teleportLocation);
                        break;
                    }
                    DelP_List(&skill_list[playerTurn], Skill_id(p), Amount(p));
                } else {
                    printf("Tidak ada teleporter pada petak %d\n", moveLocation);
                }
            } else {
                printf("\nPlayer yang anda pilih tidak bisa dimajukan!\n\n");
            }
        }
    }
}

void cerminGanda(int playerTurn) {
    printf("\n");
    gacha_skill(playerTurn);
    time_t start, end;
    time(&start);
    do time(&end); while(difftime(end, start) <= 1);
    gacha_skill(playerTurn);
    BuffCermin[playerTurn] = 1;
}

void senterPembesarHoki(int playerTurn) {
    BuffPembesar[playerTurn] = 1;
    printf("\n%s memakai skill Senter Pembesar Hoki.\n", playerName[playerTurn]);
    printf("Dadu akan mengeluarkan angka %d sampai %d!\n", HalfMaxRoll, MaxRoll);
}

void senterPengecilHoki(int playerTurn) {
    BuffPengecil[playerTurn] = 1;
    printf("\n%s memakai skill Senter Pengecil Hoki.\n", playerName[playerTurn]);
    printf("Dadu akan mengeluarkan angka %d sampai %d!\n", 1, HalfMaxRoll);
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
        printf("Masukan tidak valid. Mohon masukkan angka pemain yang valid.\n");
        printf("Masukan pemain (angka) : ");
        scanf("%d", &switch_place);
    }
    int loc_temp_1 = playerLocation[playerTurn];
    int loc_temp_2 = playerLocation[switch_place];
    playerLocation[playerTurn] = loc_temp_2;
    playerLocation[switch_place] = loc_temp_1;
    printf("Berikut merupakan posisi player terbaru setelah skill diaktifkan :\n\n");
    MAP();
}
