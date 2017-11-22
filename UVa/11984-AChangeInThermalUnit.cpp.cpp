#include <stdio.h>

int main()
{
    double c , f , t, i, diff;
    scanf("%lf", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%lf %lf", &c, &f);
        diff= (9*c)/5 + 32 +f;
        printf("Case %.0lf: %.2lf\n", i+1, ( (diff-32)*5)/9);
    }
    return 0;
}
