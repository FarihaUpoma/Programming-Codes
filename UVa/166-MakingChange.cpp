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
#define pb push_back
#define mem(a, n) memset(a, n, sizeof(a))
#define done printf("done\n")

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

int m, sum, cc[6] = {5,10,20,50,100, 200}, nc[6];
int st1[1000009], st2[100009], mmin;
vector <int> c;

void dp1()
{
    int i, coin, j;
    mem(st1, 0x3f);
    st1[0] = 0;
    for(i=0 ; i<6 ; i++) {
        coin = cc[i];
        for(j=0 ; j<100000 ; j++) {
            if(j-coin < 0) continue;
            if( st1[j-coin] + 1 < st1[j])
                st1[j] = st1[j-coin] + 1;
        }
    }
}

void dp2(int m)
{
    int i, j, coin, mmin;
    sum = 0;
    for(i=0 ; i<6 ; i++) {
        for(j=0 ; j<nc[i] ; j++) {
            c.pb(cc[i]);
            sum += cc[i];
        }
    }
    /*for(i=0 ; i<c.size() ; i++) {
        printf("%d ", c[i]);
    }printf("\n");
    printf("%d\n", sum);*/
    mem(st2, 0x3f);
    st2[0] = 0;
    for(i=0 ; i<c.size() ; i++) {
        coin = c[i];
        for(j=sum ; j>0 ; j--) {
            if(j-coin<0) continue;
            //if( j==550) printf("st[j-coin]=%d st[j]=%d\n", st2[j-coin], st2[j]);
            if( st2[j-coin] + 1 < st2[j]) {
                st2[j] = st2[j-coin] + 1;
            }
        }
    }
    mmin = 1000009;
    int x;
    for(i=m ; i<=sum ; i++) {
        if(st2[i] != 1061109567 && st1[i-m] != 1061109567) {
            if( st2[i] + st1[i-m] < mmin) {
                mmin = st2[i] + st1[i-m];
                x = i;
            }
        }
    }
    //printf("%3d (%d+%d) (%d+%d)\n", mmin, x, x-m, st2[x],st1[x-m]);
    printf("%3d\n", mmin);
}

int main()
{
    //freopen("fariha.txt", "r" , stdin);
    //freopen("out1.txt", "w", stdout);

    int i, j, cnt;
    double x;
    dp1();
    while(1) {
        //done;
        cnt = 0;
        sum = 0;
        c.clear();
        for(i=0 ; i<6 ; i++) {
            scanf("%d", &nc[i]);
            //printf("%d\n", m);
            cnt += nc[i];
        }
        //printf("cnt=%d\n", cnt);
        if(cnt==0) break;
        scanf("%lf", &x);
        x = x*100.00+0.05;
        m = x;
        //printf("m=%d\n", m);
        dp2(m);
        //printf("min = %d\n", mmin);
    }
    return 0;
}
