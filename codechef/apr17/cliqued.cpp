//Problem URL : https://www.codechef.com/APRIL17/problems/CLIQUED

*************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#define pb push_back
#define mp make_pair
#define INF 1000000000000000
 
using namespace std;
 
vector <pair <int,int> > adj[100010];
long long int dist[100010];
 
void solve(int n,int k,int s,int x)
{
	set <pair<long long int,int> > q;
	q.insert(mp(0,s));
	dist[s]=0;
	int u,v,i,ele=-1;
	long long int w,m=INF;
	//if(s<=k)
	 //ele=s,m=0;
	pair <long long int,int> tmp;
	while(!q.empty())
	{
		tmp=*(q.begin());
		q.erase(q.begin());
		u=tmp.second;
		for(i=0;i<adj[u].size();i++)
		{
			tmp=adj[u][i];
			v=tmp.first;
			w=tmp.second;
			if(dist[v]>dist[u]+w)
			{
				if(dist[v]!=INF)
				 q.erase(q.find(mp(dist[v],v)));
				dist[v]=dist[u]+w;
				if(v<=k)
				 {
				 	//m=min(m,dist[v]);
				 	if(m>dist[v])
				 	{
				 		m=dist[v];
				 		ele=v;
				 	}
				 }
				q.insert(mp(dist[v],v));
			}
		}
		if(u==s&&s<=k)
		{
			for(i=1;i<=k;i++)
			{
				if(i==u)
				 continue;
				else
				 q.insert(mp(dist[i],i));
			}
		}
		else if(u==ele)
		{
			//cout<<u<<"U\n";
			for(i=1;i<=k;i++)
			{
				if(i==u)
				 continue;
				if(dist[i]>dist[u]+x)
				{
					if(dist[i]!=INF)
				      q.erase(q.find(mp(dist[i],i)));
				    dist[i]=dist[u]+x;
				    q.insert(mp(dist[i],i));
				}
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,k,x,m,s,a,b,c,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>x>>m>>s;
		if(s<=k)
		{
			for(i=1;i<=k;i++)
			{
				adj[i].clear();
				if(i==s)
				 continue;
				else
				 dist[i]=x;
			}
			for(i=k+1;i<=n;i++)
			{
				adj[i].clear();
			    dist[i]=INF;
			}
		}
		else
		{
			for(i=1;i<=n;i++)
		    {
			  adj[i].clear();
			  dist[i]=INF;
		    }
		}
		for(i=1;i<=m;i++)
		{
			cin>>a>>b>>c;
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		solve(n,k,s,x);
		for(i=1;i<=n;i++)
		 cout<<dist[i]<<" ";
		cout<<"\n";
	}
	return 0;
} 
