#include "roll.h"
#include "inspect.h"
#include "map.h"
#include "gameplay.h"
#include "skill.h"
#include "SaveLoad.h"
#include "undo.h"
#include <stdio.h>

int lengthMap;

void welcomeGame()
{
  printf("\n");
  printf("________________________ TUGAS BESAR IF2111 ALGORITMA DAN STRUKTUR DATA KELOMPOK 2 ________________________\n");
  printf("|                                                                                                         |\n");
  printf("|   xxx   xxx    xxxxxx   xxxxxxx   xxxxxx  xxxxxxxx     xxx     xx    xx   xxxxxxx   xxxxxxx     xxx     |\n"); 
  printf("|  xxxxx xxxxx  xx    xx  xx    xx    xx       xx       xx xx    xxx   xx  xx    xx  xx    xx    xx xx    |\n"); 
  printf("|  xx xxxxx xx  xx    xx  xx    xx    xx       xx      xx   xx   xxxxx xx  xx        xx         xx   xx   |\n");
  printf("|  xx  xxx  xx  xx    xx  xxxxxxx     xx       xx     xxxxxxxxx  xx xx xx  xx        xx        xxxxxxxxx  |\n"); 
  printf("|  xx       xx  xx    xx  xx    xx    xx       xx     xx     xx  xx  xxxx  xx   xxx  xx   xxx  xx     xx  |\n"); 
  printf("|  xx       xx  xx    xx  xx    xx    xx       xx     xx     xx  xx   xxx  xx    xx  xx    xx  xx     xx  |\n"); 
  printf("|  xx       xx   xxxxxx   xxxxxxx   xxxxxx     xx     xx     xx  xx    xx   xxxxxxx   xxxxxxx  xx     xx  |\n");
  printf("|_________________________________________________________________________________________________________|\n");
  printf("\n");
  printf("                          #####!!! SELAMAT DATANG DI PERMAINAN MOBITANGGA !!!#####                         \n");
  printf("\n");
}

void MainMenu()
{
  printf("Main Menu:\n");
  printf("1. New Game\n");
  printf("2. Load Game\n");
  printf("3. Exit\n\n");
  printf("Masukkan command : ");
  scanf("%d", &commandMain);
  printf("\n");

  boolean cekCommand;
  cekCommand = false;

  if (commandMain == 1)
  {
    initializePlayerQueue();
    initializeStack(undoState);
    ReadFile();
    cekCommand = true;
  }
    else if (commandMain == 2)
  {
          // Function Load belum dibuat
    cekCommand = true;
  }
  else if (commandMain == 3)
  {
        // Function exit belum dibuat
    cekCommand = true;
  }

  while (cekCommand == false)
  {
    if (commandMain < 1 | commandMain > 3)
    {
      printf("Masukkan command : ");
      scanf("%d", &commandMain);
      printf("\n");
    }
  }
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

      printf("\n#####!!! RONDE %d !!!######\n", round);
    }
    printf("\n");
    MAP();

    turnLoop();
  } while (playerLocation[playerTurn] != lengthMap);
  insertPlayerLocation(undoState,nbPlayer,playerLocation); //masukin lokasi player tiap ronde
}

void turnLoop() {
    hasMoved = false;
    turnEnded = false;

    printf("\n#####!!! Sekarang giliran %s !!!#####\n\n", playerName[playerTurn]);
    check_jumlah_skill(playerTurn);
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
      skill_menu(playerTurn);
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
      SaveFile();
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
      undo(undoState); //Kembali ke state ronde sebelumnya
      break;
  }
}

void playerWin() {
  printf("\n!!! Selamat, %s telah memenangkan permainan. !!!\n", playerName[playerTurn]);
}
