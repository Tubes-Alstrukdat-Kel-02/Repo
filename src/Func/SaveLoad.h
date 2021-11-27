#ifndef READ_FILE_h
#define READ_FILE_h

#include "../ADT/mesin_kata.h"
#include "../ADT/mesin_kar.h"
#include "map.h"
#include "skill.h"

extern TabInt Layout_Map, Teleporter;
extern int lengthMap;
extern int MaxRoll;
extern int TotalTeleport;
extern List skill_list[5];

void ReadFile();
void SaveFile();
void LoadFile();

#endif