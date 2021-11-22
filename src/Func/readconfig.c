
#include <stdio.h>
#include <stdlib.h>
#include "map.h"

TabMap T;

void ReadConfig()
{
    int lengthmap, maxroll, totalteleport, sums, i;
    char map[100];
    char line[100];
    char teleport_info;
    int idx_teleport, idx_tujuan;
    char CC;

    FILE *config_file = fopen("config.txt", "r");

    fgets(line, sizeof(line), config_file);
    lengthmap = atoi(line);

    fgets(line, sizeof(line), config_file);
    // map = line;
    // masukin tiap char ke map

    fgets(line, sizeof(line), config_file);
    maxroll = atoi(line);

    fgets(line, sizeof(line), config_file);
    totalteleport = atoi(line);

    for(i = 1; i <= totalteleport; i++)
    {
        fscanf(config_file, "%d %d", &idx_teleport, &idx_tujuan);
        SetTeleport(&T, idx_teleport, idx_tujuan);
    }
    
    fclose(config_file);
}
