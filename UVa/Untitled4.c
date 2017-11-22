#include <stdio.h>
#include <string.h>

char b[1000];

char cpy( char a[] )
{
    int i, j,l;
    //scanf("%s", a);
    l=strlen(a);
    printf("%d\n", l);
    for(j=strlen(a) ; j>=1 ; j--)
        b[j] = a[j-1];
    b[1]='?';
    b[l+1]=0;
    //printf("%s\n", a);
    return b;
}

int main()
{
    int i;
    char a[1000];
    scanf("%s", a);
    a=cpy(a);
    printf("%s\n", a);
    return 0;
}
