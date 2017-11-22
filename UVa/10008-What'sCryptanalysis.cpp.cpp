#include <stdio.h>
#include <string.h>

 int b[1000009] ;
 char a[1000009];

int main()
{
    int i, k, max,j, c=0, n, u;
    for(i=0 ; i<26 ; i++) b[i] = 0;
    scanf("%d", &n);
    getchar();
    for(u=0 ; u<n ; u++) {
        gets(a);
        for(i=0 ; i<strlen(a) ; i++) {
            if( a[i]>64 && a[i]< 91)
                b[ a[i]-65 ]++;
            else if(a[i]>96 && a[i]<123)
                b[ a[i]-97 ]++;
        }
    }

    for(i=0 ; i<26 ; i++) {
        if( b[i]>0) c++;
    }
    for(k=0 ; k<c ; k++) {
	max=b[0];
    j=0;
        for(i=0 ; i<26 ; i++)
            if( b[i] > max ) {
                max= b[i];
                j=i;
            }
        printf("%c %d\n",j+65, max);
        b[j]=0;
    }
    return 0;
}
