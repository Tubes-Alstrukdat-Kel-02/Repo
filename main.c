#include "src/Func/roll.h"
#include "src/Func/gameplay.h"


// GLOBAL
Queue playerQueue;
int playerLocation[5], playerTurn;

// Konfigurasi (Manual)
int senterPembesarExist = 0;
int senterPengecilExist = 0;
int locationMap[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int main() {
  initializePlayerQueue();
  gameplayLoop();

  playerWin();

  return 0;
}