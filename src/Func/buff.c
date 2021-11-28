#include "buff.h"
#include "skill.h"
#include <stdio.h>
#include <stdlib.h>

/* Case 3 commandSwitchCase */
int playerTurn;

int BuffImmune[4] = {0,0,0,0};
int BuffCermin[4] = {0,0,0,0};
int BuffPembesar[4] = {0,0,0,0};
int BuffPengecil[4] = {0,0,0,0};

void showBuffList(int playerTurn, int buffStat){
    if (BuffImmune[playerTurn] != 0 && BuffCermin[playerTurn] != 1 && BuffPembesar[playerTurn] != 2 && BuffPengecil[playerTurn] != 3){
        printf("Anda tidak memiliki buff.");
    } else {
        int x = 0;
        printf("Anda memiliki buff =\n");
        if (BuffImmune[playerTurn] == 0){
            x = x + 1;
            printf("%d. Imunitas Teleport\n", x);
        }else if (BuffCermin[playerTurn] == 1){
            x = x + 1;
            printf("%d. Cermin Pengganda\n", x);
        }else if (BuffPembesar[playerTurn] == 2){
            x = x + 1;
            printf("%d. Senter Pembesar Hoki\n", x);
        }else if (BuffPengecil[playerTurn] == 3){
            x = x + 1;
            printf("%d. Senter Pengecil Hoki\n", x);
        }
    }
}

// typedef struct {
//     int buffStat[3];
// } Buff;

/* Using skill effects */ 
// void buffPlayer(playerTurn){
//     if (BuffImmune[playerTurn] == 0){
//         BuffImmune[playerTurn] = false;
//     } else if (buffStat[playerTurn] == 1){
//         BuffCermin[playerTurn] = false;
//     } else if (buffStat[playerTurn] == 2){
//         BuffPembesar[playerTurn] = false;
//     } else if (buffStat[playerTurn] == 3){
//         BuffPengecil[playerTurn] = false;
//     }
// }

boolean isImunitasTeleport(int playerTurn){
    if (playerTurn != IdxUndef){
        return (BuffImmune[playerTurn]);
    }
    return 0;
}

boolean isCerminPengganda(int playerTurn){
    if (playerTurn != IdxUndef){
        return (BuffCermin[playerTurn]);
    }
    return 0;
}

boolean isSenterPembesar(int playerTurn){
    if (playerTurn != IdxUndef){
        return (BuffPembesar[playerTurn]);
    }
    return 0;
}

boolean isSenterPengecil(int playerTurn){
    if (playerTurn != IdxUndef){
        return (BuffPengecil[playerTurn]);
    }
    return 0;
}