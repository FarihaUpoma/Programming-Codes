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
    //freopen("input.txt", "r", stdin);
    char q, w;
    int f,g, s;
    //while(1)
    //{
        f=0;g=0;s=0;
        while(scanf("%c", &q)==1)
        {
            if(f==0 && isalpha(q))
            {
                s=1;
                if(q=='a' || q=='e' || q=='i' || q=='o' ||q=='u' ||q=='A' || q=='E' || q=='I' || q=='O' ||q=='U' ) {
                    printf("%c", q);
                    g=0;
                }
                else {
                    w=q;
                    g=1;
                }
                f=1;
            }
            else if( isalpha(q))
                printf("%c", q);
            else if( !isalpha(q))
            {
                if(g==0 && s==1) printf("ay");
                else if(g==1 && s==1) printf("%cay", w);
                printf("%c", q);
                f=0;
                s=0;
            }
        }
        //printf("\n");
    //}
    return 0;
}
