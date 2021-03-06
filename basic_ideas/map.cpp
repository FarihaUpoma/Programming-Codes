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

map <string, int> mp;
map <string, int> :: iterator it;

char a[100];

int main()
{
    int n, k=1, i;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%s", a);
        if( mp[a]==0) mp[a]= k++;
    }
    for(it= mp.begin() ; it!= mp.end() ; it++) {
        if(strcmp(*it.first(), "hello")==0) printf("hoise!!!\n");
        std::cout << it->first << " => " << it->second << '\n';
    }
    printf("%d\n", strcmp("abc", "xy"));
    int x=0;
    printf("%d\n", ~x);
    return 0;
}
