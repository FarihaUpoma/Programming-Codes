#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

map <string, int> sal;
map <int, string> wrd;

int main()
{
    int m, n, i;
    scanf("%d %d", &m, &n);
    for(i=0 ; i<m ; i++) {
        scanf("%s %d", &wrd[i], &sal [wrd[i] ]);
    }
    for(i=0 ; i<m ; i++) printf("%s", wrd[i]);
    return 0;
}
