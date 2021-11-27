#ifndef skill_H
#define skill_H

#include "../ADT/boolean.h"
#include "../ADT/listdp_skill.h"

List skill_list[5];
int no_pilihan;

void skill_menu (int playerTurn);
// untuk menampilkan menu skill pada saat turn player

void check_jumlah_skill(int playerTurn);
// untuk mengecek jumlah skill yg dipunya dan menentukan apakah dapat mendapat skill baru atau tidak. Bila bisa maka akan menggacha skill di sini.


int roll_skill_langkah (int MaxRoll);
// untuk menggacha berapa langkah untuk modifier baling-baling jambu dan mesin waktu

addressList searchOrder(int no_pilihan, int playerTurn);
// untuk mencari addressList dari skill pilihan player

void show_skill_list(int playerTurn);
// untuk menampilkan daftar skill yang dimiliki suatu player

void gacha_skill(int playerTurn);
// untuk menggacha skill

void pintuGaKeMana2();
// untuk skill Pintu ga ke mana mana

void mesinWaktu(int langkah);
// untuk skill Mesin waktu

void baling2Jambu(int langkah);
// untuk skill Baling baling jambu

void cerminGanda(int playerTurn);
// untuk skill Cermin pengganda

void senterPembesarHoki();
// untuk skill Senter pembesar hoki

void senterPengecilHoki();
// untuk skill Senter pengecil hoki

void mesinPenukarPosisi();
// untuk skill Mesin penukar posisi

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