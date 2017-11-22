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

int n, n1, n2;
char a[100], b[100], g[100];

int main()
{
    scanf("%d", &n);
    getchar();
    while(gets(g)) {
        if( strcmp( g, "quit")==0) break;
        sscanf(g, "%s %d %s %d", a, &n1, b, &n2);
        printf("%s %d %s %d\n", a, n1,b,n2);
    }
    return 0;
}
