#include "gameplay.h"
#include "roll.h"
#include "SaveLoad.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// KALO SKILL UDAH BERES
// int BuffImmune[playerTurn];
// int BuffPembesar[playerTurn];
// int BuffPengecil[playerTurn];

extern int MaxRoll;
extern int HalfMaxRoll;

void roll() {
    printf("%s memilih Roll.\n", playerName[playerTurn]);
    printf("%s mengocok dadu.\n", playerName[playerTurn]);
    diceRoll(); // Perlu konfigurasi buff senter dari fitur Skill & Buff (Ryu)
    checkMove();
    moveOption();
    hasMoved = true;
}

// Perlu memiliki nilai BuffPembesar[playerTurn], BuffPengecil[playerTurn] (dari Skill/Buff (Ryu))

void diceRoll() {
  if (BuffPembesar[playerTurn]) {
    srand(time(NULL));
    rollResult = (rand() % (MaxRoll + 1 - HalfMaxRoll) + HalfMaxRoll);
  } else if (BuffPengecil[playerTurn]) {
    srand(time(NULL));
    rollResult = (rand() % (HalfMaxRoll + 1 - 1) + 1);
  } else if (!BuffPembesar[playerTurn] && !BuffPengecil[playerTurn]) {
    srand(time(NULL));
    rollResult = (rand() % (MaxRoll + 1 - 1) + 1);
  }
}

void checkMove() {
  int i;
  
  printf("%s mendapatkan angka %d.\n", playerName[playerTurn], rollResult);
  forwardLocation = playerLocation[playerTurn] + rollResult;
  backwardLocation = playerLocation[playerTurn] - rollResult;
  for (i = 0; i < Layout_Map.Neff; i++) {
    if (forwardLocation == Layout_Map.TI[i] && forwardLocation != 0) {
      forwardExist = true;
    }
    if (backwardLocation == Layout_Map.TI[i] && backwardLocation != 0) {
      backwardExist = true;
    }
  }
}

void moveOption() {
  if (forwardExist && backwardExist) {
    printf("%s bisa maju dan mundur. \n", playerName[playerTurn]);
    printf("Ke mana %s mau bergerak: \n", playerName[playerTurn]);
    printf("1. %d \n", backwardLocation);
    printf("2. %d \n", forwardLocation);
    printf("Masukkan pilihan: \n");
    scanf("%d", &moveChoice);
    while (moveChoice < 1 || moveChoice > 2) {
        printf("Input tidak valid, harap masukkan bilangan 1 atau 2.\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &moveChoice);
    }
    switch (moveChoice) {
      case 1:
        if (GetElmt(Teleporter, backwardLocation-1) != 0 && BuffImmune[playerTurn] == 0) {
          printf("%s mundur %d langkah.\n", playerName[playerTurn], rollResult);
          printf("%s berada di %d.\n", playerName[playerTurn], backwardLocation);
          printf("%s menemukan teleporter.\n", playerName[playerTurn]);
          printf("%s tidak memiliki imunitas teleport.\n", playerName[playerTurn]);
          printf("%s teleport ke petak %d.\n", playerName[playerTurn], GetElmt(Teleporter, backwardLocation-1));
          movePlayer(GetElmt(Teleporter, backwardLocation-1));
          break;
        } else if (GetElmt(Teleporter, backwardLocation-1) != 0 && BuffImmune[playerTurn] == 1) {
          printf("%s mundur %d langkah.\n", playerName[playerTurn], rollResult);
          printf("%s berada di %d.\n", playerName[playerTurn], backwardLocation);
          printf("%s menemukan teleporter.\n", playerName[playerTurn]);
          teleportOptions(backwardLocation);
        } else {
          movePlayer(backwardLocation);
          printf("%s mundur %d langkah.\n", playerName[playerTurn], rollResult);
          printf("%s berada di %d.\n", playerName[playerTurn], backwardLocation);
          break;
        }
      case 2:
        if (GetElmt(Teleporter, forwardLocation-1) != 0 && BuffImmune[playerTurn] == 0) {
          printf("%s maju %d langkah.\n", playerName[playerTurn], rollResult);
          printf("%s berada di %d.\n", playerName[playerTurn], forwardLocation);
          printf("%s menemukan teleporter.\n", playerName[playerTurn]);
          printf("%s tidak memiliki imunitas teleport.\n", playerName[playerTurn]);
          printf("%s teleport ke petak %d.\n", playerName[playerTurn], GetElmt(Teleporter, forwardLocation-1));
          movePlayer(GetElmt(Teleporter, forwardLocation-1));
          break;
        } else if (GetElmt(Teleporter, forwardLocation-1) != 0 && BuffImmune[playerTurn] == 1) {
          printf("%s maju %d langkah.\n", playerName[playerTurn], rollResult);
          printf("%s berada di %d.\n", playerName[playerTurn], forwardLocation);
          printf("%s menemukan teleporter.\n", playerName[playerTurn]);
          teleportOptions(forwardLocation);
        } else {
          movePlayer(forwardLocation);
          printf("%s maju %d langkah.\n", playerName[playerTurn], rollResult);
          printf("%s berada di %d.\n", playerName[playerTurn], forwardLocation);
          break;
        }
    }
  } else if (forwardExist){
    printf("%s bisa maju.\n", playerName[playerTurn]);
    printf("%s maju %d langkah.\n", playerName[playerTurn], rollResult);
    printf("%s berada di %d.\n", playerName[playerTurn], forwardLocation);
    if (GetElmt(Teleporter, backwardLocation-1) != 0) {
      printf("%s menemukan teleporter.\n", playerName[playerTurn]);
      if (BuffImmune[playerTurn] == 0) {
        printf("%s tidak memiliki imunitas teleport.\n", playerName[playerTurn]);
        printf("%s teleport ke petak %d.\n", playerName[playerTurn], GetElmt(Teleporter, forwardLocation-1));
        movePlayer(GetElmt(Teleporter, forwardLocation-1));
      } else {
        printf("%s memiliki imunitas teleport.\n", playerName[playerTurn]);
        teleportOptions(forwardLocation);
      }
    } else {
      movePlayer(forwardLocation);
    }
  } else if (backwardExist) {
    printf("%s bisa mundur.\n", playerName[playerTurn]);
    printf("%s mundur %d langkah.\n", playerName[playerTurn], rollResult);
    printf("%s berada di %d.\n", playerName[playerTurn], backwardLocation);
    if (GetElmt(Teleporter, backwardLocation-1) != 0) {
      printf("%s menemukan teleporter.\n", playerName[playerTurn]);
      if (BuffImmune[playerTurn] == 0) {
        printf("%s tidak memiliki imunitas teleport.\n", playerName[playerTurn]);
        printf("%s teleport ke petak %d.\n", playerName[playerTurn], GetElmt(Teleporter, backwardLocation-1));
        movePlayer(GetElmt(Teleporter, backwardLocation-1));
      } else {
        printf("%s memiliki imunitas teleport.\n", playerName[playerTurn]);
        teleportOptions(backwardLocation);
      }
    } else {
      movePlayer(backwardLocation);
    }
  } else {
    printf("%s tidak dapat bergerak.\n", playerName[playerTurn]);
  }

  backwardExist = false;
  forwardExist = false;
}

void movePlayer(int moveLocation) {
  playerLocation[playerTurn] = moveLocation;
}

// player: playerTurn or 1, 2, 3, 4
void moveOtherPlayer(int player, int moveLocation) {
  playerLocation[player] = moveLocation;
}

void teleportOptions(int location) {
  printf("Apakah %s ingin melakukan teleport (Y/N)? ", playerName[playerTurn]);
  immuneOptions(location);
}

void immuneOptions(int location) {
  scanf("%s", &teleportStrChoice);
  if (teleportStrChoice == 'y' || teleportStrChoice == 'Y') {
    teleportBoolChoice = 1;
    immuneSwitch(location);
  } else if (teleportStrChoice == 'n' || teleportStrChoice == 'N') {
    teleportBoolChoice = 0;
    BuffImmune[playerTurn] = 0;
    immuneSwitch(location);
  } else {
    printf("Jawaban tidak valid.\n");
    printf("Apakah %s ingin melakukan teleport (Y/N)? ", playerName[playerTurn]);
    immuneOptions(location);
  }
}

void immuneSwitch(int location) {
  switch (teleportBoolChoice) {
    case 1:
      printf("%s teleport ke petak %d.\n", playerName[playerTurn], GetElmt(Teleporter, location-1));
      movePlayer(GetElmt(Teleporter, location-1));
      break;
    case 0:
      printf("%s tidak melakukan teleport.\n", playerName[playerTurn]);
      movePlayer(location);
      break;
  }
}