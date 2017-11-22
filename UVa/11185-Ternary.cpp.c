#include <stdio.h>
#include <string.h>

int main()
{
    long long int a,i;
    int l,j;
    char b[100000];
    while(scanf("%lld", &a))
    {
        if( a< 0 ) break;
        if(a==0) printf("0\n");
        else {
            for(j=0 , i=a ; i>0 ; i=i/3, j++) {
                b[j] = i%3+48;
            }
            b[j]=0;
            l=strlen(b);
            for(i= l-1 ; i>=0 ; i--)
                printf("%c", b[i]);
            printf("\n");
        }
    }
    return 0;
}
