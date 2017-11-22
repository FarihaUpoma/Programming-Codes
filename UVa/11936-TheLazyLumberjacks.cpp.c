#include <stdio.h>

int main()
{
    int n, a, b, c,i;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a>= b && a>=c) {
            if((b+c) > a) printf("OK\n");
            else printf("Wrong!!\n");
        }
        else if(b>=c && b>=a) {
            if(c+a >b) printf("OK\n");
            else printf("Wrong!!\n");
        }
        else if(c>=a && c>=b) {
            if(a+b > c) printf("OK\n");
            else printf("Wrong!!\n");
        }
        else if((a==b && b==c) || (a==b && a>c) || (a==c && a>b) || (b==c && b>a)) printf("OK\n");
    }
    return 0;
}
