#include "gameplay.h"
#include "inspect.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void inspect () {
    printf("Masukkan petak: ");
    scanf("%d", &startTeleport);
    // banyak N buah petak tergantung dalam file konfigurasi. 
    // Di sini N = 15
    while (startTeleport < 1 || startTeleport > 15 ) {
        printf("petak tidak valid.\n");
        printf("Masukkan petak: ");
        scanf("%d", &startTeleport);
    }
    checkInspect();
}

void checkInspect () {
    int i = 0;
    foundTeleport();
    if (foundTeleport) {
        printf("Petak %d memiliki teleporter menuju %d.", startTeleport, endTeleport);
    } else {
        if (isPetakEmpty) {
            printf("Petak %d merupakan petak kosong.", startTeleport);
        } else {
            printf("Petak %d merupakan petak terlarang.", startTeleport);
        }
    }
}

// BELUM BERES
//cek
//cek 2
boolean foundTeleport () {
   // return 
}

boolean isPetakEmpty () {
   // return konfigPeta.T[i] == '.';
}

