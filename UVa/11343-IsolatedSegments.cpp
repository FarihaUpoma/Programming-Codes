#include <stdio.h>

#define eps 1e-10

int a[100][10];

double cross(int x1,int y1,int x2,int y2,int x3, int y3)
{
    double d;
    d= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return d;
}

bool ifIntersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    double d1, d2, d3, d4;
    int f=0,g=0;
    if((x1==x3 && y1==y3) || (x1==x4 && y1==y4) || (x2==x3 && y2==y3) || (x2==x4 && y2==y4)) f=1;
    if((x2>=x3 && x2<=x4 && y2>=y3 && y2<=y4) || (x4>=x1&& x4<=x2 && y4>=y1&& y4<=y2) || (x1>=x3 && x1<=x4 && y1>=y3 && y1<=y4) || (x3>=x1&& x3<=x2 && y3>=y1&& y3<=y2)) g=1;
    d1= cross(x1,y1,x2,y2,x3,y3);
    d2=cross(x1,y1,x2,y2,x4,y4);
    d3=cross(x3,y3,x4,y4,x1,y1);
    d4= cross(x3,y3,x4,y4,x2,y2);

    if(f==1 || g==1) return true;
    else if(d1<eps && d2<eps && d3<eps && d4<eps && f==0 && g==0) return false;
    else if( d1*d2< eps && d3*d4<eps) return true;
    else return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t, i, n, j, k, count;
    scanf("%d", &t);
    for(i=0 ; i<t;  i++) {
        scanf("%d", &n);
        for(j=0 ; j<n ; j++) {
            a[j][0]=1;
            scanf("%d %d %d %d", &a[j][1],&a[j][2],&a[j][3],&a[j][4]);
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
            if( a[j][0]==1) count++;
        }
        printf("%d\n", count);
    }
}
