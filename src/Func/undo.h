#ifndef undo_H
#define undo_H

#include "../ADT/stack.h"
#include <stdio.h>

void insertPlayerLocation(Stack undoState, int nbPlayer, int playerLocation[5]);

void undo(Stack undoState);

void initializeStack(Stack undoState);

#endif