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

long long int a[10000];

int main()
{
    long long int x, i=0;
    while(scanf("%lld", &a[i++])!=EOF)
    {
        sort(a, a+i);

        if(i%2!=0) x= a[i/2];
        else x= (a[i/2]+a[i/2-1])/2;
        printf("%lld\n", x);

    }
    return 0;
}
