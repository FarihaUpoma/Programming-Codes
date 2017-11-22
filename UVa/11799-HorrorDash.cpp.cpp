#include <stdio.h>

int main()
{
    int t, n, i, k, max, s;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        max=0;
        for(k=0 ; k<n ; k++) {
            scanf("%d", &s);
            if(s>max)
                max=s;
        }
        printf("Case %d: %d\n", i+1, max);
    }
    return 0;
}
