#include <stdio.h>

int main()
{
    int i, sum;
    char w[100];
    while(scanf("%s", w)!=EOF)
    {
        for(i=0, sum=0 ; w[i]!=0 ; i++) {
            if(w[i]>='a' && w[i]<='z') w[i] = w[i]-96;
            else if(w[i]>='A' && w[i]<='Z') w[i] = w[i] -38;
            sum=sum+ w[i];
        }
        int c=0;
        for(i=1 ; i<=sum ; i++) {
            if(sum%i==0)
                c++;
        }
        if(c<=2)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}
