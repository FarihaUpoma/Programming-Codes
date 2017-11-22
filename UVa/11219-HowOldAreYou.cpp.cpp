#include <stdio.h>

int main()
{
    int y1,y2, m1,m2, d1,d2, t, i;
    scanf("%d", &t);
    for(i=0 ; i<t; i++) {
        scanf("%d/%d/%d%d/%d/%d", &d1,&m1,&y1, &d2, &m2, &y2);
        printf("Case #%d: ",i+1);
        if( (d1-d2) <0)
            m1--;
        if(m1-m2 <0)
            y1--;
        if(y1-y2 <0)
            printf("Invalid birth date\n");
        else if( y1-y2 >130)
            printf("Check birth date\n");
        else
            printf("%d\n", y1-y2);
    }
    return 0;
}
