#include "src/Func/roll.h"
#include "src/Func/inspect.h"
#include "src/Func/gameplay.h"
#include "src/Func/skill.h"
#include "src/Func/map.h"
#include "src/Func/SaveLoad.h"
#include <stdio.h>

// GLOBAL
Queue playerQueue;
int playerLocation[5], playerTurn;
TabInt Layout_Map, Teleporter;
int lengthMap;
int MaxRoll;
int TotalTeleport;
int Round;
List skill_list[5];
int BuffImmune[4];
int BuffCermin[4];
int BuffPembesar[4];
int BuffPengecil[4];

int main() {
  welcomeGame();
  MainMenu();
  while ( commandMain != 3) {
    for (int i = 0; i < 4; i++) {
      BuffImmune[i] = 0;
      BuffCermin[i] = 0;
      BuffPembesar[i] = 0;
      BuffPengecil[i] = 0; 
    }
    roundLoop();
    playerWin();
    rankPlayer();
    MainMenu();
  }
  return 0;
}
