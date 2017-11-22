#include <stdio.h>

int main()
{
    int t, y1, y2, d1, d2, m1, m2, i;
    scanf("%d", &t);
    for( i=0 ; i<t ; i++) {
        scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);
        printf("Case #%d: ", i+1);
        if(y1>y2)
            printf("%d\n", y1-y2);
        else if(y1==y2) {
            if(m1>m2)
                printf("0\n");
            else if(m1==m2) {
                if(d1>d2)
                    printf("0\n");
                else
                    printf("Invalid birth date\n");
            }
            else
                 printf("Invalid birth date\n");
        }
        else
             printf("Invalid birth date\n");
    }
    return 0;
}
