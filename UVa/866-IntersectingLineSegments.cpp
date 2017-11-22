#include <stdio.h>
#include <math.h>

#define eps 1e-10

int a[1000][1000];

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
    int n, i, j, seg, t, k;
    scanf("%d", &t);
    for(k=0 ; k<t ; k++) {
        scanf("%d", &n);
        seg=n;
        for(i=0 ; i<n ; i++) {
            scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        }
        for(i=0 ; i<n ; i++) {
            for(j=i+1 ; j<n ; j++) {
                if( ifIntersect(a[i][0],a[i][1],a[i][2],a[i][3],a[j][0],a[j][1], a[j][2],a[j][3])) seg=seg+2;
            }
        }
        if(k>0) printf("\n");
        printf("%d\n", seg);
    }
    return 0;
}
