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

void insertion_sort(int a[], int n)
{
    int i, value, hole;
    for(i=1 ; i<n ; i++) {
        value = a[i];
        hole = i;
        while(hole>0 && a[hole-1] > value) {
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole] = value;
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) {
        scanf("%d", &a[i]);
    }
    insertion_sort(a, n);
    for(i=0 ; i<n ; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
