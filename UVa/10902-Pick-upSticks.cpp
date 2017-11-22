#include <stdio.h>

#define eps 1e-10

double a[100009][10];

double cross(int x1,int y1,int x2,int y2,int x3, int y3)
{
    double d;
    d= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return d;
}

bool ifIntersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    double d1, d2, d3, d4;
    d1= cross(x1,y1,x2,y2,x3,y3);
    d2=cross(x1,y1,x2,y2,x4,y4);
    d3=cross(x3,y3,x4,y4,x1,y1);
    d4= cross(x3,y3,x4,y4,x2,y2);
    if(d1*d2 < eps && d3*d4< eps) return true;
    else return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, i, j, count, c;
    while(scanf("%d", &t) && t)
    {
        for(i=1 ; i<=t ; i++) {
            a[i][0]=1;
            scanf("%lf %lf %lf %lf", &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
        }
        for(count=0,i=1 ; i<=t ; i++) {
            for(j=i+1 ; j<=t ; j++) {
                if( ifIntersect(a[i][1], a[i][2],a[i][3],a[i][4], a[j][1],a[j][2],a[j][3], a[j][4])) {
                    a[i][0]=0;
                    count++;
                    break;
                }
            }
        }
count= t-count;
        /*for(count=0,i=1 ; i<=t ; i++) {
            if(a[i][0]==1) {
                count++;
            }
        }*/
        //printf("count=%d\n", count);
        printf("Top sticks: ");
        for(c=1,i=1 ; i<=t ; i++) {
            if(a[i][0]==1) {
                if(c==count) printf("%d.\n", i);
                else {
                    printf("%d, ", i);
                    c++;
                }
            }
        }
    }
    return 0;
}
