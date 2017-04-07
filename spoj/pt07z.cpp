//Problem Link : http://www.spoj.com/problems/PT07Z/

**********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

long int m;
class graph
{
        long int v;
        list <long int> *adj;
        long int dfsut(long int v,bool vis[]);
        public :
        graph(long int v);
        void adde(long int v,long int w);
        void dfs(long int v);
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

long int graph :: dfsut(long int v,bool vis[])
{
    long int x=0,m1=-1,m2=-1;
    vis[v]=true;
    list <long int > :: iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(vis[*i]==false)
        {
        	x=dfsut(*i,vis);
            if(x>=m1)
             {
             	m2=m1;
             	m1=x;

             }
            else if(x>m2)
             m2=x;
        }
    }
    m=max(m,m1+m2+2);
   // cout<<v<<"V"<<m<<"M\n";
    return m1+1;
}

void graph :: dfs(long int v)
{
    long int i,a;
    bool *vis = new bool [this->v];
    for(i=0;i<(this->v);i++)
     vis[i]=false;
    a=dfsut(1,vis);
    //return a;
}

int main()
{
    long int n,i,u,v;
    scanf("%ld",&n);
    graph g(n+1);
    for(i=1;i<n;i++)
    {
        scanf("%ld%ld",&u,&v);
        g.adde(u,v);
    }
    g.dfs(1);
    printf("%ld",m);
    return 0;
}
