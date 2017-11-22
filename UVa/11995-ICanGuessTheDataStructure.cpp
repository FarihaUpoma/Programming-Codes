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

int min(int x, int y)
{
    if( x<y) return x;
    else return y;
}

int max(int x, int y)
{
    if( x>y) return x;
    else return y;
}

stack <int> s;
queue <int> q;
priority_queue <int> pq;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, ss, qq, pqq, f, i, cmd, val, sv, qv, pqv, g, imp;
    while(scanf("%d", &n)!= EOF) {
        ss=qq=pqq=f=g=imp=0;
        for(i=0 ; i<n ; i++) {
            scanf("%d %d", &cmd, &val);
            if(cmd == 1) {
                s.push(val);
                q.push(val);
                pq.push(val);
                g++;
            }
            else {
                f++;
                if(g==0) imp=1;
                if(g!=0) {
                    sv = s.top();
                    qv = q.front();
                    pqv = pq.top();
                    s.pop(); q.pop(); pq.pop();
                    g--;
                }
                if(val == sv) ss++;
                if(val == qv) qq++;
                if(val == pqv) pqq++;
            }
        }
        if(imp==1) printf("impossible\n");
        else if( (f==ss && f==qq) || (f==qq && f== pqq) || ( f==ss && f==pqq)) {
            printf("not sure\n");
        }
        else if( f==ss) printf("stack\n");
        else if(f==qq) printf("queue\n");
        else if( f==pqq) printf("priority queue\n");
        else printf("impossible\n");
        while(!s.empty()) s.pop();
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
    }
    return 0;
}
