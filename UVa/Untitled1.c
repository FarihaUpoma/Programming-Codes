#include <stdio.h>

int sum(  int x)
{
    int b , c;
    for(c=x, b=0 ;  ; c=c/10) {
        b=b+(c%10);
        if(c==0) break;
    }
    return b;
}

int main()
{
    int x, i, c, j;
    scanf("%d", &x);
    j=sum(x);
    for(i=j ; ; ) {
        if(i%9==0 ) {
            c++;
             i=sum(i);
        }
        else break;
    }
    printf("%d\n", c);
    return 0;
}
