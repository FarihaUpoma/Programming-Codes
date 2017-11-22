#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector <int> graph[105],grapht[105],graphw[105],scc_dfs;
list <int> list1;
int visit[105],scc_vis[105],visitT[105];
int node,edge,counter,count;

void dfs_visit(int u)
{
    visit[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visit[v])
            dfs_visit(v);
    }

    //list1.push_front(u);
    scc_dfs.push_back(u);
}

void dfs()
{
    for(int i=1;i<=node;i++)
    {
        if(!visit[i])
            dfs_visit(i);
    }
}

void scc_visit(int u)
{
    visitT[u]=1;
    for(int i=0;i<grapht[u].size();i++)
    {
        int v=grapht[u][i];
        if(!visitT[v])
            scc_visit(v);
    }
}

void scc()
{
    for(int i=node-1;i>=0;i--)
    {
        if(!visitT[scc_dfs[i]])
        {
            counter++;
            scc_visit(scc_dfs[i]);
        }

    }
}

void wcc_visit(int u)
{
    visit[u]=1;
    for(int i=0;i<graphw[u].size();i++)
    {
        int v=graphw[u][i];
        if(!visit[v])
            wcc_visit(v);
    }

    //list1.push_front(u);
   // scc_dfs.push_back(u);
}



void wcc()
{
    for(int i=1;i<node;i++)
        visit[i]=0;

    for(int i=1;i<=node;i++)
    {
        if(!visit[i])
        {
            count++;
            wcc_visit(i);
        }
    }
}

int main()
{
    freopen("inScc.txt","r",stdin);

    cin>>node>>edge;
    for(int i=1;i<node;i++)
        visit[i]=0,visitT[i]=0;

    counter=0,count=0;

    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        grapht[b].push_back(a);

        graphw[a].push_back(b);
        graphw[b].push_back(a);
    }
    dfs();
    scc();
    if(counter==1)
        cout<< "Strongly Connected" <<endl;
    else
        cout<< "Not Strongly Connected" << endl;

    wcc();

    if(count==1)
        cout<< "Weakly Connected" <<endl;
    else
        cout<< "Not connected" <<endl;

    return 0;
}
