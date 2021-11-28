#include <stdio.h>
#include "SaveLoad.h"
#include <string.h>
static FILE * pita;

TabInt Layout_Map, Teleporter;
Queue playerQueue;
int lengthMap;
int MaxRoll;
int HalfMaxRoll;
int TotalTeleport;
List skill_list[5];
int Round;
int playerTurn;
Queue playerQueue;

void readFile()
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
    memset( CKata.TabKata, '\0', sizeof(CKata.TabKata));

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

void saveFile()
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

    // Baris ke-7 round saat disave
    fprintf(fp, "%d\n", Round);

    // Baris ke-8 player yang akan bermain
    fprintf(fp, "%d\n", playerTurn);
    
    // Baris ke-9 sampai selesai data pemain
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

void loadFile()
{
    CreateMap(&Layout_Map);
    CreateMap(&Teleporter);
    CreateEmptyQueue(&playerQueue, 5);
    CreateEmptyList(&skill_list[5]);

    char name[50];
    char filename[100];
    printf("Masukan nama save file yang akan di load : ");
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
    memset( CKata.TabKata, '\0', sizeof(CKata.TabKata));

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

    STARTKATA(fp);
    nbPlayer = StrToInt(CKata);

    STARTKATA(fp);
    Round = StrToInt(CKata);

    STARTKATA(fp);
    playerTurn = StrToInt(CKata);

    int k;
    for(k = 0; k < nbPlayer; k++) 
    {   
        int nbElmtSkill;

        STARTKATA(fp);

        strcpy(playerName[k], CKata.TabKata);
        memset( CKata.TabKata, '\0', sizeof(CKata.TabKata));

        ADVKATA();
        playerLocation[k] = StrToInt(CKata);

        ADVKATA();
        nbElmtSkill = StrToInt(CKata);

        AddElmtQueue(&playerQueue, k);

        int m;
        for (m = 0; m < nbElmtSkill; m++) 
        {
            int Skill_id, Amount;

            STARTKATA(fp);
            Skill_id = StrToInt(CKata);
            ADVKATA();
            Amount = StrToInt(CKata);

            addressList P = Alokasi_List (Skill_id, Amount);

            InsertLast_List(&skill_list[m], P);
        }

        //ADVKATA();
        //activeBuff = ;
    }

    fclose(fp);
}