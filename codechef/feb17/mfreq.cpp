//Problem URL : https://www.codechef.com/FEB17/problems/MFREQ

************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int a[100010],len[100010];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,l,r,i,j,c,mc,ans,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	len[n]=1;
	for(i=n-1;i>=1;i--)
	{
		if(a[i]==a[i+1])
		 len[i]=len[i+1]+1;
		else
		 len[i]=1;
	}
	while(m--)
	{
		cin>>l>>r>>k;
		ans=-1;
		for(i=l;i<=r-k+1;i++)
		{
			if(len[i]-len[i+k-1]+1>=k)
			{
				ans=a[i];
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
