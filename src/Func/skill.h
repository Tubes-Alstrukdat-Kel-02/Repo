#ifndef skill_H
#define skill_H

#include "../ADT/boolean.h"
#include "listdp_skill.h"

List skill_list[5];
int no_pilihan;

void skill_menu (playerTurn);
// untuk menampilkan menu skill pada saat turn player

void check_jumlah_skill(playerTurn);
// untuk mengecek jumlah skill yg dipunya dan menentukan apakah dapat mendapat skill baru atau tidak. Bila bisa maka akan 
// langsung gacha skill di sini.

address SearchOrder(no_pilihan, playerTurn);
// untuk mencari address dari skill pilihan player

void show_skill_list(playerTurn);
// untuk menampilkan daftar skill yang dimiliki suatu player

/* 
Keterangan skill_id :
1 -> Pintu ga ke mana mana
2 -> Mesin waktu
3 -> Baling baling jambu
4 -> Cermin pengganda
5 -> Senter pembesar hoki
6 -> Senter pengecil hoki
7 -> Mesin penukar posisi
*/

#endif