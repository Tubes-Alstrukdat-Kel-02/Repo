#ifndef gameplay_H
#define gameplay_H

#include "../ADT/boolean.h"
#include "../ADT/queueRenamed.h"

Queue playerQueue;
int playerLocation[5], playerTurn;
int nbPlayer;
char playerName[5][30];
boolean turnEnded, hasMoved;
extern int lengthMap;

void welcomeGame();
/* Pembuka game */

void initializePlayerQueue(); // done
/* Membuat array playerName berisi nama pemain sejumlah 1-4, queue playerQueue untuk mengatur giliran bermain, variabel playerLocation berisi bilangan 0 (start point), dan variabel playerTurn berisi Head(playerQueue) untuk menyatakan giliran pemain pertama  */

void roundLoop();
/* Loop untuk satu ronde */

void turnLoop();
/* Loop untuk satu giliran pemain */

int command;

void inputCommand(); // done
/* Membuat variabel command berisi perintah yang akan dilakukan */
/* Hanya sebagai dummy, variabel tidak digunakan untuk fungsi */
/* Secara paksa, command yang dilakukan adalah ROLL */

void commandSwitchCase();

void playerWin(); // done
/* Pemain telah memenangkan permainan */

#endif
