#include <stdio.h>
#include <string.h>

int div( char a[], int b )
{
    int i, len= strlen(a), rem=0;
    for(i=0 ; i<len ; i++) {
        rem= rem*10+ ( a[i]-'0' );
        rem= rem%b;
    }
    return rem;
}

int main()
{
    char a[1000009];
    while(scanf("%s", a))
    {
        if( strcmp(a, "0")==0) break;
        else {
            if( div(a, 17)==0) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
