#ifndef player_H
#define player_H

#define MAX_NAMA 100
typedef struct play {
    char *Nama;
    int Current_petak;
    // List Skill; ini harusnya ngambil dari ADT list skill
    // ADT_buff Buff; ini harusnya ngambil dari ADT buff;
} player;

#define nama(p) (p).Nama
#define current_petak(p) (p).Current_petak

#endif