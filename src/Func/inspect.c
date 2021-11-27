#include "gameplay.h"
#include "inspect.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

extern TabInt Layout_Map, Teleporter;
extern int lengthMap;
IdxType startTeleport;
ElType endTeleport;

void inspect () {
/* I.S. File konfigurasi telah terbaca, array Layout_Map dan array Teleporter terdefinisi */
/* F.S. Prosedur checkInspect telah dijalankan */
    printf("Masukkan petak: ");
    scanf("%d", &startTeleport);
    /* Mengecek apakah petak ada dalam Map atau tidak */
    while (startTeleport < 1 || startTeleport > lengthMap) {
        printf("Petak tidak boleh melebihi panjang peta.\n");
        printf("Masukkan petak: ");
        scanf("%d", &startTeleport);
    }
    checkInspect();
}

void checkInspect () {
/* I.S. Input petak dari prosedur inspect valid (petak tidak melebihi lengthMap). */
/* F.S. Petak diketahui memiliki reporter atau jika petak 
tidak memiliki reporter, petak tersebut kosong atau terlarang */
    if (foundTeleport(Teleporter, startTeleport-1)) {
        endTeleport = GetElmt(Teleporter, startTeleport-1);
        printf("Petak %d memiliki teleporter menuju petak %d.\n", startTeleport, endTeleport);
    } else { /* Petak tidak memiliki teleporter */
        if (isPetakEmpty(Layout_Map, startTeleport-1)) {
            printf("Petak %d merupakan petak kosong.\n", startTeleport);
        } else { /* Petak tidak kosong */
            printf("Petak %d merupakan petak terlarang.\n", startTeleport);
        }
    }
}

boolean foundTeleport (TabInt T, IdxType i) {
/* Mengecek apakah teleporter ditemukan dalam Map atau tidak */
/* Petak memiliki teleporter jika elemen dari array Teleporter tidak bernilai 0. */
    return (T.TI[i] != 0);
}

boolean isPetakEmpty (TabInt T, IdxType i) {
/* Mengecek apakah petak tersebut kosong (true) atau terlarang (false) */
/* Kondisi : teleporter tidak ditemukan dalam Map */
/* Petak kosong jika elemen dari array Layout_Map tidak bernilai 0. */
    return (T.TI[i] != 0);
}

