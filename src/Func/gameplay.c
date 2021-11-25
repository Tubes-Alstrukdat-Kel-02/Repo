#include "roll.h"
#include "inspect.h"
#include "map.h"
#include "gameplay.h"
#include <stdio.h>

int lengthMap;
void welcomeGame()
{
  printf("\n");
  printf("______________________________ TUGAS BESAR IF2111 ALGORITMA DAN STRUKTUR DATA KELOMPOK 2 ________________________\n");
  printf("|                                                                                                               |\n");
  printf("| xxx    xxx    xxxxxx    xxxxxxx    xxxxxx  xxxxxxxxxx    xxx      xxx    xx    xxxxxxx    xxxxxxx      xxx    |\n"); 
  printf("| xxxx  xxxx   xx    xx   xx    xx     xx        xx       xx xx     xxxx   xx   xx    xx   xx    xx     xx xx   |\n"); 
  printf("| xx xxxx xx   xx    xx   xx    xx     xx        xx      xx   xx    xxxxx  xx   xx         xx          xx   xx  |\n");
  printf("| xx  xx  xx   xx    xx   xxxxxxx      xx        xx     xxxxxxxxx   xx xx  xx   xx         xx         xxxxxxxxx |\n"); 
  printf("| xx      xx   xx    xx   xx    xx     xx        xx     xx     xx   xx  xxxxx   xx   xxx   xx   xxx   xx     xx |\n"); 
  printf("| xx      xx   xx    xx   xx    xx     xx        xx     xx     xx   xx    xxx   xx    xx   xx    xx   xx     xx |\n"); 
  printf("| xx      xx    xxxxxx    xxxxxxx    xxxxxx      xx     xx     xx   xx     xx    xxxxxxx    xxxxxxx   xx     xx |\n");
  printf("|_______________________________________________________________________________________________________________|\n");
  printf("\n");
  printf("                                #####!!! SELAMAT DATANG DI PERMAINAN MOBITANGGA !!!#####                         \n");
  printf("\n");
}

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
    playerLocation[i] = 1;
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
  } while (playerLocation[playerTurn] != lengthMap);
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
  printf("\nMasukkan command: ");
  scanf("%d", &command);
  while (command < 1 || command > 8) {
    printf("Input tidak valid, harap masukkan bilangan 1-8.\n");
    printf("\nMasukkan command: ");
    scanf("%d", &command);
  }
  switch (command){
    case 1:
      printf("Fitur Skill belum dibuat.\n");
      commandSwitchCase();
      break;
    case 2:
      MAP();
      commandSwitchCase();
      break;
    case 3:
      printf("Fitur Buff belum dibuat.\n");
      commandSwitchCase();
      break;
    case 4:
      inspect();
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
