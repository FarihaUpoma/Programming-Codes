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

char a[1000];

int main()
{
    //freopen("input.txt", "r", stdin);
    int l, i, j, n;
    while(gets(a)!=NULL)
    {
        l= strlen(a);
        for(n=0,i=0 ; i<l ; i++)
        {
            if( isdigit( a[i] ) )
            {
                //printf("%c is a digit\n", a[i]);
                n= n+a[i]-'0';
            }
            else if( a[i]=='!')
                printf("\n");
            else
            {

                for(j=0 ; j<n ; j++)
                {
                    if(a[i]=='b') printf(" ");
                    else
                        printf("%c", a[i]);
                }
                n=0;
            }
        }
        printf("\n");
    }
    return 0;
}
