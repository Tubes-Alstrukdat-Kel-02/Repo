#ifndef READ_FILE_h
#define READ_FILE_h

#include "../ADT/mesin_kata.h"
#include "../ADT/mesin_kar.h"
#include "../ADT/queueRenamed.h"
#include "map.h"
#include "skill.h"

extern TabInt Layout_Map, Teleporter;
extern Queue playerQueue;
extern int lengthMap;
extern int MaxRoll;
extern int TotalTeleport;
extern List skill_list[5];
extern int Round;
extern int playerTurn;

void readFile();
void saveFile();
void loadFile();

#endif