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

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

int visit[1000][1000], g[30][5];
char a[1000][1000];

map <int , int> mp;

void bfs(int x, int y, char k)
{
    int xx, yy, i, tx, ty;
    queue <int>q1, q2;
    visit[ x][y]=1;
    q1.push(x);
    q2.push(y);
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]==k && visit[ tx][ty]==0) {
                a[tx][ty]='0';
                visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
            }
        }
    }
}

int main ()
{
    int t, n, m, i, j, k, temp, p=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);

        memset(visit, 0, sizeof(visit));
        /*memset(v, 0, sizeof(v));
        memset(mp, 0, sizeof(mp));*/

        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if( a[i][j] >96 && a[i][j]<123) {
                    bfs(i, j, a[i][j]);
                    if(mp.find(a[i][j]-'a')==mp.end()) mp[ a[i][j]-'a' ]= 1;
                    else mp[ a[i][j]-'a' ] += 1;
                }
            }
        }
        map <int , int> :: iterator it;
        for(it=mp.begin(), k=0 ; it!= mp.end(); it++, k++) {
            g[k][0]= it->first;
            g[k][1]= it->second;
        }
        for(i=0 ; i<k-1 ; i++) {
            for(j=0 ; j<k-i-1 ; j++) {
                if( g[j][1] < g[j+1][1]) {
                    temp= g[j][1];
                    g[j][1]= g[j+1][1];
                    g[j+1][1]= temp;
                    temp= g[j][0];
                    g[j][0]= g[j+1][0];
                    g[j+1][0]= temp;
                }
                else if( g[j][1]== g[j+1][1]) {
                    if( g[j][0] > g[j+1][0]) {
                        temp= g[j][1];
                        g[j][1]= g[j+1][1];
                        g[j+1][1]= temp;
                        temp= g[j][0];
                        g[j][0]= g[j+1][0];
                        g[j+1][0]= temp;
                    }
                }
            }
        }
        printf("World #%d\n", p++);
        for(i=0 ; i<k ; i++) printf("%c: %d\n", g[i][0]+'a', g[i][1]);
        mp.clear();
    }
    return 0;
}
