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
    for(i=2 ;  ; i++) {
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
        l= strlen(st[i]);
        if(l>150) break;
    }
}

void strRev(char *c)
{
    int l, m, i, j;
    char q;
    l= strlen(c);
    m= l/2;
    for(i=0 , j=l-1 ; i<m ; i++, j--)
    {
        q= c[i];
        c[i]=c[j];
        c[j]=q;
    }
}

int main()
{
    char a[110], b[110];
    int i, f, c, la, lb, l;
    fib();
    while(scanf("%s %s",a, b))
    {
        if( strcmp(a, "0")==0 && strcmp(b, "0")==0) break;
        c=0;
        f=0;
        la= strlen(a);
        lb= strlen(b);
        for(i=1 ; ; i++) {
            strRev(st[i]);
            l= strlen(st[i]);
            if(l>=la) {
                if(l==la) {
                    if(strcmp( st[i], a)>=0) f=1;
                }
                else f=1;
            }
            if(f==1) {
                c++;
            }
            if(l>=lb) {
                if(l==lb) {
                    if(strcmp( st[i], b)==1) {
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
