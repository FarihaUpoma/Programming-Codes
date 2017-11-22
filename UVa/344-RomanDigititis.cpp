#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int sp[105][10];

void rom()
{
    int ch, y, f, w, i;
    int a[5]= {1,5,10,50,100};
    for(ch=1 ; ch<101 ; ch++)
    {
        y=ch;
        while(1)
        {
            for(f=0,i=4 ; i>=0 ; i--) {
                if( y/10==9)
                {
                    sp[ch][4]++;
                    sp[ch][2]++;
                    y= y%10;
                    break;
                }
                /*if(y/10==5)
                {
                    sp[ch][4]++;
                    sp[ch][2]++;
                    y= y%10;
                    break;
                }*/
                if(y==9) {
                    sp[ch][ 0 ]++;
                    sp[ch][ 2 ]++;
                    f=1;
                    break;
                }
                w= y/a[i];
                y= y%a[i];

                if( w!= 0 ) {
                    if(w==4) {
                        sp[ch][ i ]++;
                        sp[ch][ i+1 ]++;
                    }
                    else if(w==9) {
                        sp[ch][ i ]++;
                        sp[ch][ i+2 ]++;
                    }
                    else
                        sp[ch][ i ]= sp[ch][ i ]+w;
                    break;
                }
            }
            if(y==0 || f==1) break;
        }
        //for(i=0 ; i<5 ; i++) printf("%d ", sp[ch][i]);
    }
}


int main()
{
    int x, sum1=0,sum2=0,sum3=0,sum4=0,sum5=0, i;
    rom();
    while(scanf("%d", &x) && x)
    {
        sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
        for(i=1 ; i<=x ; i++)
        {
            sum1= sp[i][0]+sum1;
            sum2=sp[i][1]+sum2;
            sum3=sp[i][2]+sum3;
            sum4=sp[i][3]+sum4;
            sum5=sp[i][4]+sum5;
        }

        printf("%d: %d i, %d v, %d x, %d l, %d c\n",x, sum1,sum2,sum3,sum4,sum5);

    }
    return 0;
}
