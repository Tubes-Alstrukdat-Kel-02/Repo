#include <stdio.h>
#include <stdlib.h>
#include "mesin_kar.h"
#include "boolean.h"

int main()
{
    FILE *fp;

    fp = fopen("../../data/config file/configtest.txt", "r");
    
    START(fp);
    printf("%c\n", CC);
    
    return 0;
}