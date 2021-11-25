#include "gameplay.h"
#include "inspect.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

extern TabInt Layout_Map, Teleporter;
IdxType startTeleport;
ElType endTeleport;


//TINGGAL NAMBAHIN KOMEN
void inspect () {
    printf("Masukkan petak: ");
    scanf("%d", &startTeleport);
    // banyak N buah petak tergantung dalam file konfigurasi. 
    while (IsIdxEff(Layout_Map, startTeleport-1)) {
        printf("petak tidak valid.\n");
        printf("Masukkan petak: ");
        scanf("%d", &startTeleport);
    }
    checkInspect();
}

void checkInspect () {
    if (foundTeleport(Teleporter, startTeleport-1)) {
        endTeleport = GetElmt(Teleporter, startTeleport-1);
        printf("Petak %d memiliki teleporter menuju petak %d.", startTeleport, endTeleport);
    } else {
        if (isPetakEmpty(Layout_Map, startTeleport-1)) {
            printf("Petak %d merupakan petak kosong.", startTeleport);
        } else {
            printf("Petak %d merupakan petak terlarang.", startTeleport);
        }
    }
}

boolean foundTeleport (TabInt T, IdxType i) {
    return (T.TI[i] != 0);
}

boolean isPetakEmpty (TabInt T, IdxType i) {
    return (T.TI[i] != 0);
}

