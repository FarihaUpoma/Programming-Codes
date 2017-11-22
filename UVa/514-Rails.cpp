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

stack <int> s;
int a[1010];

int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("out1.txt", "w", stdout);
    int n, i, k, f, top, j, p=1;
    while(scanf("%d", &n) && n)
    {
        //printf("Case no:%d\n", p++);
        while(1)
        {
            scanf("%d", &a[0]);
            if(a[0]==0) break;
            for(i=1 ; i<n ; i++)
                scanf("%d", &a[i]);
            k=0;
            for(i=1 ; i<=n ; i++)
            {
                if(a[k]==i)
                    k++;
                else {
                    s.push(i);
                }
                while(!s.empty() && s.top()==a[k])
                {
                    s.pop();
                    k++;
                }
            }
            if(s.empty()) printf("Yes\n");
            else printf("No\n");
            while(!s.empty()) s.pop();
        }
        printf("\n");
    }
    //printf("\n");
    return 0;
}
