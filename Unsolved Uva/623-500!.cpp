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

char st[1009][1000009];

int main()
{
    int i, l, j, x, q, carry, k, y, p;
    st[0][0]=st[1][0]=1+'0';
    st[0][1]=st[1][1]=0;
    for(i=2 ; i<5 ; i++) {
        l= floor(log(i))+1;
        //for(j=0 ; j<l ; j++) {
            //x= x%10;
            q= strlen( st[i-1] );
            for(p=0,carry=0,k=0 ; k<q ; k++)
            {
                y= (st[i-1][k]-'0')*i;
                printf("%d->>>>> y=%d carry=%d (carry+y)%c10=%d st[i][p]=%c\n",i, y, carry,'%', (carry+y)%10, ((carry+y)%10)+'0');
                st[i][p]= (carry+y)%10 +'0';
                carry= (carry+y)/10;
                p++;
            }
            st[i][p]=0;
        //}
    }
    printf("%s\n", st[4]);
    return 0;
}
