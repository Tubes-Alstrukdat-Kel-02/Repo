#include "buff.h"
#include "skill.h"
#include "array.h"
#include "listdp_skill.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#include "buff.h"
#include "skill.h"
#include "array.h"
#include "listdp_skill.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Case 3 commandSwitchCase */
int playerTurn;

int isImunitasTeleport[3] = {0,0,0,0}
int isCerminPengganda[3] = {0,0,0,0}
int isSenterPembesar[3] = {0,0,0,0}
int isSenterPengecil[3] = {0,0,0,0}

int showBuffList(int playerTurn, int buffStat){
    if (buffStat[playerTurn] != 0 && buffStat[playerTurn] != 1 && buffStat[playerTurn] != 2 && buffStat[playerTurn] != 3){
        printf("Anda tidak memiliki buff.");
    } else {
        int x = 0;
        printf("Anda memiliki buff =\n");
        if (buffStat[playerTurn] == 0){
            x = x + 1;
            printf("%d. Imunitas Teleport\n", x);
        }else if (buffStat[playerTurn] == 1){
            x = x + 1;
            printf("%d. Cermin Pengganda\n", x);
        }else if (buffStat[playerTurn] == 2){
            x = x + 1;
            printf("%d. Senter Pembesar Hoki\n", x);
        }else if (buffStat[playerTurn] == 3){
            x = x + 1;
            printf("%d. Senter Pengecil Hoki\n", x);
        }
    }
}

// typedef struct {
//     int buffStat[3];
// } Buff;

/* Using skill effects */ 
void buffPlayer(&playerTurn){
    if (buffStat[playerTurn] == 0){
        BuffImune[playerTurn] = false;
    } else if (buffStat[playerTurn] == 1){
        BuffCermin[playerTurn] = false;
    } else if (buffStat[playerTurn] == 2){
        BuffPembesar[playerTurn] = false;
    } else if (buffStat[playerTurn] == 3){
        BuffPengecil[playerTurn] = false;
    }
}

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