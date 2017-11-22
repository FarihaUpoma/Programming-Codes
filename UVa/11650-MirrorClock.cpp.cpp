#include <stdio.h>

int main()
{
    int t, i, h, m;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d:%d", &h, &m);
        if(h==12) h=0;
        if(m==0)
            printf("%.2d:00\n", 12-h);
        else {
            if(12-h-1==0)
                printf("%.2d:%.2d\n", 12, 60-m);
            else
                printf("%.2d:%.2d\n", 12-h-1, 60-m);
        }
    }
    return 0;
}
