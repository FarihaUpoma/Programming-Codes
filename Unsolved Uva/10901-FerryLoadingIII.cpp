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

char a[10];

queue <int> ql;
queue <int> qr;

map <int, int> mp;
map <int, int> :: iterator it;
int res[10009];

int main()
{
    //freopen("input.txt", "r", stdin);

    int T, n, t, m, tt, f, nn, i, b, k;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &t, &m);
        k=0;
        while(m--) {
            scanf("%d %s", &b, a);
            if( a[0]=='l') ql.push(b);
            else qr.push(b);
            mp[k++]= b;
        }
        memset( res, -1, sizeof(res));
        tt=0;f=0;
        while( !(ql.empty() && qr.empty() )) {
            //printf("tt=%d\n", tt);
            if(f==0) {
                if( qr.front() < ql.front() || ql.empty()) {
                    if( qr.front() > tt) {
                        tt= tt+ ( qr.front()-tt);
                    }
                    tt += t;
                    nn=0;
                    while( qr.front() <=tt) {

                        qr.pop();
                        nn++;
                        if(nn==n || qr.empty()) break;
                    }
                    if(nn==0)  {
                        tt += t+qr.front();

                        qr.pop();
                    }
                    else {
                        tt += t;
                    }
                }
                else if( ql.front() < qr.front() || qr.empty()) {
                    nn=0;
                    while( ql.front() <=tt) {

                        ql.pop();
                        nn++;
                        if(nn==n || ql.empty()) break;
                    }
                    if(nn==0) {
                        tt += t+ql.front();

                        ql.pop();
                        f=1;
                    }
                    else {
                        tt += t;
                        f=1;
                    }
                }
            }
            else {
                if( qr.front() < ql.front() || ql.empty()) {
                    //tt += t;
                    nn=0;
                    while( qr.front() <=tt) {

                        qr.pop();
                        nn++;
                        if(nn==n || qr.empty()) break;
                    }
                    if(nn==0)  {
                        tt += t+qr.front();

                        qr.pop();
                        f=0;
                    }
                    else {
                        tt += t;
                        f=0;
                    }
                }
                else if(ql.front() < qr. front() || qr.empty()){
                    if( ql.front() > tt) {
                        tt= tt+ ( ql.front()-tt);
                    }
                    tt += t;
                    nn=0;
                    while( ql.front() <=tt) {

                        ql.pop();
                        nn++;
                        if(nn==n || ql.empty()) break;
                    }
                    if(nn==0) {
                        tt += t+ql.front();

                        ql.pop();
                    }
                    else {
                        tt += t;
                    }
                }
            }

        }

        if(T>0) printf("\n");
    }
    return 0;
}
