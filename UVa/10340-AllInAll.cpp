#include <stdio.h>
#include <string.h>

char a[1000009], b[1000009];

int main()
{
    int k, n, m, c, i, j;
    while(scanf("%s %s", a, b)!=EOF)
    {
        k=-1;
        n= strlen(a);
        m= strlen(b);
        for(c=0,i=0 ; i<n ; i++) {
            for(j=k+1 ; j<m ; j++) {
                if( a[i]==b[j])
                {
                    c++;
                    k=j;
                    break;
                }
            }
        }
        printf("%d\n", c);
        if(c==n) printf("Yes\n");
        else printf("No\n");
    }
}
