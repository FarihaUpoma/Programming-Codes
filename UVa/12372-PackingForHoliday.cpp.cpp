#include <stdio.h>

int main()
{
    //freopen("input.txt", "r", stdin);
    int l, w, h, t, i;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        //printf("Case %d: ", i+1);
        scanf("%d %d %d", &l ,&w, &h);
        if(l>20 || w>20 || h>20)
            printf("Case %d: bad\n", i+1);
        else printf("Case %d: good\n", i+1);
    }
    return 0;
}
