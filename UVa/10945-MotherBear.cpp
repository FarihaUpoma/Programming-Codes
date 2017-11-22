#include <stdio.h>
#include <string.h>

char a[1000009], c[1000009];

int main()
{
    int l, m, i,k, p,q;
    while(gets(a))
    {
        if( strcmp( a, "DONE") == 0) break;
        else {
            p=0;
            l=strlen(a);
            for(i=0 ; i<l ; i++) {
                if( (a[i]>64 && a[i]<91) || (a[i]>96 && a[i]<123) ) {
                    c[p] = a[i];
                    p++;
                }
            }
            c[p]=0;

            q=strlen(c);
            m=q/2;
            for(i=0 ,k =q-1 ; i<=m ; i++,k--) {
                if(c[i]>64 && c[i]<91) c[i]=c[i]+32;
                if(c[k]>64 && c[k]<91) c[k]=c[k]+32;

                if( c[i] != c[k]) break;
            }

            if(i>m) printf("You won't be eaten!\n");
            else printf("Uh oh..\n");
        }
    }
    return 0;
}
