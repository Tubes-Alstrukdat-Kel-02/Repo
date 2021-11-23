#include <stdio.h>
#include "readfile.h"
#include <string.h>
static FILE * pita;

    TabInt Layout_Map, Teleporter;
    int lengthMap;
    int MaxRoll;
    int TotalTeleport;

void readFile()
{
    //char Namafile;
    //printf("Masukkan nama file konfigurasi : ");
    //scanf("%s", &Namafile);
    CreateMap(&Layout_Map);
    CreateMap(&Teleporter);

    char filename[20];
    printf("Masukan nama file konfigurasi : ");
    scanf("%s", filename);
    FILE *fp;
    fp = fopen(filename, "r");

    STARTKATA(fp);
    lengthMap = StrToInt(CKata);

    STARTKATA(fp);
    int i;
    for(i = 0; i < lengthMap; i++)
    {
        if (CKata.TabKata[i] == '.')
        {
            // kalo map nya . masukin i + 1
            SetMap(&Layout_Map, i, i+1);
        }
        else if (CKata.TabKata[i] == '#')
        {
            // kalo mapnya # masukin 0
            SetMap(&Layout_Map, i, 0);
        }
        Layout_Map.Neff = Layout_Map.Neff+1;
    } 

    STARTKATA(fp);
    MaxRoll = StrToInt(CKata);

    STARTKATA(fp);
    TotalTeleport = StrToInt(CKata);

    int j;
    for (j = 0; j < TotalTeleport; j++)
    {
        STARTKATA(fp);
        int idxTeleport;
        int teleportDest;

        idxTeleport = StrToInt(CKata);

        ADVKATA();
        teleportDest = StrToInt(CKata);

        if (!CheckTeleport(Teleporter, teleportDest))
        {
            SetTeleport(&Teleporter, idxTeleport-1, teleportDest);
        }
    }

    fclose(fp);
}
