#include "gameplay.h"
#include "roll.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// Perlu memiliki nilai senterPembesarExist, senterPengecilExist (dari Skill/Buff (Ryu))

void diceRoll() {
  if (senterPembesarExist) {
    srand(time(NULL));
    rollResult = (rand() % (MaxRoll + 1 - HalfMaxRoll) + HalfMaxRoll);
  } else if (senterPengecilExist) {
    srand(time(NULL));
    rollResult = (rand() % (HalfMaxRoll + 1 - 1) + 1);
  } else if (!senterPembesarExist && !senterPengecilExist) {
    srand(time(NULL));
    rollResult = (rand() % (MaxRoll + 1 - 1) + 1);
  }
}

void checkMove() {
  printf("%s mendapatkan angka %d.\n", playerName[playerTurn], rollResult);
  int mapSize = sizeof(locationMap)/sizeof(locationMap[0]);
  forwardLocation = playerLocation[playerTurn] + rollResult;
  backwardLocation = playerLocation[playerTurn] - rollResult;
  for (int i = 0; i < mapSize; i++) {
    if (forwardLocation == locationMap[i]) {
      forwardExist = true;
    }
    if (backwardLocation == locationMap[i]) {
      backwardExist = true;
    }
  }
}

// Perlu fungsi forwardExist dan backwardExist, tunggu hasil MAP selesai dulu (Rachmad)

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
        movePlayer(backwardLocation);
        printf("%s mundur %d langkah.\n", playerName[playerTurn], rollResult);
        printf("%s berada di %d.\n", playerName[playerTurn], backwardLocation);
        break;
      case 2:
        movePlayer(forwardLocation);
        printf("%s maju %d langkah.\n", playerName[playerTurn], rollResult);
        printf("%s berada di %d.\n", playerName[playerTurn], forwardLocation);
        break;
    }
  } else if (forwardExist){
    printf("%s bisa maju.\n", playerName[playerTurn]);
    printf("%s maju %d langkah.\n", playerName[playerTurn], rollResult);
    printf("%s berada di %d.\n", playerName[playerTurn], forwardLocation);
    movePlayer(forwardLocation);
  } else if (backwardExist) {
    printf("%s bisa mundur.\n", playerName[playerTurn]);
    printf("%s mundur %d langkah.\n", playerName[playerTurn], rollResult);
    printf("%s berada di %d.\n", playerName[playerTurn], backwardLocation);
    movePlayer(backwardLocation);
  } else {
    printf("%s tidak dapat bergerak.\n", playerName[playerTurn]);
  }

  backwardExist = false;
  forwardExist = false;
  
}

void movePlayer(int moveLocation) {
  playerLocation[playerTurn] = moveLocation;

  AddElmtQueue(&playerQueue, InfoHead(playerQueue));
  DelElmtQueue(&playerQueue, &InfoHead(playerQueue));
}
