#ifndef SAVE_LOAD_h
#define SAVE_LOAD_h

#include "../ADT/mesin_kata.h"
#include "../ADT/mesin_kar.h"
#include "../ADT/queueRenamed.h"
#include "../ADT/listlinier_skill.h"
#include "../ADT/boolean.h"
#include "buff.h"
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
extern Queue playerQueue;

void readFile();
void saveFile();
void loadFile();

#endif