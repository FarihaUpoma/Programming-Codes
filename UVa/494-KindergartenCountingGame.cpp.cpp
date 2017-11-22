#include <stdio.h>
#include <string.h>

char a[1000009];

int main()
{
    int i, c, l;

    while(gets(a))
    {
        c=0;
        l=strlen(a);
        if(l==0) c=-1;
        else {
            for(i=0 ; i<l ; i++) {
                    if( a[i] <'A' || (a[i] >'Z' && a[i] <'a') || a[i] >'z' ) {
                        if( (a[i+1]>=65 && a[i+1]<=90) || (a[i+1]>=97 && a[i+1]<=122) )
                            c++;
                        else
                            c=c;
                    }
            }
        }
        printf("%d\n", c+1);
    }
    return 0;
}
