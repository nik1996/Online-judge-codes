//Problem URL : https://www.codechef.com/JAN17/problems/TOURISTS

**************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#define pb push_back
#define mp make_pair
 
using namespace std;
 
vector <pair<int,int> >edge;
vector <pair<int,int> > adj[100010];
int n,e,vis[200010],v1[100010],lp[100010];
 
void cal(int v)
{
	vector <pair<int,int> > :: iterator it=adj[v].begin();
	//vector <pair<int,int> > :: iterator iv;
	if(lp[v]>=adj[v].size())
	 return;
	it+=lp[v];
	int x,p;
	for(;it!=adj[v].end();++it)
	{
		x=it->first;
		if(x==-1)
		 continue;
		p=it->second;
		if(vis[p]==0)
		{
			v1[x]=v1[v]=1;
			edge[p].first=v;
			edge[p].second=x;
			vis[p]=1;
			it->first=-1;
			lp[v]=it-adj[v].begin()+1;
			cal(x);
		}
	}
}
 
void solve()
{
	int i,fl=0,s,j,x,y,a,b;
	memset(vis,0,sizeof(vis));
	memset(v1,0,sizeof(v1));
	memset(lp,0,sizeof(lp));
	for(i=1;i<=n;i++)
	{
		s=adj[i].size();
		if(s&1)
		{
			fl=1;
			break;
		}
	}
	if(fl==1)
	 printf("NO");
	else
	{
		cal(1);
		for(i=1;i<=n;i++)
		{
			if(v1[i]==0)
			{
				printf("NO\n");
				return;
			}
		}
		printf("YES\n");
		for(i=0;i<e;i++)
		{
			printf("%d %d\n",edge[i].first,edge[i].second);
		}
	}
}
 
int main() {
	int i,a,b;
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		edge.pb(mp(a,b));
		adj[a].pb(mp(b,i));
		adj[b].pb(mp(a,i));
	}
	solve();
	return 0;
}  
