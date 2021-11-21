#include "roll.h"
#include "inspect.h"
#include "gameplay.h"
#include <stdio.h>

void initializePlayerQueue() {
  int i;
  
  printf("Masukkan jumlah player: ");
  scanf("%d", &nbPlayer);
  while (nbPlayer < 2 || nbPlayer > 4) {
    printf("Input tidak valid, harap masukkan bilangan 2-4.\n");
    printf("Masukkan jumlah player: ");
    scanf("%d", &nbPlayer);
  }
  CreateEmptyQueue(&playerQueue, nbPlayer+1);
  for (i = 0; i < nbPlayer; i++) {
    printf("Masukkan nama player %d: ", i+1);
    scanf("%s", playerName[i]);
    playerLocation[i] = 0;
    AddElmtQueue(&playerQueue, i);
  }
}

void roundLoop() {
  int round = 0;

  do {
    if (playerTurn == 0) {
      round = round + 1;
      // SILAHKAN RESET BUFF DISINI

      printf("\n!!! RONDE %d\n", round);
    }

    turnLoop();
  } while (playerLocation[playerTurn] != 15);
}

void turnLoop() {
    hasMoved = false;
    turnEnded = false;

    printf("\n!!! Sekarang giliran %s\n", playerName[playerTurn]);
    do {
      inputCommand();
    } while (turnEnded == false);
    AddElmtQueue(&playerQueue, InfoHeadQueue(playerQueue));
    DelElmtQueue(&playerQueue, &InfoHeadQueue(playerQueue));

    playerTurn = InfoHeadQueue(playerQueue);
}

void inputCommand() {
  printf("\n");
  printf("Menu:\n");
  printf("1. Skill\n");
  printf("2. Map\n");
  printf("3. Buff\n");
  printf("4. Inspect\n");
  printf("5. Roll\n");
  printf("6. Save\n");
  printf("7. End Turn\n");
  printf("8. Undo\n");
  commandSwitchCase();
}

void commandSwitchCase() {
  printf("\n");
  printf("Masukkan command: ");
  scanf("%d", &command);
  while (command < 1 || command > 8) {
    printf("Input tidak valid, harap masukkan bilangan 1.\n");
    printf("Masukkan command: ");
    scanf("%d", &command);
  }
  switch (command){
    case 1:
      printf("Fitur Skill belum dibuat.\n");
      commandSwitchCase();
      break;
    case 2:
      printf("Fitur Map belum dibuat.\n");
      commandSwitchCase();
      break;
    case 3:
      printf("Fitur Buff belum dibuat.\n");
      commandSwitchCase();
      break;
    case 4:
      inspect();
      commandSwitchCase();
      break;
    case 5:
      if (hasMoved) {
        printf("Hanya bisa satu kali untuk setiap giliran.\n");
        commandSwitchCase();
        break;
      } else {
        roll();
        break;
      }
    case 6:
      printf("Fitur Save belum dibuat.\n");
      commandSwitchCase();
      break;
    case 7:
      if (!hasMoved) {
        printf("%s belum melakukan Roll.\n", playerName[playerTurn]);
        commandSwitchCase();
        break;
      } else {
        printf("%s memilih End Turn.\n", playerName[playerTurn]);
        printf("%s menyudahi giliran.\n", playerName[playerTurn]);
        turnEnded = true;
        break;
      }
    case 8:
      printf("Fitur Undo belum dibuat.\n");
      commandSwitchCase();
      break;
  }
}

void playerWin() {
  printf("\n!!! Selamat, %s telah memenangkan permainan.\n", playerName[playerTurn]);
}
