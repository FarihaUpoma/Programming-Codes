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

map <unsigned char, int> v;
char q[5], a[10010];

int main()
{
    int t, i, n, j, w, m, l, k;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        for(j=0 ; j<n ; j++) {
            scanf("%s %d", q, &w);
            v[ q[0] ]= w;
        }
        scanf("%d", &m);
        double x=0.0;
        getchar();
        for(j=0 ; j<m ; j++) {
            gets(a);
            l= strlen(a);

            for(k=0 ; k<l ; k++) {
                x= x+ v[ a[k] ];
            }
        }
        printf("%.2lf%c\n", x/100.00, '$');
        v.clear();
    }
    return 0;
}
