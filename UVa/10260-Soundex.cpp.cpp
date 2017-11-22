#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char a[1000009];
    while(scanf("%s", a)!=EOF)
    {
        for(i=0 ; i<strlen(a) ; i++) {
            if(a[i] =='B' || a[i]=='P' || a[i]=='F' || a[i] == 'V') a[i]='1';
            else if( a[i]=='C' || a[i]=='G' || a[i]=='J' || a[i]=='K' || a[i]=='Q'|| a[i]=='S' || a[i]=='X' || a[i]=='Z') a[i]='2';
            else if( a[i]=='D' || a[i]=='T' ) a[i]='3';
            else if( a[i]=='L' ) a[i]='4';
            else if( a[i]== 'M' || a[i]== 'N') a[i]='5';
            else if( a[i]=='R' ) a[i]='6';
        }
        for(i=0 ; i<strlen(a) ; i++) {
            if( (a[i] >48 && a[i] <58 ) && a[i]!=a[i-1])
                printf("%c", a[i] );
        }
        printf("\n");
    }
    return 0;
}
