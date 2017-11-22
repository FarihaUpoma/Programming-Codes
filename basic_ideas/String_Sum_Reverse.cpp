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

char a[100], b[10], c[100];

int main()
{
    int l,i, j, carry, x;
    scanf("%s %s", a, b);
    if(strlen(a)>strlen(b)) l= strlen(a);
    else l= strlen(b);
    for(carry=0,j=0 ; j<l ; j++) {
        if(a[j]==0 || b[j]==0) x= a[j]+b[j]-'0';
        else
            x= a[j]+b[j]-2*'0';
        c[j]= (x+carry)%10+'0';
        carry= (x+carry)/10;
    }
    while(carry) {
        c[j]= carry%10;
        carry= carry/10;
    }
    c[j]= 0;
    printf("%s\n", c);
    return 0;
}
