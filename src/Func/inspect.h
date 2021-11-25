#ifndef INSPECT_H
#define INSPECT_H

#include "../ADT/boolean.h"
#include "../ADT/array.h"
#include "SaveLoad.h"

extern TabInt Layout_Map, Teleporter;
IdxType startTeleport;
ElType endTeleport;


void inspect ();
void checkInspect ();
boolean foundTeleport (TabInt T, IdxType i);
boolean isPetakEmpty (TabInt T, IdxType i);

#endif