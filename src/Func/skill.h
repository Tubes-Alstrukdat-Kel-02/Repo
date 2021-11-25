#ifndef skill_H
#define skill_H

#include "../ADT/boolean.h"
#include "../ADT/listdp_skill.h"

List skill_list[5];
int no_pilihan;

void skill_menu (playerTurn);
// untuk menampilkan menu skill pada saat turn player

void check_jumlah_skill(playerTurn, MaxRoll);
// untuk mengecek jumlah skill yg dipunya dan menentukan apakah dapat mendapat skill baru atau tidak. Bila bisa maka akan 
// langsung gacha skill di sini.

int roll_skill_langkah (MaxRoll);
// untuk menggacha berapa langkah untuk modifier baling-baling jambu dan mesin waktu

address SearchOrder(no_pilihan, playerTurn);
// untuk mencari address dari skill pilihan player

void show_skill_list(playerTurn);
// untuk menampilkan daftar skill yang dimiliki suatu player

void PintuGaKeMana2();
// untuk skill Pintu ga ke mana mana

void MesinWaktu(langkah);
// untuk skill Mesin waktu

void Baling2Jambu(langkah);
// untuk skill Baling baling jambu

void CerminGanda();
// untuk skill Cermin pengganda

void SenterPembesarHoki();
// untuk skill Senter pembesar hoki

void SenterPengecilHoki();
// untuk skill Senter pengecil hoki

void MesinPenukarPosisi();
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