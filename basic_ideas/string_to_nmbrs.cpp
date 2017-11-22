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

char a[100];

int main()
{
    int x, prblm, pl, tym, f, l, j, i, g;
    char sub;
    gets(a);
    l= strlen(a);
    x=0;prblm=0;tym=0;j=-1;f=1;pl=0;
    for(i=j+1 ;  ; i=j+1) {
        if(isalpha(a[i])) break;
        x=0;g=0;
        if( isdigit(a[i])) {
            for(x=0,j=i ; ; j++) {
                if(a[j]==' ') break;
                x= x*10+ (a[j]-'0');
                g=1;
            }
            if(f==1 && g==1) {
                pl= x;
                f=2;
            }
            else if(f==2 && g==1) {
                prblm= x;
                f=3;
            }
            else if(f==3 && g==1) {
                tym= x;
                break;
            }
        }
    }

    sub= a[l-1];
    printf("%d %d %d %c\n", pl, prblm, tym, sub);
    return 0;
}
