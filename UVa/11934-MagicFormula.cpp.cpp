#include <stdio.h>

int main()
{
    int a,b,c,d,l,i,m;
    while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &l)!=EOF)
    {
        if(a==0 &&b==0 && c==0 && d==0 && l==0) break;
        else {
            m=0;
            for(i=0 ; i<=l ; i++) {
                if( (a*i*i + b*i + c)%d ==0 ) m++;
            }
            printf("%d\n", m);
        }
    }
    return 0;
}
