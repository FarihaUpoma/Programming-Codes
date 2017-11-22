#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

#define eps 1e-10

struct point
{
    int x;
    int y;
};

struct line
{
    point p1;
    point p2;
};

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


double cross(point p1, point p2, int x, int y)
{
    double d= p1.x*(p2.y-y)+p2.x*(y-p1.y)+x*(p1.y- p2.y);
    return d;
}

bool ifIntersect( point p1, point p2, line l)
{
    double d1,d2,d3,d4;
    d1= cross(p1, p2, l.p1.x, l.p1.y);
    d2= cross(p1,p2, l.p2.x, l.p2.y);
    d3= cross(l.p1, l.p2, p1.x, p1.y);
    d4= cross(l.p1, l.p2, p2.x, p2.y);
    if(d1*d2<-eps && d3*d4<-eps) return true;

    if ( fabs(d1) < eps && onSegment(p1.x,p1.y, l.p1.x, l.p1.y, p2.x,p2.y)) return true;

    if ( fabs(d2) < eps && onSegment(p1.x,p1.y, l.p1.x, l.p1.y, p2.x,p2.y)) return true;

    if ( fabs(d3) < eps && onSegment(l.p1.x, l.p1.y, p1.x, p1.y, l.p2.x, l.p2.y)) return true;

    if ( fabs(d4) < eps && onSegment(l.p1.x, l.p1.y, p1.x, p1.y, l.p2.x, l.p2.y)) return true;


    return false;
}

/*double inArea(point p1, point p2, line l)
{
    double d;
    d= cross(p1, p2, l.p1.x, l.p1.y);
    return d;
}*/

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);
    line l5;
    point p1,p2,p3,p4;
    int t, i, f=0;
    double d1,d2,d3,d4;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d %d %d %d %d %d %d %d", &l5.p1.x, &l5.p1.y, &l5.p2.x, &l5.p2.y, &p1.x, &p1.y, &p3.x, &p3.y);
                if(p1.x>p3.x) swap(p1.x, p3.x);
                if(p1.y<p3.y) swap(p1.y, p3.y);
                //printf("left top= %d,%d ri8 bottom-%d,%d\n", p1.x,p1.y, p3.x, p3.y);
                p2.x= p1.x;
                p2.y= p3.y;

                p4.x= p3.x;
                p4.y= p1.y;

        if( ifIntersect( p1,p2,l5 ) || ifIntersect(p2,p3, l5) || ifIntersect(p3,p4, l5) || ifIntersect(p4, p1, l5)) {
            printf("T\n");
        }
        else {
            d1= cross( p1,p2,l5.p1.x,l5.p1.y );
            d2= cross( p2,p3, l5.p1.x,l5.p1.y );
            d3= cross( p3,p4, l5.p1.x,l5.p1.y );
            d4= cross( p4, p1, l5.p1.x,l5.p1.y );
            //printf("%lf %lf %lf %lf\n", d1,d2,d3,d4);
            if(d1*d2<eps || d2*d3<eps || d3*d4<eps) printf("F\n");
            else
                printf("T\n");
        }
    }
    return 0;
}
