#include <stdio.h>

int main()
{
    int a, b,l , k;
    while(scanf("%d %d", &a, &b)!=EOF)
    {
        if(a==-1 && b==-1) break;
        else {
            if(a>b) {
                l= a-b;
                k= (b+100)-a;
                if(l<k)
                    printf("%d\n", l);
                else printf("%d\n", k);
            }
            else {
                l= b-a;
                k= (a+100)-b;
                if(l<k)
                    printf("%d\n", l);
                else printf("%d\n", k);
            }
        }
    }
    return 0;
}
