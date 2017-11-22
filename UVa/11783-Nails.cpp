#include <stdio.h>

#define eps 1e-10

int a[1000][1000];

double cross(int x1,int y1,int x2,int y2,int x3,int y3)
{
    double d;
    d= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return d;
}

bool ifIntersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    double d1,d2,d3,d4;
    d1= cross(x1,y1,x2,y2,x3,y3);
    d2= cross(x1,y1,x2,y2,x4,y4);
    d3= cross(x3,y3,x4,y4,x1,y1);
    d4= cross(x3,y3,x4,y4,x2,y2);
    if( d1*d2<eps && d3*d4<eps) return true;
    else return false;
}

int main()
{
    int t, i, n, j, k, nail, f;

    while(scanf("%d", &n) && n)
    {
        for(j=0 ; j<n ; j++) {
            a[j][0]=0;
            scanf("%d %d %d %d", &a[j][1],&a[j][2],&a[j][3],&a[j][4]);
        }
        for(nail=0,j=0 ; j<n ; j++) {
            for(f=0,k=j+1 ; k<n ; k++) {
                if( ifIntersect(a[j][1],a[j][2],a[j][3],a[j][4],a[k][1],a[k][2],a[k][3],a[k][4])) {
                    //printf("%d korse with %d\n", j+1, k+1);
                    nail++;
                    f=1;
                    a[k][0]=1;
                }
            }
            if(f==0 && a[j][0]==0) nail=nail+2;
            //printf("nail=%d\n", nail);
        }
        printf("%d\n", nail);
    }
    return 0;
}
