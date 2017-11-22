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

int a[100], b[100];

void merge(int lo, int mid, int hi)
{
    int h, i, j, k;
    h = lo;
    i = lo;
    j = mid+1;
    while(h<=mid && j<=hi) {
        if( a[h] <= a[j] ) {
            b[i] = a[h];
            h++;
        }
        else {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if(h>mid) {
        for(k=j ; k<=hi ; k++) {
            b[i] = a[k];
            i++;
        }
    }
    else {
        for(k=h ; k<=mid ; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for(k=lo ; k<=hi ; k++)
        a[k] = b[k];
}

int mid;

void merge_sort(int low, int hi)
{
    if(low<hi) {
        printf("a: ");for(int k=low ; k<=hi ; k++) printf("%d ", a[k]);printf("\n");
        mid = (low+hi)/2;
        merge_sort(low, mid);
        merge_sort(mid+1, hi);

        merge(low, mid, hi);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);
    merge_sort(0, n-1);
    for(i=0 ; i<n ; i++)
        printf("%d ", a[i]);
    return 0;
}
