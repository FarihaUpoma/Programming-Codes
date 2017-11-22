#include <stdio.h>
#include <string.h>

unsigned long long int rev(unsigned long long int n)
{
    unsigned long long int i;
    unsigned long long int m=0;
    for(i=n ; i>0 ; i=i/10)
        m= (m*10) + (i%10);
    return m;
}

bool if_pal( unsigned long long int n)
{
    int len, i, k, c=0;
    char b[10009];
    sprintf(b, "%llu", n);
    len=strlen(b);
    for(i=0 , k=len-1 ; i<len/2 ; i++, k--) {
        if( b[i]==b[k]) c++;
        else break;
    }
    if(c==len/2) return true;
    else return false;
}

int main()
{
    unsigned long long int n, sum, i, c;
    int t, k;
    scanf("%d", &t);
    for(k=0 ; k<t ; k++) {
        sum=0;
        c=0;
        scanf("%llu", &n);
        for(i=n ; ; i=sum) {
            sum=rev(i)+i;
            c++;
            if(if_pal(sum)) break;
        }
        printf("%llu ", c);
        printf("%llu\n", sum);
    }
    return 0;
}

