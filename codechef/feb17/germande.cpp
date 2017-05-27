//Problem URL : https://www.codechef.com/FEB17/problems/GERMANDE

**************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
int a[2000010];
vector <int> v;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,o1,o2,i,j,c,st,ans,p,ind;
	cin>>t;
	while(t--)
	{
		v.clear();
		cin>>o1>>o2;
		n=o1*o2;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i+n]=a[i];
		}
		ans=st=0;
		for(i=1;i<=n;i+=o2)
		{
			c=0;
			for(j=i;j<i+o2;j++)
			{
				if(a[j]==1)
		    	 c++;
			}
			v.pb(c);
			if(c>o2/2)
			 st++;
		}
		if(st>o1/2)
		{
			ans=1;
		}
		else
		{
			for(p=2;p<=o2;p++)
		    {
		    	ind=p;
		    	st=0;
		    	for(i=0;i<v.size();i++)
		    	{
		    		c=v[i]-a[ind-1]+a[ind+o2-1];
		    		ind+=o2;
		    		v[i]=c;
		    		if(v[i]>o2/2)
		    		 st++;
		    	}
		    	if(st>o1/2)
		    	{
		    		ans=1;
		    		break;
		    	}
		    }
		}
		cout<<ans<<"\n";
	}
	return 0;
}  
