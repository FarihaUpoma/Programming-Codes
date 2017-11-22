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

int q, a[100];

int partition(int a[], int p, int r)
{
    int x, i, tmp, j;
    x = a[r];
    i = p-1;
    for(j=p ; j<r ; j++) {
        if( a[j] <= x) {
            i++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    tmp = a[r];
    a[r] = a[i+1];
    a[i+1] = tmp;
    return i+1;
}

void quicksort(int a[], int p, int r)
{
    if(p<r) {
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n-1);
    for(i=0 ; i<n ; i++)
        printf("%d ", a[i]);
    return 0;
}
