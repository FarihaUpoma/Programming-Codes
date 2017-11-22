#include <stdio.h>

int main()
{
    int c, diff , t, i;
    double r;
    scanf("%d", &t);
    for(i=0  ; i<t ; i++) {
        scanf("%d %d", &c, &diff);
        r=(1.8*c +diff)*5;
        printf("Case %d: %.2lf\n", i+1, r/9);
    }
    return 0;
}
