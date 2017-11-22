#include <stdio.h>
#include <math.h>

int main()
{
    int n, l, u, i, k;
    scanf("%d %d %d", &n, &l, &u);
    for(k=0,i=n ; i>=0 ; i=i/2)
        a[k++]= i%2;
    for(i=0 ; i<k ; i++)
        printf("%d", a[i]);
    return 0;
}
