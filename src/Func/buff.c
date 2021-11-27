#include "buff.h"
#include "skill.h"
#include "array.h"
#include "listdp_skill.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Case 3 commandSwitchCase */
int show_buff_list(int PlayerTurn){
    if (IsEmpty(skill_list)){
        printf("Anda tidak memiliki buff!");
    }
    addressList p = First(skill_list[playerTurn]);
    int x = 1;
    printf("Anda memiliki buff =\n");
    while (p != Nil){
        if (Skill_id(p) == 1){
            printf("%d. Imunitas Teleport\n", x);
        }else if (Skill_id(p) == 2){
            printf("%d. Cermin Pengganda\n", x);
        }else if (Skill_id(p) == 3){
            printf("%d. Senter Pembesar Hoki\n", x);
        }else if (Skill_id(p) == 4){
            printf("%d. Senter Pengecil Hoki\n", x);
    }
    p = Next(p);
    x++;
}

/* Efek pemakaian skill */

void BuffStatus(playerTurn){
    for (int i = 1; i <= n; i++){
        IsImmune(playerTurn)[i] = false;
        IsCerminPeng(playerTurn)[i] = false;
    }
}

boolean IsImmunedTeleport (int playerTurn){
    if (playerTurn != IdxUndef){
        return (IsImmune(playerTurn));
    }
    return 0;
}

boolean IsCerminPengganda (int playerTurn){
    if (playerTurn != IdxUndef){
        return (IsCerminPeng(playerTurn));
    }
    return 0;
}