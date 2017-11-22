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

int l[110], w[110], h[110], m[110];

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, g, max, i, x, k, p, mmax;
    while(scanf("%d", &t) && t) {
        k=0;p=0;
        max=-1; mmax=-1;
        while(t--) {

            scanf("%d %d %d", &l[k], &w[k], &h[k]);
            if(h[k]>max) {
                max= h[k];
                mmax= l[k]*w[k]*h[k];
            }
            k++;
        }
        //printf("k=%d max=%d mmax=%d\n",k, max, mmax);
        for(i=0 ; i<k ; i++) {
            //printf("done\n");
            x= l[ i ]* w[ i ] * h[ i ];
            //printf("x=%d\n", x);
            if(h[i]==max)
                if(x> mmax) mmax=x;
        }
        printf("%d\n", mmax);
    }
    return 0;
}
