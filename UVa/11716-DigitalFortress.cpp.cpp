#include <stdio.h>
#include <string.h>

int main()
{
    int l, i, j, m, k, t, n;
    char a[1000009];
    scanf("%d", &t);
    getchar();
    for(n=0 ; n<t ; n++) {
        gets(a);
        l=strlen(a);
        for(i=1 ;  ; i++) {
            j=i*i;
            if(j >=l) break;
        }

        if(j==l) {
            for(m=0 ; m<i ; m++) {
                for(k=m ; k<j ; k=k+i)
                    printf("%c", a[k] );
            }
            printf("\n");
        }
        else printf("INVALID\n");
    }
    return 0;
}
