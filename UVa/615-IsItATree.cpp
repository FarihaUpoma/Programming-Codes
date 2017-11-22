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

map <int, int> mp;
map <int, int> :: iterator it;
int g[100][100], in[100], out[100], f;
int visit[100], cost[100];

void bfs(int s)
{
    int u;
    memset(visit, 0, sizeof(visit));
    memset(cost, 0, sizeof(cost));
    queue <int> q;
    visit[s]=1;
    cost[s]=0;
    q.push(s);
    f=0;
    while( !q.empty()) {
        u= q.front();
        q.pop();
        for(it= mp. begin() ; it!=mp.end() ; it++) {
            if( g[u][it->second]==1 ) {
                //printf("edge :: %d -> %d\n", u, it->second);
                if( visit[ it->second] ==0) {
                    visit[ it->second]= 1;
                    cost[ it->second]= cost[u]+1;
                    q.push(it->second);
                }
                else if( visit[ it->second]==1) {
                    f=1;
                    break;
                }
            }
        }
        if(f==1) break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int a, b, i, j, k=1, p=0, l=0, w, root, r=0, T=1, z;
    while(scanf("%d %d", &a, &b))
    {
        if(a==-1 && b==-1) break;
        if( a==0 && b==0) {
            for(i=0 ; i<p ; i++) {
                if( g[ mp[ in[i] ] ][ mp[ out[i] ] ]==1) z=1;
                g[ mp[ in[i] ] ][ mp[ out[i] ] ]=1;
            }

            /*printf("mp---\n");
            for(it= mp.begin() ; it!=mp.end() ; it++) printf("%d -> %d ", it->first,it->second);
            printf("\n");for(i=0 ;i<p ; i++) printf("in= %d\n", in[i]);
            printf("\n");for(i=0 ;i<l ; i++) printf("out= %d\n", out[i]);*/
            for(i=0 ; i<p ; i++) {
                for(w=0,j=0 ; j<l ; j++) {
                    if( in[i]==out[j]) {
                        //printf("in=%d out=%d\n", in[i], out[j]);
                        w=1;
                        break;
                    }
                }
                if(w==0)
                    root= in[i];
            }
            //printf("\nroot=%d mp[root]= %d\n", root, mp[root]);
            bfs ( mp[root]);
            if(f==1 || z==1) printf("Case %d is not a tree.\n", T++);
            else
            {
                for(it= mp.begin() ; it!= mp.end() ; it++) {
                    if (visit[it->second]==0) {
                        f=1;
                        printf("Case %d is not a tree.\n", T++);
                        break;
                    }
                    if(cost[it->second]==0 && it->second!= mp[root]) {
                        r=1;
                        printf("Case %d is not a tree.\n", T++);
                        break;
                    }
                }
                //printf("f=%d r=%d\n", f, r);
                //if(f==1 || r==1) printf("2 not tree\n");
                if(f==0 && r==0) printf("Case %d is a tree.\n", T++);
            }
            p=0;k=1;l=0;r=0;f=0;z=0;
            mp.clear();
            memset(g, 0, sizeof(g));
        }
        else {
        if( mp.find(a)==mp.end()) {
            mp[a]=k;
            k++;
        }
        else mp[a]= k++;
        if( mp.find(b)==mp.end()) {
            mp[b]=k;
            k++;
        }
        else mp[b]= k++;
        in[p++]= a; out[l++]= b;
        }
    }
    return 0;
}
