//Problem URL : https://www.codechef.com/FEB17/problems/INTERVAL

//This will pass one subtask and some test cases of other subtasks.
*************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
 
int a[300010],b[210],m;
long long int dp2[300010][210];
 
using namespace std;
 
long long int rec(int st,int e,int ind)
{
	if(ind==m+1)
	 return 0;
	if(dp2[st][ind]!=0)
	 return dp2[st][ind];
	int x,i,j;
	long long int ans,s,cs;
	 ans=0;
	x=b[ind];
	s=0;
	for(i=st;i<=st+x-1;i++)
	 s+=a[i];
	for(i=st+x;i<e;i++)
	{
		 s+=(a[i]-a[i-x]);
		 cs=s;
		if(ind<=m)
		{
			if(dp2[i-x+1][ind+1]==0)
		      dp2[i-x+1][ind+1]=rec(i-x+1,i,ind+1);
		    cs=s-dp2[i-x+1][ind+1];
		}
		if(cs>ans)
		 ans=cs;
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,i,j,n,x;
	long long int s,ans,cs;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		 cin>>a[i];
		for(i=1;i<=m;i++)
		 cin>>b[i];
		if(n==1)
		{
			cout<<a[1]<<"\n";
			continue;
		}
		x=b[1];
		b[m+1]=a[0]=0;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			 dp2[i][j]=0;
		}
		ans=s=0;
		for(i=1;i<=x-1;i++)
		 s+=a[i];
		for(i=x;i<=n;i++)
		{
			s+=(a[i]-a[i-x]);
			cs=s-rec(i-x+1,i,2);
			if(cs>ans)
			 ans=cs;
		}
		cout<<ans<<"\n";
	}
	return 0;
}    
