#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

double a, b, w[1000009][10];

bool ifInR( double x1, double y1, double x3, double y3, double a, double b)
{
    double x2= x1, y2= y3, x4= x3, y4= y1;
    if( (a>x1 && a<x3) && (b>y2 && b<y4)) return true;
    return false;
}

bool ifInC(double x, double y, double r, double a, double b)
{
    double R=(a-x)*(a-x)+(b-y)*(b-y);
    if(R< r*r) return true;
    return false;
}

double cross(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double d= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return d*0.5;
}

bool ifInT(double x1, double y1, double x2, double y2, double x3, double y3, double a, double b)
{
    double d1, d2, d3, d;
    d1= fabs(cross(x1,y1,x2,y2,a,b));
    d2= fabs(cross(x2,y2,x3,y3,a,b));
    d3= fabs(cross(x3,y3,x1,y1,a,b));
    d=  fabs(cross(x1,y1,x2,y2,x3,y3));
    if( fabs( ( d1+d2+d3)-d)<eps) return true;
    return false;
}

char s[1000009];

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, k=0, f;
    char q;
    while(scanf("%c", &q))
    {
        if(q=='*') break;
        else {
            s[k]= q;
            if(q=='r') {
                scanf("%lf %lf %lf %lf", &w[k][0], &w[k][1], &w[k][2], &w[k][3]);
            }
            else if(q=='c') scanf("%lf %lf %lf", &w[k][0], &w[k][1], &w[k][2]);
            else if(q=='t') scanf("%lf %lf %lf %lf %lf %lf", &w[k][0], &w[k][1], &w[k][2], &w[k][3], &w[k][4], &w[k][5]);
            k++;
            getchar();
        }
    }
    //printf("k=%d\n", k);
    j=1;
    while(scanf("%lf %lf", &a, &b))
    {
        if(a==9999.9 & b==9999.9) break;
        else {
            for(f=0,i=0 ; i<k ; i++) {
                if(s[i]=='r') {
                    if(ifInR( w[i][0], w[i][1], w[i][2], w[i][3], a, b) ) {
                        printf("Point %d is contained in figure %d\n", j, i+1);
                        f=1;
                    }
                }
                else if(s[i]=='c') {
                    if( ifInC( w[i][0], w[i][1], w[i][2], a, b)) {
                        printf("Point %d is contained in figure %d\n", j, i+1);
                        f=1;
                    }
                }
                else if(s[i]=='t') {
                    if( ifInT(w[i][0], w[i][1],w[i][2],w[i][3],w[i][4],w[i][5],a, b) ) {
                        printf("Point %d is contained in figure %d\n", j, i+1);
                        f=1;
                    }
                }
            }
            if(f==0) printf("Point %d is not contained in any figure\n", j);
            j++;
        }
    }
    return 0;
}
