#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define eps 1e-10
#define PI acos(-1)
#define pb push_back
#define mem(a, n) memset(a, n, sizeof(a))
#define input freopen("input.txt", "r", stdin)
#define done printf("done\n")

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

int min(int x, int y)
{
    if( x<y) return x;
    else return y;
}

int max(int x, int y)
{
    if( x>y) return x;
    else return y;
}

/*int bestEnd[100], a[100], n;

int lis()
{
    int i, k=0;
    bestEnd[0] = 99999;
    for(i=0 ; i<n ; i++) {
        if( a[i] > bestEnd[k])
            k++;
        bestEnd[k] = a[i];
    }
    return k;
}*/

int binary_search(int c[], int sz, int v)
{
    int lo, hi, mid;
    lo=1;
    hi=sz;
    while(lo<hi) {
        mid = (lo+hi)/2;
        if( v < c[mid] && v > c[mid-1]) break;
        else if( v > c[mid] ) {
            lo = mid+1;
        }
        else if( v < c[mid]) {
            hi = mid;
        }
    }
    return mid;
}

int sz, c[100], dp[100], array[100], n;
void lis()
{
    sz = 1;
    c[1] = array[0]; /*at this point, the minimum value of the last element of the size 1 increasing sequence must be array[0]*/
    dp[0] = 1;
    for( int i = 1; i < n; i++ ) {
        //done;
       if( array[i] < c[1] ) {
          c[1] = array[i]; /*you have to update the minimum value right now*/
          dp[i] = 1;
       }
       else if( array[i] > c[sz] ) {
          c[sz+1] = array[i];
          dp[i] = sz+1;
          sz++;
       }
       else {
          int k = binary_search( c, sz, array[i] ); /*you want to find k so that c[k-1]<array[i]<c[k]*/
          done;
          c[k] = array[i];
          dp[i] = k;
       }
    }
}

int main()
{
    input;

    int i, x;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) {
        scanf("%d", &array[i]);
    }
    lis();
    for(i=0 ; i<=sz ; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}
