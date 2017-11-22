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
    int n, i, j, l, x, carry=0;
    char a[1000], b[1000];
    scanf("%s %d", a, &n);
    l= strlen(a);
    for(j=0,i=l-1 ; i>=0 ; i--) {
        x= (a[i]-'0')*n;
         printf("x=%d carry=%d (carry+x)%c10=%d b[j]=%c\n", x, carry,'%', (carry+x)%10, ((carry+x)%10)+'0');
        b[j]= ((carry+x)%10)+'0';
        carry= (carry+x)/10;

        j++;
    }
    b[j]=0;
    printf("%s\n", b);
    return 0;
}
