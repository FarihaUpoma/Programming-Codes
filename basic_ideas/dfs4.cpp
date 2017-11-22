#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int color[105];
vector <int> graph[105];

bool dfs(int u)
{
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(color[v]==-1)
        {
            color[v]=1-color[u];
            cout<<color[v]<<endl;
            dfs(v);
        }
        else if(color[v]==color[u])
            return false;
    }
    return true;
}

int main()
{

    int node,edge;
    cin>>node>>edge;

    for(int i=1;i<=edge;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<=node;i++)
        color[i]=-1;

    color[0]=1;

    if(dfs(0)==true)
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;


    return 0;
}

