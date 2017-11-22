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

map <char, char> mp;
map <char, char> :: iterator it;

char a[100000];

int main()
{
    int i, l;
    while(gets(a)!=NULL)
    {
        mp['W']= 'Q';mp['E']= 'W', mp['R']='E', mp['T']='R';mp['Y']='T';mp['U']='Y';mp['I']='U';mp['O']='I';mp['P']='O';mp['[']='P';mp[']']='[';mp['\\']=']';
        mp['S']='A';mp['D']='S';mp['F']='D';mp['G']='F';mp['H']='G';mp['J']='H';mp['K']='J';mp['L']='K';mp[';']='L';mp['\'']=';';
        mp['X']='Z';mp['C']='X';mp['V']='C';mp['B']='V';mp['N']='B';mp['M']='N';mp[',']='M';mp['.']=',';mp['/']='.';mp[' ']=' ';
        mp['1']='`';mp['2']='1';mp['3']='2';mp['4']='3';mp['5']='4';mp['6']='5';mp['7']='6';mp['8']='7';mp['9']='8';mp['0']='9';mp['-']='0';mp['=']='-';
        l= strlen(a);
        for(i=0 ; i<l ; i++)
            printf("%c", mp[a[i]]);
        printf("\n");
    }
    return 0;
}
