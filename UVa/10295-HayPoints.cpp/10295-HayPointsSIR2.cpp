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

char a[1005][100], b[1000];
int s[1005];

int main()
{
//	freopen("input.txt","r", stdin);
    int m, n, i, j, temp, sal, start, mid, end;
    scanf("%d %d", &m, &n);
    for(i=0 ; i<m ; i++) {
        scanf("%s %d", a[i], &s[i]);
    }

    for(i=0 ; i<m ; i++) {
        for(j=i+1 ; j<m ; j++) {
            if( strcmp( a[i], a[j])==1) {
                strcpy( b, a[i]);
                strcpy(a[i], a[j]);
                strcpy( a[j], b);
                temp= s[i];
                s[i]= s[j];
                s[j]= temp;
            }
        }
    }

    for(i=0 ; i<n ; i++) {
        sal= 0;
        while(1) {
            scanf("%s", b);
            if( strcmp(b, ".")==0) break;
            start = 0; end= m;
            while(start <= end) {
                mid= (start+end)/2;
                if( strcmp( b, a[mid])==1)
                    start= mid+1;
                else if( strcmp( b, a[mid])==-1)
                    end= mid-1;
                else {
                    sal= sal+ s[mid];
                    break;
                }
				//printf("%s %d\n", b, sal);
            }
        }
        printf("%d\n", sal);
    }
    return 0;
}
