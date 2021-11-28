#ifndef undo_H
#define undo_H

#include "../ADT/stack.h"

extern int playerLocation[5];
extern Stack undoState;

void insertPlayerLocation(Stack undoState, int nbPlayer, int playerLocation[5]);

void undo(Stack undoState);

void initializeStack(Stack undoState);

#endif