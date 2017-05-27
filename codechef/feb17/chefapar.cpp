//Problem URL : https://www.codechef.com/FEB17/problems/CHEFAPAR

************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int a[100010];
 
int main() {
	// your code goes here
	int t,n,i,j,c1,c2;
	long long int ans;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		 cin>>a[i];
		ans=c1=c2=0;
		i=0;
		while(i<n)
		{
			if(a[i]==0)
			 break;
			else
			 i++;
		}
		//cout<<i<<"I\n";
		for(j=i;j<n;j++)
		{
			if(a[j]==0)
			 {
			 	c1++;
			 	c2++;
			 }
			else
			{
				c1++;
			}
		}
		//cout<<c1<<"C1 "<<c2<<"C2\n";
		ans=ans+(c1*100);
		ans=ans+(c2*1000);
		cout<<ans<<"\n";
	}
	return 0;
}
