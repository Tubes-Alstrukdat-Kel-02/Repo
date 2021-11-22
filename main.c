#include "konfigurasiManual.h"
#include "src/Func/roll.h"
// #include "src/Func/inspect.h"
#include "src/Func/gameplay.h"
#include <stdio.h>
// #include <string.h>

// GLOBAL
Queue playerQueue;
int playerLocation[5], playerTurn;

int main() {
  initializePlayerQueue();
  roundLoop();
  playerWin();
  return 0;
}
