#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

char a[110][110];

int main()
{
    int j=0, c, i, l, max=0, k;
    while(gets(a[j])!=NULL)
    {
        l= strlen(a[j]);
        if(l>max) max= l;
        j++;
    }

    for(c=0 ; c<max ; c++)
    {
        for(i=j-1 ; i>=0 ; i--)
        {
            //printf("\na[i][c]=%c\n", a[i][c]);
            if(a[i][c]==0) {
                printf(" ");
                continue;
            }
            printf("%c" , a[i][c]);
        }
        printf("\n");
    }
    return 0;
}
