 #include <stdio.h>
#include <string.h>

int main()
{
    int m,k,i,n,tmp,l, g;
    char a[1000009];
    while(scanf("%d", &g)!=EOF)
    {
        if(g==0) break;
        else {
            scanf("%s", a);
            l=strlen(a);
            g=l/g;
            m=g/2;
            for(k=0 ; k<l ; k=k+g) {
                for(i=k , n=k+g-1 ; i<k+m ; i++, n--) {
                    tmp=a[i];
                    a[i] = a[n];
                    a[n]=tmp;
                }
            }
            printf("%s\n", a);
        }
    }
    return 0;
}
