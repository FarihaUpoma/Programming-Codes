#include <stdio.h>

int main()
{
    int k, n,m, x,y, i;
    while(scanf("%d", &k)!=EOF)
    {
        if(k==0) break;
        else {
            scanf("%d %d", &n,&m);
            for(i=0 ; i<k ; i++) {
                scanf("%d %d", &x, &y);
                if(x>n && y>m)
                    printf("NE\n");
                else if(x>n && y<m)
                    printf("SE\n");
                else if(x<n && y<m)
                    printf("SO\n");
                else if(x<n && y>m)
                    printf("NO\n");
                else printf("divisa\n");
            }
        }
    }
    return 0;
}
