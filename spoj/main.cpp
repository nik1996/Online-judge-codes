#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

class graph
{
        long int v;
        list <long int> *adj;
        bool cyut(long int v,bool vis[],int c,int col[]);
        public :
        graph(long int v);
        void cl();
        void adde(long int v,long int w);
        bool isbi();
};

graph :: graph(long int v)
{
        this->v=v;
        adj= new list <long int> [v];
}

void graph :: adde(long int v,long int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void graph :: cl()
{
    long int i;
    for(i=1;i<v;i++)
     adj[i].clear();
}

bool graph :: cyut(long int v,bool vis[],int c,int col[])
{
    vis[v]=true;
    col[v]=c;
    list <long int> :: iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(vis[*i]==false)
        {
            if(cyut(*i,vis,1-col[v],col)==false)
             return false;
        }
        else if(col[v]==col[*i])
         return false;
    }
    return true;
}

bool graph :: isbi()
{
    bool *vis = new bool [this->v];
    int col[v];
    long int i;
    for(i=1;i<(this->v);i++)
      {
          vis[i]=false;
          col[i]=-1;
      }
    for(i=1;i<(this->v);i++)
    {
        if(vis[i]==false)
        {
            if(cyut(i,vis,0,col)==false)
            return false;
         }
    }
    return true;
}
int main()
{
    long int t,n,m,i,j,u,v;
    scanf("%ld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%ld%ld",&n,&m);
        graph g(n+1);
        g.cl();
        for(i=1;i<=m;i++)
        {
            scanf("%ld%ld",&u,&v);
            g.adde(u,v);
        }
        if(g.isbi())
        {
            printf("Scenario #%ld:\nNo suspicious bugs found!\n",j);
        }
        else
        {
            printf("Scenario #%ld:\nSuspicious bugs found!\n",j);
        }
    }
    return 0;
}
