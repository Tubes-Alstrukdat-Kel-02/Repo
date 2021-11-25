#include "src/Func/roll.h"
#include "src/Func/inspect.h"
#include "src/Func/gameplay.h"
#include "src/Func/map.h"
#include "src/Func/SaveLoad.h"
#include <stdio.h>
#include <string.h>

// GLOBAL
Queue playerQueue;
int playerLocation[5], playerTurn;
TabInt Layout_Map, Teleporter;
int lengthMap;
int MaxRoll;
int TotalTeleport;

int main() {
  welcomeGame();
  MainMenu();
  roundLoop();
  playerWin();
  MainMenu();
  return 0;
}
