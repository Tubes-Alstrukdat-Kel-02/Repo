#include "roll.h"
#include "gameplay.h"
#include <stdio.h>

void initializePlayerQueue() {
  printf("Masukkan jumlah player: ");
  scanf("%d", &nbPlayer);
  while (nbPlayer < 1 || nbPlayer > 4) {
    printf("Input tidak valid, harap masukkan bilangan 1-4.\n");
    printf("Masukkan jumlah player: ");
    scanf("%d", &nbPlayer);
  }
  CreateEmptyQueue(&playerQueue, nbPlayer+1);
  for (int i = 0; i < nbPlayer; i++) {
    printf("Masukkan nama player %d: ", i+1);
    scanf("%s", playerName[i]);
    playerLocation[i] = 0;
    AddElmtQueue(&playerQueue, i);
  }
}

void gameplayLoop() {
  do {
    printf("\n");
    playerTurn = InfoHead(playerQueue);
    inputCommand(); // done
    diceRoll(); // done
    checkMove(); // Cek dulu fitur MAP (Rachmad)
    moveOption(); // done
  } while ( playerLocation[playerTurn] != 15);
}

void inputCommand() {
  printf("!!! Sekarang giliran %s\n", playerName[playerTurn]);
  printf("Menu:\n");
  printf("1. Roll\n");
  printf("Masukkan command: ");
  scanf("%d", &command);
  while (command < 1 || command > 1) {
    switch (command){
      case 1:
        printf("%s memilih Roll.", playerName[playerTurn]);
        printf("%s mengocok dadu.", playerName[playerTurn]);
        break;
      default:    
        printf("Input tidak valid, harap masukkan bilangan 1.\n");
        printf("Masukkan command: ");
        scanf("%d", &command);
        continue;
    }

    break;
  }
}

void playerWin() {
  printf("\n");
  printf("!!! Selamat, %s telah memenangkan permainan.\n", playerName[playerTurn]);
}