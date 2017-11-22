#include <stdio.h>
#include <string.h>

int main()
{
    int k, m, a, r, g, i, t, q, p, n, h;
    char b[1000009];
    scanf("%d", &n);
    for(h=0 ; h<n ; h++) {
        scanf("%s", b);
        m=0, a=0, r=0, g=0, i=0, t=0, p=0;
        for(k=0 ; k<strlen(b) ; k++) {
            if(b[k] == 'M') m++;
            else if(b[k] == 'A') a++;
            else if(b[k] == 'R') r++;
            else if(b[k] == 'G') g++;
            else if(b[k] == 'I') i++;
            else if(b[k] == 'T') t++;
        }
        for(q=1 ; q<=m ; q++) {
            if(a>=3*q && r>=2*q && g>=1*q && i>=1*q && t>=1*q)
                p++;
        }
        printf("%d\n", p);
    }
    return 0;
}
