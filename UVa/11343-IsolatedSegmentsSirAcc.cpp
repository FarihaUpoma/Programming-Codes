#include <stdio.h>
#include <math.h>

#define eps 1e-10

double a[100][10];



double max(double a, double b ) {
    if ( a > b ) return a;
    return b;
}

double min(double a, double b) {
    if ( a > b ) return b;
    return a;
}



bool onSegment(double x1, double y1, double x2, double y2, double x3, double y3)
{
    if ( x2 <= max(x1,x3) && x2 >= min(x1,x3) && y2 <= max(y1, y3) && y2 >= min(y1, y3)) return true;
    return false;
}

double cross(double x1,double y1,double x2,double y2,double x3, double y3)
{
    double d;
    d= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return d;
}

bool ifIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
    double d1, d2, d3, d4;
    d1= cross(x1,y1,x2,y2,x3,y3);
    d2=cross(x1,y1,x2,y2,x4,y4);
    d3=cross(x3,y3,x4,y4,x1,y1);
    d4= cross(x3,y3,x4,y4,x2,y2);
    if ( d1*d2 < -eps && d3*d4 < -eps  )   return true;        // general case

    //Special Cases

    if ( fabs(d1) < eps && onSegment(x1, y1, x3,y3, x2, y2)) return true;

    if ( fabs(d2) < eps && onSegment(x1, y1, x4, y4, x2, y2)) return true;

    if ( fabs(d3) < eps && onSegment(x3, y3, x1, y1, x4, y4)) return true;

    if ( fabs(d4) < eps && onSegment(x3, y3, x2, y2, x4, y4)) return true;

    return false;

}

int main()
{
   //freopen("in.txt", "r", stdin);
//  freopen("in.txt", "r", stdin);
    int t, i, n, j, k, count;
    scanf("%d", &t);
    for(i=0 ; i<t;  i++) {
        scanf("%d", &n);
        for(j=0 ; j<n ; j++) {
            a[j][0]=1;
            scanf("%lf %lf %lf %lf", &a[j][1],&a[j][2],&a[j][3],&a[j][4]);
        }
        for(j=0 ; j<n ; j++) {
            for(k=j+1 ; k<n ; k++) {
                if( ifIntersect(a[j][1],a[j][2],a[j][3],a[j][4],a[k][1],a[k][2],a[k][3],a[k][4]))
                {
                    //printf("kore\n");
                    a[j][0]=a[k][0]=0;
                }
            }
        }
        for(count=0,j=0 ; j<n ; j++) {
            if( fabs(a[j][0]-1) < eps ) count++;
        }
        printf("%d\n", count);
    }
}
