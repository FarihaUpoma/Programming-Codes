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

int freq[200], w[1009];
char a[1009];

int main()
{
    freopen("input.txt", "r", stdin);
    int l, i, c=0, k, j;
    while(gets(a)!=NULL)
    {
        if(c==1) printf("\n");
        else c=1;
        for(i=32 ; i<132 ; i++) freq[i]=0;
        l= strlen(a);
        for(i=0 ; i<l ; i++) {
            freq[ a[i] ]++;
        }
        for(k=0,i=32 ; i<128 ; i++) {
            if( freq[i]>0) {
                w[k++]= freq[i];
            }
        }
        sort( w, w+k);
        //for(i=0 ; i<k ; i++) printf("%d ", w[i]); printf("\n");
        for(i=0 ; i<k ; i++) {
            for(j=128 ; j>=32 ; j--)
            {
                if( freq[j]==w[i]) {
                    printf("%d %d\n", j, w[i]);
                    freq[j]=0;
                    break;
                }
            }
        }
        //printf("\n");
    }
    return 0;
}
