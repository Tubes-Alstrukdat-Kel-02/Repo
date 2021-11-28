/* File: buff.h */

#ifndef buff_H
#define buff_H
#include "../ADT/array.h"
#include "../ADT/listlinier_skill.h"
#include "../ADT/boolean.h"
extern int playerTurn;

int BuffImmune[4];
int BuffCermin[4];
int BuffPembesar[4];
int BuffPengecil[4];

void showBuffList(int playerTurn);
/* Untuk menampilkan daftar buff yang dimiliki seorang player */

void buffPlayer(int playerTurn);
/* Untuk set buff yang dimiliki seorang player */

boolean isImunitasTeleport(int playerTurn);
/* Untuk mengetahui player tersebut memiliki imunitas terhadap teleport atau tidak */

boolean isCerminPengganda(int playerTurn);
/* Untuk mengetahui player tersebut memiliki cermin pengganda atau tidak */

boolean isSenterPembesar(int playerTurn);
/* Untuk mengetahui player tersebut memiliki senter pembesar atau tidak */

boolean isSenterPengecil(int playerTurn);
/* Untuk mengetahui player tersebut memiliki senter pengecil atau tidak */

#endif