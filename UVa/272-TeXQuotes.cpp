#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

char a[10009];

int main()
{
    //freopen("input.txt", "r", stdin);
    int l, i, c=0;
    while(gets(a)!=NULL)
    {
        l= strlen(a);
        for(i=0 ; i<l ; i++)
        {
            if( a[i]=='"') c++;
            if(a[i]=='"' && c%2==0) {
                printf("''");
                continue;
            }
            else if(a[i]=='"' && c%2==1) {
                printf("``");
                continue;
            }
            printf("%c", a[i]);
        }
        printf("\n");
    }
    return 0;
}
