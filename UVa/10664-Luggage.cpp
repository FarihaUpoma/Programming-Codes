#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int status[1000000];
int c[1000], sum, n;

void dp()
{
    int i, j, coin;
    status[0]=1;
    for(i=0 ; i<n ; i++) {
        coin= c[i];
        for(j=sum ; j>=0 ; j--) {
            if(j+coin>sum || status[j]==0) continue;
            status[j+coin]= status[j]+1;
        }
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int t, i, j;
    char *p, in[10000];
    scanf("%d", &t);
    getchar();
    for(i=0 ; i<t ; i++) {
        gets(in);
        n=0;
        p=strtok(in, " ");
        while(p)
        {
            c[n++]= atoi(p);
            p= strtok(NULL, " ");
        }
        for(sum=0,j=0 ; j<n ; j++)
            sum= sum+c[j];
        if(sum%2!=0) printf("NO\n");
        else {

            dp();

            if(status[sum/2]>0)
                printf("YES\n");
            else printf("NO\n");
        }

        memset(status, 0, sizeof status);
        memset(in, 0, sizeof(in));

    }
    return 0;
}
