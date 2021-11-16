#ifndef roll_H
#define roll_H

#include "../ADT/boolean.h"
#include "../ADT/queueRenamed.h"

int rollResult;

// INGET ADA INI DISINI
// NANTI KONFIGURASIIN YG BENER
#define MaxRoll 10
#define HalfMaxRoll ((MaxRoll/2)+1)

int senterPembesarExist, senterPengecilExist;
int rollResult;

void diceRoll(); // done
/* Menghasilkan bilangan rollResult sesuai dadu yang digunakan: */
/* Jika memiliki buff Senter Pembesar Hoki akan menggunakan dadu highChance  */
/* Jika memiliki buff Senter Pengecil Hoki akan menggunakan dadu lowChance  */
/* Jika tidak memiliki buff akan menggunakan dadu chance */

boolean forwardExist, backwardExist;
int backwardLocation, forwardLocation;
int locationMap[16];

void checkMove(); // Cek dulu fitur MAP (Rachmad)
/* Mengecek playerLocation +- rollResult, jika terdapat nilai hasil yang sesuai dengan yang ada di peta, maka nilai boolean forwardExist dan/atau backwardExist menjadi true */

int moveChoice;

void moveOption(); // done
/* Antarmuka pemain untuk memberikan perintah arah gerak atau menampilkan hasil pergerakan berdasarkan boolean forwardExist dan backwardExist */

void movePlayer(int moveLocation); // Cek dulu fitur MAP (Rachmad)
/*  */

#endif