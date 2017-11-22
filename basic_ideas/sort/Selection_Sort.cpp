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

int a[100];

void selection_sort(int a[], int n)
{
    int i, j, min, tmp;
    for(i=0 ; i<n ; i++) {
        min = i;
        for(j=i+1 ; j<n ; j++) {
            if( a[j] < a[min])
            min = j;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) {
        scanf("%d", &a[i]);
    }
    selection_sort(a, n);
    for(i=0 ; i<n ; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
