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

char st[5001][109];

void fib()
{
    int i, l, carry, x, j;
    st[0][0]=st[1][0]='1';
    for(i=2 ; ; i++) {
        if( strlen(st[i-2])>strlen(st[i-1])) l= strlen(st[i-2]);
        else l= strlen(st[i-1]);
        for(carry=0,j=0 ; j<l ; j++) {
            if( st[i-2][j]==0 || st[i-1][j]==0) x= st[i-2][j]+st[i-1][j]-'0' ;
            else x= st[i-2][j]+st[i-1][j] - 2*'0';
            st[i][j] = (x+carry)%10 +'0';
            carry= (x+carry)/10;
        }
        while(carry) {
            st[i][j++]= carry%10 +'0';
            carry= carry/10;
        }
        st[i][j]=0;
        l= strlen( st[i]);
        if(l>101) break;
    }
}

void strRev()
{
    int i, l, j, k, m;
    for(i=0 ; ; i++) {
        l= strlen( st[i]);
        if(l==0) break;
        m= l/2;
        for(j=0 , k=l-1 ; j<m ; j++, k--) {
            char q= st[i][j];
            st[i][j]= st[i][k];
            st[i][k]= q;
        }
    }
}

int main()
{
    int i, l, l1, l2, c, f;
    char a[105], b[105];

    fib();
    strRev();

    while(scanf("%s %s", a, b))
    {
        if( strcmp(a, "0")==0 && strcmp(b, "0")==0) break;
        l1= strlen(a);
        l2= strlen(b);
        for(f=0,c=0,i=1 ; ; i++) {
            l= strlen( st[i] ) ;
            if( l>= l1) {
                if( l==l1) {
                    if(strcmp( st[i], a)>=0) f=1;
                }
                else f=1;
            }
            if(f==1) {
                c++;
            }
            if(l>=l2) {
                if( l==l2) {
                    if( strcmp(st[i], b)==1) {
                        c--;
                        break;
                    }
                }
                else {
                    c--;
                    break;
                }
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
