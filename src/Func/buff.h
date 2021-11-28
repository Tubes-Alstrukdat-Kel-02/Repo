/* File: buff.h */

#ifndef buff_H
#define buff_H
#include "../ADT/array.h"
#include "../ADT/listdp_skill.h"
#include "../ADT/boolean.h"
extern int playerTurn;

List buffStat[4];

void showBuffList(int playerTurn, int buffStat);
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