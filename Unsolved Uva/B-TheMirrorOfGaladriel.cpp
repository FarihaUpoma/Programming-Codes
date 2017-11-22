#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

char a[100], b[100];

int main()
{
    int t, i, n, l, f=0, m;
    scanf("%d", &t);
    while(t--)
    {
        f=0;
        scanf("%s", a);
        l= strlen(a);
        m= l/2;
        for(i=0, n=l-1 ; i<m ; i++, n--) {
            if( a[i]!=a[n]) {
                f=1;
                break;
            }
        }
        if(f==1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
