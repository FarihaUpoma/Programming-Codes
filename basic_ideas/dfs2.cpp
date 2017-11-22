#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int color[105],parent[105],d[105],f[105],time;
bool cycle;
vector <int> graph[105];
list <int> topSort;
list <int> :: iterator it;

void dfs_visit(int u)
{
    color[u]=2;
    time=time+1;
    d[u]=time;


    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if( color[v]==1 )
        {
            dfs_visit(v);
        }
        else if(color[v]==2)
            cycle=true;
    }

    color[u]=3;
    time=time+1;
    f[u]=time;
    topSort.push_front(u);
}

void dfs(int n,int e)
{
    for(int i=0;i<=n;i++)
        color[i]=1;

    time=0;

    for(int i=0;i<n;i++)
    {
        if(color[i]==1)
            dfs_visit(i);
    }
}

int main()
{
    int node,edge;

    freopen("in.txt","r",stdin);

    cin>>node>>edge;

    for(int i=1;i<=edge;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    cycle=false;

    dfs(node,edge);

    if(cycle==false)
    {
        for(it=topSort.begin();it!=topSort.end();it++)
            cout<<(*it)<<" ";

         cout<<endl;
    }
    else
        cout<<"A cycle exists in the graph"<<endl;


    return 0;
}


