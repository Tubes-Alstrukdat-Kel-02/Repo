#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "boolean.h"

int main()
{
    TabInt Tab1, Tab2;
    int i;
    int n = 20;
    MakeEmpty(&Tab1);
    MakeEmpty(&Tab2);

    if (IsEmpty(Tab1))
    {
        for(i =0; i < n; i++)
        {
            SetNeff(&Tab1, n);
            SetEl(&Tab1, i, i);
        }
    }

    SetTab(Tab1, &Tab2);

    for(i = 0; i < 20 ; i++)
    {
        printf("%d\n", Tab2.TI[i]);
    }

    return 0;
}
