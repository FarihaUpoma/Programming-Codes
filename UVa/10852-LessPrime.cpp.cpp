#include <stdio.h>
#include <math.h>

int a[1000009];

int main()
{
    int k,p,t, c, i, j=0, n;
    for(k=2 ; k<10000 ; k++) {
        c=0;
        for(i=1 ; i<= sqrt(k) ; i++) {
            if(k%i==0)
                c++;
        }
        if(c==1) {
            a[j] = k;
            j++;
        }
    }

    scanf("%d", &t);
    for(p=0 ; p<t; p++) {
        scanf("%d", &n);
        for(i=0 ; a[i]< n/2 ; i++);

        for(k=i ; ; k++) {
            if(a[k]<= n && n< 2*a[k])
                break;
        }
        printf("%d\n", a[k]);
    }
    return 0;
}
