#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int main()
{
    long long int n, x;
    while(scanf("%lld", &n))
    {
        if(n<0) break;
        x= n*(n+1)/2 + 1;
        printf("%lld\n", x);
    }
    return 0;
}
