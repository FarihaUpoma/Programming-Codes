#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    int i, j,l;
    scanf("%s", a);
    l=strlen(a);
    printf("%d\n", l);
    for(j=strlen(a) ; j>=1 ; j--)
        a[j] = a[j-1];
    a[1]='?';
    a[l+1]=0;
    printf("%s\n", a);
    return 0;
}
