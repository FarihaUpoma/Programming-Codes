#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

char a[110][100];
int m1[100], m2[200];

int main()
{
    int t, m, l, q, i, j, c, k, x, p;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d %d", &l, &m);
        q=0;
        for(j=0 ; j<m ; j++)
        {
            scanf("%s", a[j]);
            for(c=0,k=0 ; k<l-1 ; k++) {
                for(p=k+1 ; p<l ; p++) {
                    if( a[j][k]>a[j][p]) c++;
                }
            }
            m1[j]= c;
            m2[j]=c;
        }
        //for(j=0 ; j<m ; j++) printf("%d ", m2[j]);printf("\n");
        sort(m1  ,m1+m);
        for(j=0 ; j<m ; j++)
        {
            for(k=0 ; k<m ; k++)
            {
                if( m1[j]==m2[k])
                {
                    printf("%s\n", a[k]);
                    m2[k]=-1;
                    break;
                }
            }
        }
        if(i<t-1) printf("\n");
    }
    return 0;
}
