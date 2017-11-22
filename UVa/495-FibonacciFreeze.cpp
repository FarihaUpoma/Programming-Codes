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

char st[6000][100009];

void fib()
{
    int i, l, carry, j, x, k;
    st[0][0]=st[1][0]='1';
    for(i=2 ; i<=5005 ; i++) {
        if( strlen(st[i-2])>strlen(st[i-1]) ) l= strlen(st[i-2]);
        else l= strlen(st[i-1]);
        for(carry=0,j=0 ; j<l ; j++) {
            if(st[i-2][j]==0 || st[i-1][j]==0)
                x= st[i-2][j]+st[i-1][j]-'0';
            else
                x= st[i-2][j]+st[i-1][j]-2*'0';
            st[i][j]= ((x+carry)%10)+'0';
            carry= (x+carry)/10;
        }
        while(carry) {
            st[i][j++]=(carry%10)+'0';
            carry=carry/10;
        }
        st[i][j]=0;
    }
}

void strRev(char *c)
{
    int l, i;
    l= strlen(c);
    for(i=l-1 ; i>=0 ; i--) {
        printf("%c", c[i]);
    }
    printf("\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);
    int n;
    fib();
    //for(int i=0 ; i<100 ; i++) {printf("%d -> ", i);strRev(st[i-1]);}
    while(scanf("%d", &n)!=EOF)
    {
        printf("The Fibonacci number for %d is ", n);
        if(n==0) printf("0\n");
        else
            strRev(st[n-1]);
    }
    return 0;
}
