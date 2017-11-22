#include <stdio.h>

int status[1000000];
int c[500], sum, m;

void dp()
{
    int i, j, coin;
    status[0]=1;
    for(i=0 ; i<m ; i++) {
        coin= c[i];
        for(j=sum ; j>=0 ; j--) {
            if(j+coin>sum || status[j]==0) continue;
            status[j+coin]= status[j]+1;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, i, j;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &m);
        sum=0;
        for(j=0 ; j<m ; j++) {
            scanf("%d", &c[j]);
            sum= sum+c[j];
        }

        dp();

        for(j= sum/2 ; j>=0 ; j--) {
            if(status[j]>0) {
                break;
            }
        }
        printf("%d\n", sum-j-j);
        for(j=0 ; j<=sum ; j++)
            status[j]= 0;
        //for(j=0 ; j<m ; j++) c[j]=0;
    }
    return 0;
}
