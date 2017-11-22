#include <stdio.h>
#include <math.h>
#include <algorithm>

#define eps 1e-10

int a[100][100];

int max(int a, int b ) {
    if ( a > b ) return a;
    return b;
}

int min(int a, int b) {
    if ( a > b ) return b;
    return a;
}



bool onSegment(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if ( x2 <= max(x1,x3) && x2 >= min(x1,x3) && y2 <= max(y1, y3) && y2 >= min(y1, y3)) return true;
    return false;
}

int cross(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int d;
    d= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return abs(d);
}

bool ifInside(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int d1,d2,d3,d4;
    d1= cross(x1,y1,x2,y2,x4,y4);
    d2= cross(x2,y2,x3,y3,x4,y4);
    d3= cross(x3,y3,x1,y1,x4,y4);
    d4= cross(x1,y1,x2,y2,x3,y3);

    if(d4==0) return true;

    if(d1==0 &&  onSegment(x1,y1,x4,y4,x2,y2)) return true;

    if(d2==0 && onSegment(x2,y2,x4,y4,x3,y3)) return true;

    if(d3==0 && onSegment(x3,y3,x4,y4,x1,y1)) return true;

//printf("d1=%d d2=%d d3=%d d4=%d\n", d1,d2,d3,d4);
    if( abs(d1)+abs(d2)+abs(d3)!=abs(d4)) return false;
    else return true;

    /*if((d1*d2>0 && d2*d3>0) || d4==eps) return true;
    else return false;*/
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, j, k, p, x, y, z, f;
    int d,max, A;
    char q[100];
    while(scanf("%d", &n) && n)
    {
        for(i=0 ; i<n ; i++) {
            a[i][0]=1;
            scanf("%s %d %d",&q[i], &a[i][1],&a[i][2]);
        }
        max=0;
        for(i=0 ; i<n ;i++) {
            for(j=i+1 ;j<n; j++) {
                for(k=j+1 ; k<n ; k++) {
                    for(f=0,p=0 ; p<n ; p++) {
                        if(p==i || p==j || p==k) continue;
                        //printf("%d-%d %d-%d %d-%d\n", a[i][1],a[i][2],a[j][1],a[j][2],a[k][1],a[k][2]);
                        if(ifInside(a[i][1],a[i][2],a[j][1],a[j][2],a[k][1],a[k][2],a[p][1],a[p][2])) {
                            //printf("inside is  %d %d\n", a[p][1],a[p][2]);
                            f=1;
                            break;
                        }
                        //else printf("outside is %d %d\n\n", a[p][1],a[p][2]);
                    }
                    d= abs( a[i][1]*(a[j][2]-a[k][2])+a[j][1]*(a[k][2]-a[i][2])+a[k][1]*(a[i][2]-a[j][2]));
//printf("%c%c%c AREA=%d\n\n",i+65,j+65,k+65, d);
                    if(f==0 && d>max) {
                        //printf("%c%c%c AREA=%d\n\n",i+65,j+65,k+65, d);
                        x=i;
                        y=j;
                        z=k;
                        max=d;
                        A=d;
                    }
                }
            }
        }
        //printf("%d %d %d\n", x,y,z);
        printf("%c%c%c\n", x+65,y+65,z+65);
    }
    return 0;
}
