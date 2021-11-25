#ifndef INSPECT_H
#define INSPECT_H

#include "../ADT/boolean.h"
#include "../ADT/array.h"
#include "SaveLoad.h"

extern TabInt Layout_Map, Teleporter;
extern int lengthMap;
IdxType startTeleport;
ElType endTeleport;


void inspect ();
/* I.S. File konfigurasi telah terbaca, array Layout_Map dan array Teleporter terdefinisi. */
/* F.S. Prosedur checkInspect telah dijalankan. */

void checkInspect ();
/* I.S. Input petak dari prosedur inspect valid (petak tidak melebihi lengthMap). */
/* F.S. Petak diketahui memiliki reporter atau jika petak 
tidak memiliki reporter, petak tersebut kosong atau terlarang. */

boolean foundTeleport (TabInt T, IdxType i);
/* Mengecek apakah teleporter ditemukan dalam Map atau tidak. */
/* Petak memiliki teleporter jika elemen dari array Teleporter tidak bernilai 0. */

boolean isPetakEmpty (TabInt T, IdxType i);
/* Mengecek apakah petak tersebut kosong (true) atau terlarang (false). */
/* Kondisi : teleporter tidak ditemukan dalam Map. */
/* Petak kosong jika elemen dari array Layout_Map tidak bernilai 0. */

#endif