#include "undo.h"
#include "gameplay.h"


Stack undoState;

void insertPlayerLocation(Stack undoState, int nbPlayer, int playerLocation[5]){
    for (int i = 0; i < nbPlayer; i++) {
        InfoTopStack(undoState) = playerLocation[i];
    }
}

void undo(Stack undoState){
    PopStack(&undoState, InfoTopStack(undoState));
    for (int i = 0; i < nbPlayer; i++){
        playerLocation[i] = InfoTopStack(undoState);
    }
}

void initializeStack(Stack undoState){
    CreateEmptyStack(&undoState);
}

