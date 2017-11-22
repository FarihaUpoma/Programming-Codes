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

int main()
{
    char a[60];
    while(scanf("%s", a))
    {
        if(a[0]=='#') break;
        if(next_permutation(a, a+strlen(a)))
            printf("%s\n", a);
        else printf("No Successor\n");
    }
    return 0;
}
