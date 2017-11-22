#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;


int main()
{
    int a, n, i;
    vector < int > v;
    cin>>n;
    for(i=0 ; i<n ; i++)  {
        cin >> a;
        v.push_back(a);
    }
    sort( v.begin(), v.end());
    for(i=0 ; i<n ; i++)
        cout<< v[i] <<' ';
    return 0;
}
