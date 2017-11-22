#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int color[105],parent[105],d[105],f[105],time;
vector <int> graph[105];

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
            cout<<u<<"->"<<v<<" : tree edge"<<endl;
            dfs_visit(v);
        }
        else if(color[v]==2)
            cout<<u<<"->"<<v<<" : back edge"<<endl;

        else if(color[v]==3)
        {
            if(d[u]<d[v])
                cout<<u<<"->"<<v<<" : forward edge"<<endl;

            else if(d[u]>d[v])
                cout<<u<<"->"<<v<<" : cross edge"<<endl;
        }

    }

    color[u]=3;
    time=time+1;
    f[u]=time;

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
    dfs(node,edge);

    for(int i=0;i<node;i++)
    {
        cout<<"Discovery time of "<<i<<" is "<<d[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<node;i++)
    {
        cout<<"Finishing time of "<<i<<" is "<<f[i]<<endl;
    }

    return 0;
}

