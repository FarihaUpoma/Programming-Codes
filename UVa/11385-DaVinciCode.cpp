#include <stdio.h>
#include <string.h>

int a[1000009];
char b[10000], p[10000], q[10000];

int main()
{
    int n, i, sum, c, k, max, l, t;
    scanf("%d", &t);
    for(l=0 ; l<t  ; l++ ) {
        scanf("%d", &n);
        for(i=0 ; i<n ; i++) scanf("%d", &a[i] );
        getchar();
        gets(q);
        for(k=0 ; k<n; k++) {
            c=0;
            for(i=1 , sum=1 ; ; i=i+sum) {
                sum=sum+i;
                c++;
                if(sum==a[k]) {
                    a[k]= c*2;
                    break;
                }
                else if (i==a[k]) {
                    a[k]= c*2-1;
                    break;
                }
            }
        }
        max=0;
        for(i=0 ; i<n ; i++)
            if( a[i]>max) max= a[i];

        for(i=0 ; i<max ; i++) b[i]= ' ';
        k=0;
        for(i=0 ; i<strlen(q) ; i++) {
            if( q[i]>64 && q[i]<91) {
                p[k]=q[i];
                k++;
            }
        }
        for(i=0 ; i<max ; i++ ) {
            for(k=0 ; k<n ; k++) {
                if( i+1 == a[k])
                    b[i] = p[k];
            }
        }
        printf("%s\n", b);
        for(i=0 ; i<max ; i++) b[i]=0;
    }
    return 0;
}
