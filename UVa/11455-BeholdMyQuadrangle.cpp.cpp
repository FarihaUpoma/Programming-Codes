#include <stdio.h>

int main()
{
    long long int a,b,c,d , t, i;
    scanf("%lld", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d %lld %lld %lld", &a, &b, &c, &d);
        if( (a+b+c)<d || (a+b+d)<c || (a+c+d)<b || (b+c+d)<a)
            printf("banana\n");
        else {
            if(a==b && b==c && c==d)
                printf("square\n");
            else if( (a==c && b==d) || (a==b && c==d) || (a==d && b==c) )
                printf("rectangle\n");
            else
                printf("quadrangle\n");
        }
    }
    return 0;
}
