#include <stdio.h>

int main()
{
    int Term1 , Term2 , Final , Attendance , ct1, ct2, ct3 , T, i;
    double ct, t;
    scanf("%d", &T);
    for( i=0 ; i<T ; i++) {
        scanf("%d %d %d %d %d %d %d", &Term1 , &Term2 , &Final , &Attendance , &ct1, &ct2, &ct3);
        if(ct1 > ct2) {
            if(ct2 > ct3 )
                ct= (ct1+ct2)/2;
            else
                ct= (ct1+ct3)/2;
        }
        else {
            if(ct1 > ct3 )
                ct= (ct2+ct1)/2;
            else
                ct= (ct2+ct3)/2;
        }
        printf("Case %d: ", i+1);
        t=Term1 + Term2 + Final + Attendance + ct;
        if(t >= 90)
            printf("A\n");
        else if(t >= 80 && t < 90)
            printf("B\n");
        else if(t >= 70 && t< 80)
            printf("C\n");
        else if(t >= 60 && t< 70)
            printf("D\n");
        else if(t  < 60)
            printf("F\n");
    }
    return 0;
}
