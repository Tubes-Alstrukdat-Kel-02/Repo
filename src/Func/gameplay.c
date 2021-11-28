#include "roll.h"
#include "inspect.h"
#include "map.h"
#include "gameplay.h"
#include "skill.h"
#include "SaveLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buff.h"

int lengthMap;

void welcomeGame()
{
  printf("\n");
  printf("____________________________ TUGAS BESAR IF2111 ALGORITMA DAN STRUKTUR DATA KELOMPOK 2 _____________________________\n");
  printf("|                                                                                                                  |\n");
  printf("|   xxx   xxx     xxxxxx    xxxxxxx    xxxxxx   xxxxxxxx      xxx      xx    xx    xxxxxxx    xxxxxxx      xxx     |\n"); 
  printf("|  xxxxx xxxxx   xx    xx   xx    xx     xx        xx        xx xx     xxx   xx   xx    xx   xx    xx     xx xx    |\n"); 
  printf("|  xx xxxxx xx   xx    xx   xx    xx     xx        xx       xx   xx    xxxxx xx   xx         xx          xx   xx   |\n");
  printf("|  xx  xxx  xx   xx    xx   xxxxxxx      xx        xx      xxxxxxxxx   xx xx xx   xx         xx         xxxxxxxxx  |\n"); 
  printf("|  xx       xx   xx    xx   xx    xx     xx        xx      xx     xx   xx  xxxx   xx   xxx   xx   xxx   xx     xx  |\n"); 
  printf("|  xx       xx   xx    xx   xx    xx     xx        xx      xx     xx   xx   xxx   xx    xx   xx    xx   xx     xx  |\n"); 
  printf("|  xx       xx    xxxxxx    xxxxxxx    xxxxxx      xx      xx     xx   xx    xx    xxxxxxx    xxxxxxx   xx     xx  |\n");
  printf("|__________________________________________________________________________________________________________________|\n");
  printf("\n");
  printf("                               #####!!! SELAMAT DATANG DI PERMAINAN MOBITANGGA !!!#####                             \n");
  printf("\n");
}

void MainMenu()
{
  printf("=======   Main Menu   =======\n");
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
    printf("\n");
    readFile();
    cekCommand = true;
  }
    else if (commandMain == 2)
  {
    cekCommand = true;
    loadFile();
  }
  else if (commandMain == 3)
  {
    printf("Terima kasih telah memainkan permainan MOBITANGGA\n");
    printf("Bye bye........\n");

    time_t start, end;  
    time(&start);
    do time(&end); while(difftime(end, start) <= 1.5);

    exit(0);
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
  if (commandMain ==1)
  {
    Round = 0;
  }

  do {
    if (playerTurn == 0) {
      Round = Round + 1;
      for (int i = 0; i < 4; i++) {
        BuffCermin[i] = 0;
        BuffPembesar[i] = 0;
        BuffPengecil[i] = 0; 
      }
      
      printf("\n<><><><><><><>!!!    RONDE %d    !!!<><><><><><><>\n", Round);
    }
    printf("\n");
    MAP();

    turnLoop();
  } while (playerLocation[playerTurnRn] != lengthMap);
}

void turnLoop() {
    hasMoved = false;
    turnEnded = false;

    printf("\n---###!!!   Sekarang giliran %s   !!!###---\n\n", playerName[playerTurn]);
    check_jumlah_skill(playerTurn);
    do {
      inputCommand();
      if (playerLocation[playerTurn] == lengthMap)
      {
          turnEnded = true;
      }
    } while (turnEnded == false);

    playerTurnRn = playerTurn;
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
  printf("\n");
  while (command < 1 || command > 8) {
    printf("Input tidak valid, harap masukkan bilangan 1-8.\n");
    printf("\nMasukkan command: ");
    scanf("%d", &command);
    printf("\n");
  }
  switch (command){
    case 1:
      if (hasMoved) {
        printf("Sudah melakukan roll. Tidak bisa mengakses menu skill.\n");
        commandSwitchCase();
        break;
      } else {
        skill_menu(playerTurn);
        break;
      }
    case 2:
      MAP();
      commandSwitchCase();
      break;
    case 3:
      showBuffList(playerTurn);
      inputCommand();
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
      saveFile();
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
  printf("\n$$$$$ !!! Selamat, %s telah memenangkan permainan. !!! $$$$$\n", playerName[playerTurnRn]);
}

void rankPlayer()
{
  int loc1 = playerLocation[0];
  int loc2 = playerLocation[1];
  int loc3 = playerLocation[2];
  int loc4 = playerLocation[3];
  int i,temp, j,k;
  int loc[5] = {loc1, loc2, loc3, loc4};
  int rank[5] = {0,1,2,3};

  for (i = 0; i < nbPlayer; ++i) 
  {
    for (j = i + 1; j < nbPlayer; ++j) 
      {
        if (loc[i] <= loc[j]) 
            {
              temp = rank[i];
              rank[i] = rank[j];
              rank[j] = temp;
            }
      }
  }

  printf("\n$$$$$$$   LEADERBOARD   $$$$$$$\n\n");
  for(i = 0; i < nbPlayer; i++)
  {
    printf("Rank %d %s dengan petak akhir %d\n", i+1, playerName[rank[i]], playerLocation[rank[i]]);
  }
  printf("\n");
}