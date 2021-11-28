#include <stdio.h>
#include <stdlib.h>
#include "mesin_kata.h"
#include "boolean.h"

int main()
{
    int lengthMap;
    char map[100];
    FILE *fp;
    fp = fopen("../../data/config file/config.txt", "r");

    STARTKATA(fp);
    lengthMap = StrToInt(CKata);
    printf("%d\n", lengthMap);

    STARTKATA(fp);
    strcpy(map, CKata.TabKata);
    printf("%s\n", map);

    return 0;
}