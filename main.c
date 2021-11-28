#include "src/Func/roll.h"
#include "src/Func/inspect.h"
#include "src/Func/gameplay.h"
#include "src/Func/skill.h"
#include "src/Func/map.h"
#include "src/Func/SaveLoad.h"
#include <stdio.h>

// GLOBAL
Queue playerQueue;
int playerLocation[5], playerTurn, playerTurnRn;
TabInt Layout_Map, Teleporter;
int lengthMap;
int MaxRoll;
int TotalTeleport;
int Round;
Stack undoState;

int main() {
  welcomeGame();
  MainMenu();
  while ( commandMain != 3)
  {
    roundLoop();
    playerWin();
    rankPlayer();
    MainMenu();
  }
  return 0;
}
