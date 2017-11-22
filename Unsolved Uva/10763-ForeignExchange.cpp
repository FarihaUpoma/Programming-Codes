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
    int t, i, j, n, b, w, ab;
    char q;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++)
    {
        scanf("%d %s", &n, a);

        printf("Case %d: ", i+1);
        for(b=0,w=0,ab=0,j=0 ; j<n ; j++)
        {
            if( a[j]=='B') b++;
            else if( a[j]=='W') w++;
            else if(a[j]=='A') ab++;
        }
        if( ab==n) printf("ABANDONED\n");
        else if(b+ab==n) printf("BANGLAWASH\n");
        else if(w+ab==n) printf("WHITEWASH\n");
        else if(b>w) printf("BANGLADESH %d - %d\n",b, w);
        else if(b==w) printf("DRAW %d %d\n", b, w);
        else printf("WWW %d - %d\n", w, b);
    }
    return 0;
}
