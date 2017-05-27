//Problem URL : https://www.codechef.com/JAN17/problems/CAPIMOVE

***********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#define pb push_back
#define mp make_pair
 
using namespace std;
 
list <int> adj[500010];
int p[500010],ind[500010],par[500010];
vector <pair<int,int> > v;
 
void solve(int n)
{
	int i,j,x;
	memset(par,0,sizeof(par));
	list <int> :: iterator it;
	sort(v.begin(),v.end());
	for(i=0;i<n;i++)
	{
		x=v[i].second;
		ind[x]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			x=*it;
			par[ind[x]]=i;
		}
		j=n-1;
		while(j>=0)
		{
			if(par[j]!=i&&v[j].second!=i)
			{
				printf("%d ",v[j].second);
				break;
			}
			else
			 j--;
		}
	}
}
 
int main() {
	int t,n,i,x,y;
	scanf("%d",&t);
	while(t--)
	{
		v.clear();
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		 adj[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			v.pb(mp(p[i],i));
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		solve(n);
		printf("\n");
	}
	return 0;
} 
