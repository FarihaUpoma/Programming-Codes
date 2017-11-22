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

map <string, int> m;
map <string, int> :: iterator p;
char a[100];

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, l;
    double x, c;
    scanf("%d\n", &t);
    while(t--) {
        c=0;
        while(gets(a)) {
            l= strlen(a);
            if(l==0)
                break;
            if(m.find(a) == m.end())
                m[a]=1;
            else
                m[a]= m[a]+1;
            c++;
        }
        //printf("%d\n", m.size());
        for(p= m.begin() ; p != m.end() ; p++) {
                cout << (*p).first;
                x= (*p).second;
                printf(" %.4lf\n", (x*100.00)/c);
        }
        if(t>0)
            printf("\n");
        m.clear();
    }
    return 0;
}
