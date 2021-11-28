#ifndef roll_H
#define roll_H

#include "../ADT/boolean.h"
#include "../ADT/queueRenamed.h"
// #include "../../konfigurasiManual.h"

extern int MaxRoll;

int rollResult;

void roll();

int rollResult;

void diceRoll(); // done
/* Menghasilkan bilangan rollResult sesuai dadu yang digunakan: */
/* Jika memiliki buff Senter Pembesar Hoki akan menggunakan dadu highChance  */
/* Jika memiliki buff Senter Pengecil Hoki akan menggunakan dadu lowChance  */
/* Jika tidak memiliki buff akan menggunakan dadu chance */

boolean forwardExist, backwardExist;
char teleportStrChoice;
boolean teleportBoolChoice;
int backwardLocation, forwardLocation;
int locationMap[100];

void checkMove(); // Cek dulu fitur MAP (Rachmad)
/* Mengecek playerLocation +- rollResult, jika terdapat nilai hasil yang sesuai dengan yang ada di peta, maka nilai boolean forwardExist dan/atau backwardExist menjadi true */

int moveChoice;

void moveOption(); // done
/* Antarmuka pemain untuk memberikan perintah arah gerak atau menampilkan hasil pergerakan berdasarkan boolean forwardExist dan backwardExist */

void movePlayer(int moveLocation); // Cek dulu fitur MAP (Rachmad)
/*  */

void moveOtherPlayer(int player, int moveLocation); // Cek dulu fitur MAP (Rachmad)
/*  */

void teleportOptions(int location);
void immuneOptions();
void immuneSwitch();

#endif
