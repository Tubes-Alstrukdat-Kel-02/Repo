#include <stdio.h>
#include "SaveLoad.h"
#include <string.h>
static FILE * pita;

TabInt Layout_Map, Teleporter;
int lengthMap;
int MaxRoll;
int HalfMaxRoll;
int TotalTeleport;
List skill_list[5];

void ReadFile()
{
    CreateMap(&Layout_Map);
    CreateMap(&Teleporter);

    char name[50];
    char filename[100];
    printf("Masukan nama file konfigurasi : ");
    scanf("%s", name);

    strcat(filename, "../../data/");
    strcat(filename, name);
    strcat(filename, ".txt");

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

void SaveFile()
{
    char name[50];
    FILE *fp;
    printf("Masukkan nama save file : ");
    scanf("%s", name);
    pita = stdin;
    STARTKATA(pita);

    printf("Data anda berhasil disimpan di ../data/%s.txt\n", name);
    char filename[100] = "";
    strcat(filename, "data/");
    strcat(filename, name);
    strcat(filename, ".txt");

    fp = fopen(filename, "w");
    
    // Baris ke-1 peta
    fprintf(fp, "%d\n", lengthMap); 

    // Baris ke-2 peta
    int i;                                                          
    for (i = 0; i < lengthMap; i++)
    {
        if (Layout_Map.TI[i] != 0)
        {
            fprintf(fp, "%c", '.');
        }
        else
        {
            fprintf(fp, "%c", '#');
        }
    }
    fprintf(fp, "\n");

    // Baris ke-3 maxroll
    fprintf(fp, "%d\n", MaxRoll);

    // Baris ke-4 jumlah teleport
    fprintf(fp, "%d\n", TotalTeleport);

    // Baris ke-5 sampai ke-(4 + Jumlah teleport) letak teleport dan petak keluar teleport
    int j;
    for (j = 0; j < lengthMap; j++)
    {
        if (Teleporter.TI[j] != 0)
        {
            fprintf(fp, "%d %d\n", j+1, Teleporter.TI[j]);
        }
    }

    // Baris ke-6 jumlah pemain
    fprintf(fp, "%d\n", nbPlayer);
    
    // Baris ke-7 sampai selesai data pemain
    int k; 
    for(k = 0; k < nbPlayer; k++)
    {   
        // Nama pemain, lokasi, banyak skill
        fprintf(fp, "%s %d %d\n", playerName[k], playerLocation[k], NBElmtList(skill_list[k]));
        if (NBElmtList(skill_list[k]) != 0)
        {
            // id skill dan amount dari skill yang dimiliki pemain
            int m;
            for (m = 0; m < NBElmtList(skill_list[k]); m++)
            {
                addressList p = First(skill_list[k]);
                fprintf(fp, "%d %d\n", Skill_id(p), Amount(p));
                p = Next(p);
            }
        }
    }

    fclose(fp);
}

void LoadFile() //belum kelar
{
    CreateMap(&Layout_Map);
    CreateMap(&Teleporter);

    char name[50];
    char filename[100];
    printf("Masukan nama file konfigurasi : ");
    scanf("%s", name);

    strcat(filename, "../../data/");
    strcat(filename, name);

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

    // lanjutin ngeload savenya
    fclose(fp);
}