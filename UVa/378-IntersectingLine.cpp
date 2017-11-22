#include <stdio.h>
#include <math.h>

double A1, A2, B1, B2, C1, C2, d;
int w,x,y,z;

struct point
{
    double x, y;
};

struct line
{
    point p1, p2;
};


bool ifIntersect( line l1, line l2)
{
    A1= l1.p1.y-l1.p2.y;
    B1= l1.p2.x- l1.p1.x;
    C1= l1.p1.x*A1+ l1.p1.y*B1;
    A2= l2.p1.y-l2.p2.y;
    B2= l2.p2.x- l2.p1.x;
    C2= l2.p1.x*A2 + l2.p1.y*B2;
    w=A1, x=A2, y=B1, z=B2;
    if( (w==0 && x==0) || (y==0 && z==0) ) return false;
    else return true;
}
point interPoint( line l1, line l2)
{
    point p;
    d= A1*B2-A2*B1;
    p.x= (B2*C1-B1*C2)/d;
    p.y= (A1*C2-A2*C1)/d;

    return p;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    double A, B, C;
    int f, g, t, i;
    line l1, l2;
    point p;
    scanf("%d", &t);
    printf("INTERSECTING LINES OUTPUT\n");
    for(i=0 ; i<t ; i++) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &l1.p1.x, &l1.p1.y, &l1.p2.x, &l1.p2.y, &l2.p1.x, &l2.p1.y, &l2.p2.x, &l2.p2.y);
        f=0;g=0;

        A= l1.p1.y-l1.p2.y;
        B= l1.p2.x-l1.p1.x;
        C= l1.p1.x*A + l1.p1.y*B;
        if( l2.p1.x*A + l2.p1.y*B == C) f=1;
        if(l2.p2.x*A + l2.p2.y*B == C) g=1;

        if(f==1 && g==1) printf("LINE\n");
        else {
            if(ifIntersect(l1, l2)) {
                p= interPoint(l1,l2);
                printf("POINT %.2lf %.2lf\n", p.x, p.y);
            }
            else printf("NONE\n");
        }
        if(i==t-1) printf("END OF OUTPUT\n");
    }
}
