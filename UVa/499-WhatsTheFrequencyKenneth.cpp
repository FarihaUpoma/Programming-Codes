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

int cap[30], sml[30];
char a[10000];

int main()
{
    int l, i, max1, max2;
    while(gets(a))
    {
        for(i=0 ; i<26 ; i++) cap[i]=0;
        for(i=0 ; i<26 ; i++) sml[i]=0;
        l= strlen(a);
        for(i=0 ; i<l; i++)
        {
            if( isalpha(a[i]))
            {
                if( a[i]>64 && a[i]<91 ) cap[ a[i]-65 ]++;
                else if( a[i]>96 && a[i]<123) sml[ a[i]-97 ]++;
            }
        }
        max1=0; max2=0;
        for(i=0 ; i<26 ; i++) {
            if( cap[i]>max1) max1= cap[i];
            if( sml[i]>max2) max2= sml[i];
        }
        if( max1==max2) {
            for(i=0 ; i<26 ; i++) {
                if( cap[i]==max1) printf("%c", i+65);
            }
            for(i=0 ; i<26 ; i++) {
                if( sml[i]==max2) printf("%c", i+97);
            }
            printf(" %d\n", max1);
        }
        else if(max2<max1) {
            for(i=0 ; i<26 ; i++) {
                if( cap[i]==max1) printf("%c", i+65);
            }
            printf(" %d\n", max1);
        }
        else {
            for(i=0 ; i<26 ; i++) {
                if( sml[i]==max2) printf("%c", i+97);
            }
            printf(" %d\n", max2);
        }
    }
    return 0;
}
