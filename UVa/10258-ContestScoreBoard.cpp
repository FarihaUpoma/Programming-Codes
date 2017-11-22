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

int pl[101][12];
char a[10], b[1000][10], sub;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);
    int t, k, i, j, x, prblm, tym, temp, l, f, g, p;
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--) {
        for(i=1 ; i<=100 ; i++) {
            pl[i][0]=i;
            pl[i][11]=-2;
            for(j=1 ; j<=10 ; j++)
                pl[i][j]=0;
        }

        while(gets(a)) {

            l= strlen(a);
            if(l==0) break;
            char *p;
            p= strtok( a, " ");
            i=0;
            while(p!=NULL)
            {
                strcpy( b[i++], p);
                p= strtok(NULL, " ");
            }
            x= atoi( b[0]);
            prblm= atoi(b[1]);
            tym= atoi(b[2]);
            sub= b[3][0];
            //printf("%d %d %d %c\n",x , prblm, tym, sub);

            if(pl[x][prblm]!=-1) {
                if( sub=='I') {
                    pl[x][prblm] += 20;
                }
                else if( sub=='C') {
                    pl[x][10]++;
                    pl[x][prblm] += tym;
                    if(pl[x][11]==-1 || pl[x][11]==-2) pl[x][11]=0;
                    pl[x][11] += pl[x][prblm];
                    pl[x][prblm]= -1;
                }

                if(pl[x][11]==-2) pl[x][11]=-1;

            }
            //printf("pl[x][prblm]=pl[%d][%d]=%d pl[x][11]=%d\n", x, prblm, pl[x][prblm], pl[x][11]);
        }
        //printf("loop sesh\n");
        for(i=1 ; i<=100 ; i++) {
            for(j=i+1 ; j<=100 ; j++) {
                if( pl[j][10] > pl[i][10] && pl[i][10]!=0) {
                    //printf("changing %d & %d while 1st: 10=%d,11=%d & 2nd: 10=%d, 11=%d\n", i,j,pl[i][10],pl[i][11],pl[j][10],pl[j][11]);

                    temp= pl[j][11];
                    pl[j][11]= pl[i][11];
                    pl[i][11]= temp;
                    temp= pl[j][10];
                    pl[j][10]= pl[i][10];
                    pl[i][10]= temp;
                    temp= pl[j][0];
                    pl[j][0]= pl[i][0];
                    pl[i][0]= temp;
                }
                else if( pl[j][10]==pl[i][10] && pl[i][10]!=0) {
                    if( pl[j][11] < pl[i][11]) {
                        //printf("changing %d & %d while 1st: 10=%d,11=%d & 2nd: 10=%d, 11=%d\n", i,j,pl[i][10],pl[i][11],pl[j][10],pl[j][11]);
                        temp= pl[j][11];
                        pl[j][11]= pl[i][11];
                        pl[i][11]= temp;
                        temp= pl[j][10];
                        pl[j][10]= pl[i][10];
                        pl[i][10]= temp;
                        temp= pl[j][0];
                        pl[j][0]= pl[i][0];
                        pl[i][0]= temp;
                    }
                }
            }
        }
        for(i=1 ; i<=100 ; i++) {
            //printf("i=%d   ");
            if( pl[i][11]>=0) {
                printf("%d %d %d\n", pl[i][0], pl[i][10], pl[i][11]);
            }
        }
        for(i=1 ; i<=100 ; i++) {
            if(pl[i][11]==-1)
                printf("%d %d 0\n", pl[i][0], pl[i][10]);
        }
        if(t>0) printf("\n");
    }
    return 0;
}
