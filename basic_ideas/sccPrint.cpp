#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector <int> graph[105],grapht[105],graphw[105],scc_dfs,component[105];
list <int> list1;
int visit[105],scc_vis[105],visitT[105],g[105][105],check[105];
int node,edge,counter,count,a1,ch;
char a;
int check2[105][105];

void dfs_visit(int u)
{
    visit[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visit[v])
            dfs_visit(v);
    }

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
    component[a1].push_back(u);
    check[u]=ch;
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
    a='A';
    ch=1;

    for(int i=node-1;i>=0;i--)
    {
        a1=a;

        if(!visitT[scc_dfs[i]])
        {
            counter++;
            scc_visit(scc_dfs[i]);
            a++;
            ch++;
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

        g[a][b]=1;
    }

    dfs();

    scc();
    cout<<"The components are: "<<endl;
    for(int i=1;i<=counter;i++)
    {
        printf("%c -> ",i+'A'-1);
        for(int j=0;j<component[i+'A'-1].size();j++)
            cout<<" "<<component[i+'A'-1][j];
        cout<<endl;
    }

    char a1,b1;
    int p;

      for(int i=1;i<=node;i++)
      {

         for(int j=1;j<=node;j++)
         {
             if(i==j)
                continue;

             if(g[i][j])
             {
                 if(check[i]==check[j])
                 continue;
                 else
                 {
                    for(int k=1;k<=counter;k++)
                    {
                        for(int l=0;l<component[k+'A'-1].size();l++)
                        {
                            if(component[k+'A'-1][l]==i)
                                a1=k+'A'-1;
                            else if(component[k+'A'-1][l]==j)
                                b1=k+'A'-1;
                        }
                    }
                 }
             }

         }

         if(!check2[a1][b1])
         {
             cout <<a1<<" -> "<<b1<<endl;
            check2[a1][b1]=1;
         }

      }



    return 0;
}

