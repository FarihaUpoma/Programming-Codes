#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

double g[2005], v, t;
int visit[2005][2005], cost[2005][2005], xt, yt, f;

void bfs(double xs, double ys, int j)
{
    double xx, yy, d, tt, tempx, tempy;
    int x, y, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int> q2;
    visit[0][1] =1;
    cost[0][1]=0;
    q1.push(0) ;
    q2. push(1);
    f=0;
    while( !q1.empty() ) {
        x= q1.front();
        y= q2.front();
        xx= g[ x];
        yy= g[ y ];
        q1.pop();
        q2.pop();
        d= sqrt((xx-xt)*(xx-xt) + (yy-yt)*(yy-yt));
        tt= d/v;
        //printf("dis= %lf tt=%lf\n", d, tt/60);
        if(tt<=t*60) {
            cost[2][3]= cost[x][y]+1;
            visit[2][3]= 1;
            f=1;
            break;
        }
        else {
            for(i=4 ; i< j ; i=i+2) {
                tempx = g[i]; tempy= g[i+1];
                d= sqrt((xx-tempx)*(xx-tempx) + (yy-tempy)*(yy-tempy));
                tt= d/v;
                //printf("dis= %lf tt=%lf\n", d, tt/60);
                if(tt<=t*60 && visit[i][i+1]==0) {
                    cost[i][i+1]=  cost[x][y]+1;
                    visit[i][i+1]=1;
                    q1.push(i);
                    q2.push(i+1);
                }
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int l, k, i;
    double xs, ys;
    char a[2005][100];
    while(scanf("%lf %lf", &v, &t) && v && t)
    {
        /*scanf("%lf %lf", &xs, &ys);
        scanf("%lf %lf", &xt, &yt);
        printf("xs= %lf %lf %lf %lf", xs, ys, xt,yt);*/
        k=0;
        getchar();
        while(gets(a[k]))
        {
            l= strlen(a[k]);
            //printf("a[k]=%s\n", a[k]);
            if(l==0) break;
            k++;
        }
        /*for(i=0 ; i<k ; i++) printf("%s\n", a[i]);
        printf("done\n");*/
        char *p;
        int j=0;
        for(i=0 ; i<k ; i++) {
            p= strtok( a[i], " ");
            while(p) {
                g[j++]= atoi(p);
                p= strtok(NULL, " ");
            }
        }
        /*for(i=0 ; i<j ; i++) {
            printf("%lf ", g[i]);
        }*/

        xs= g[0]; ys= g[1]; xt= g[2], yt= g[3];
        bfs(xs, ys, j);
        if(visit[2][3]==0) printf("No.\n");
        else {
            printf("Yes, visiting %d other holes.\n", cost[2][3]-1);
        }
    }
    return 0;
}
