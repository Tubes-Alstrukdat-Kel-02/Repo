#include "konfigurasiManual.h"
#include "src/Func/roll.h"
#include "src/Func/gameplay.h"
#include "src/Func/skill.h"

// GLOBAL
Queue playerQueue;
int playerLocation[5], playerTurn;

int main() {
  initializePlayerQueue();
  roundLoop();
  playerWin();
  return 0;
}
