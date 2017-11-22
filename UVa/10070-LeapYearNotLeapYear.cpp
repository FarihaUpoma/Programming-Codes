#include <stdio.h>
#include <cstring>

char a[1000009];

int div( char a[], int b )
{
    int i, len= strlen(a), rem=0;
    for(i=0 ; i<len ; i++) {
        rem= rem*10+ ( a[i]-'0' );
        rem= rem%b;
    }
    return rem;
}

int main()
{
    int f, fool=0, b;
    while(scanf("%s", a)!=EOF)
    {
        if(fool==1)
            printf("\n");
        fool=1;
        f=0;
        b=0;
        if( (div(a, 4)==0 && div(a, 100)!=0) || div(a, 400)==0) {
            printf("This is leap year.\n");
            f=1;
        }
        if(f==1 && div(a, 55)==0)
            f=2;
        if( div(a, 15) ==0) {
            printf("This is huluculu festival year.\n");
            b=1;
        }
        if(f==2)
            printf("This is bulukulu festival year.\n");
        else if(f==0 && b==0) printf("This is an ordinary year.\n");
    }
    return 0;
}
