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

char a[1000], eng[100][100], dic[100][100];

int main()
{
    int k=0, kk=0, i, j, start, end, mid;
    while(scanf("%s", eng[k++]))
    {
        printf("%d\n", strlen(eng[k-1]));
        if( strlen(eng[k-1])==0) break;
        scanf("%s", dic[kk++]);

    }
    printf("scan sesh!\n");
    for(i=0 ; i<kk ; i++) {
        for(j=i+1 ; j<kk ; j++) {
            if( strcmp(dic[i], dic[j])==1) {
                strcpy(a, dic[i]);
                strcpy(dic[i], dic[j]);
                strcpy(dic[j], a);
                strcpy(a, eng[i]);
                strcpy(eng[i], eng[j]);
                strcpy(eng[j], a);
            }
        }
    }
    while(scanf("%s", a))
    {
        start= 0;end= kk;
        while(1)
        {
            mid= (start+end)/2;
            if( strcmp( a, dic[mid])==1)
                start= mid;
            else if( strcmp(a, dic[mid])==-1)
                end= mid;
            else
            {
                printf("%s\n", eng[mid]);
                break;
            }
        }
    }
}
