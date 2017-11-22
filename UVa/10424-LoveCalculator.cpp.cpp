#include <stdio.h>
#include <string.h>

int sum( int x)
{
    int b , c;
    for(c=x, b=0 ;  ; c=c/10) {
        b=b+(c%10);
        if(c==0) break;
    }
    return b;
}

int main()
{
    int i, sum1, sum2, j;
    double k;
    char a[100], b[100];
    while(gets(a))
    {
        gets(b);
        if(strlen(a)==0 || strlen(b)==0) printf("0.00 %c\n", '%');
        else {
            for(i=0,sum1=0 ; i< strlen(a) ; i++) {
                if( a[i]>=65 && a[i]<=90 ) {
                    a[i]= a[i]-64;
                    sum1=sum1+a[i];
                }
                else if( a[i]>= 97 && a[i]<= 122) {
                    a[i]=a[i]-96;
                    sum1=sum1+a[i];
                }

            }
            for(i=0,sum2=0 ; i< strlen(b) ; i++) {
                if( b[i]>=65 && b[i]<=90 ) {
                    b[i]= b[i]-64;
                    sum2=sum2+b[i];
                }
                else if( b[i]>= 97 && b[i]<= 122) {
                    b[i]=b[i]-96;
                    sum2=sum2+b[i];
                }

            }

            for(i=sum1 ; i>9 ; i=sum(i));
            for(j=sum2 ; j>9 ; j=sum(j));


            if(i>j) {
                k=j*100;
                printf("%.2lf %c\n", k/i, '%');
            }
            else {
                k=i*100;
                printf("%.2lf %c\n", k/j, '%');
            }
        }
    }
    return 0;
}
