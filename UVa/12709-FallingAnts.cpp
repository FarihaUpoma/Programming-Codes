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

int a[100], b[100], c[100];

int main()
{
    int t, i, max, maxv, v;
    while(scanf("%d", &t) && t) {
    max=-1;maxv=-1;
        for(i=0 ; i<t ; i++) {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
            v= a[i]*b[i]*c[i];
            if(c[i]>=max) {
                max= c[i];
                maxv= v;
            }
        }
        printf("%d\n", maxv);
    }
    return 0;
}
