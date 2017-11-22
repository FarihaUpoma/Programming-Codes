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

char a[100];

int main()
{
    //freopen("input.txt", "r", stdin);
    int l, i, d, j, n, g, f;
    while(gets(a)!=NULL)
    {
        l= strlen(a);
        if( a[0]>='0' && a[0]<='9' ) {
            for(g=0,i=l-1 ; i>=0 ; i=i-g)
            {
                if(a[i]=='1') {
                    n= (a[i]-'0' )*100+(a[i-1]-'0')*10+(a[i-2]-'0');
                    g=3;
                }
                else {
                    n= (a[i]-'0')*10+ (a[i-1]-'0');
                    g=2;
                }
                //printf("n=%d\n", n);
                printf("%c", n);
            }
            //printf("digit chilo\n");
        }
        else {
            for(i=l-1 ; i>=0 ; i--) {
                d= a[i];
                for(j=d ;  ; j=j/10) {
                    if(j==0) break;
                    printf("%d", j%10);

                }
            }
        }
        //printf("string chilo\n");
        printf("\n");
    }
    return 0;
}
