#include <stdio.h>
#include <string.h>

char s[1000009], t[1000009];

int main()
{
    int i, j, c, m;
    while(scanf("%s", s)!=EOF)
    {
        scanf("%s", t);
        c=0;
        m=0;
        for(i=0 ; i<strlen(s) ; i++) {
            for(j=m ; j<strlen(t) ; )
                if( s[i]==t[j] ) {
                    c++;
                    m=j+1;
                    break;
                }
                else j++;
        }
        if( c== strlen(s) )
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
