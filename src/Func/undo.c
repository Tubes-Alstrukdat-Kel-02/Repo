#include "gameplay.h"
#include "undo.h"

void insertPlayerLocation(Stack undoState, int nbPlayer, int playerLocation[5]){
    for (int i = 0; i < nbPlayer; i++) {
        InfoTopElmt(undoState)(i) = playerLocation[i];
    }
}

void undo(Stack undoState){
    Pop(undoState, InfoTop(undoState);
    for (int i = 0; i < nbPlayer; i++){
        playerLocation(i) = InfoTopElmt(undoState)(i);
    }
}

void initializeStack(Stack undoState){
    CreateEmptyStack(&undoState);
}

