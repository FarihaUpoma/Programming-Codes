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

void add( char *c, char *d, char *w)
{
    int l, i, carry, x;
    l= strlen(c);
    for(carry=0,i=0 ; i<l ; i++) {
        if( c[i]==0 || d[i]==0) x= c[i]+d[i]-'0';
        else x= c[i]+d[i]-2*'0';
        w[i]= (x+carry)%10+ '0';
        carry= (x+carry)/10;
    }
    while( carry ) {
        w[i++]= carry%10 + '0';
        carry= carry/10;
    }
    w[i]=0;
}

void sum(char *c, char *d, char *w)
{
    if( strlen(c) >= strlen(d)) add(c, d, w);
    else add(d, c, w);
}

char st[5000][10000];
int n;

void fib()
{
    int i;
    n=2;
    st[0][0]=st[1][0]='1';
    for(i=2 ; ; i++) {
        sum( st[i-2], st[i-1], st[i]);
        n++;
    }
}

char a[100], b[100];

int main()
{
    int i;
    scanf("%s %s", a, b);
    fib();
    printf("%s\n", st[10]);
    return 0;
}
