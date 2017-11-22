#include <stdio.h>

int main()
{
    int g, l  , t, i, k;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d %d", &g, &l);
        k=l/g;
        if(g*k != l) printf("-1\n");
        else {
            if(g==1)
                printf("%d %d\n", g, l);
            else {
                l=g*( (g*l)/(g*g) );
                printf("%d %d\n", g, l);
            }
        }
    }
    return 0;
}
