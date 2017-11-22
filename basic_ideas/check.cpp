#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>
using namespace std;
long long get(long long a)
{
    long long s=1,d;
    for(d=1;;d++)
    {
        if(s*2==a) return d;
        if(s*2>a) return d-1;
        s=s*2;
    }
}
long long power(long long a)
{
    long long s,d,f,g;
    s=1;
    for(d=1;d<=a;d++) s=s*2;
    return s;
}
long long check(long long a)
{
    long long s,d,f,g,h,j,k,l;
    if(a==0) return 0;
    if(a==1) return 1;
    if(a==2) return 3;
    if(a==3) return 4;
    s=get(a);
    f=0;
    l=0;
    for(d=s;d>=0;d--)
    {
        g=power(d);
        h=a/g;
        j=h-f;
        f=h;
        l=l+g*j;
    }
    return l;
}
int main()
{
    long long a,s,d,f,g,h,j,k,l;
    //for(a=0;a<=20;a++) cout<<a<<" "<<get(a)<<" "<<power(a)<<endl;
    cin>>a>>s;
    cout<<check(s)-check(a-1)<<endl;
}
