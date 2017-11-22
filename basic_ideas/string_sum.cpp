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

char a[100], b[100], st[100][100];

void strRev(char *c)
{
    int i, l;
    l= strlen(c);
    for(i=l-1 ; i>=0 ; i--) printf("%c", c[i]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int l, j, carry, i, x;
    st[0][0]=st[1][0]=1;
    scanf("%s %s", a, b);
    if( strlen(a)>strlen(b)) l= strlen(a);
    else l= strlen(b);
    for(carry=0,j=l-1, i=0 ; j>=0 ; j--, i++) {
        x= a[j]+b[j]-2*'0';
        printf("a[j]=%d b[j]=%d x=%d st[2][j]=%d\n", a[j], b[j],x, (x+carry)%10);
        st[2][i]= ((x+carry)%10)+'0';
        carry= (x+carry)/10;
    }
    while(carry) {
        st[2][i++]= (carry%10)+'0';
        carry= carry/10;
    }
    st[2][i]=0;
    printf("%s\n", st[2]);
    strRev(st[2]);
    return 0;
}
