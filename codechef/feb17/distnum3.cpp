//Problem URL : https://www.codechef.com/FEB17/problems/DISTNUM3

//This will pass one subtask.

*************************************************************************************************************************************

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <unordered_set>
#define pb push_back
#define mp make_pair
 
using namespace std;
 
vector <int> adj[100010];
int a[100010];
bool vis[100010];
unordered_set <int> s;
 
bool dfs(int v,int tar)
{
	vis[v]=true;
	if(tar==v)
	 return true;
	int i,x;
	for(i=0;i<adj[v].size();i++)
	{
		x=adj[v][i];
		if(vis[x]==false)
		{
			if(dfs(x,tar)==true)
		    {
			   s.insert(a[x]);
			   return true;
		    }
		}
	}
	return false;
}
 
int solve(int u,int v,int n)
{
	bool x;
	int i,ans=0,val,j;
	for(i=1;i<=n;i++)
	 vis[i]=false;
	s.clear();
	s.insert(a[u]);
	x=dfs(u,v);
	return s.size();
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,q,i,x,u,v,y,n;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	while(q--)
	{
		cin>>x;
		if(x==1)
		{
			cin>>u>>v;
			//s.clear();
			cout<<solve(u,v,n)<<"\n";
		}
		else
		{
			cin>>v>>y;
			a[v]=y;
		}
	}
	return 0;
}   
