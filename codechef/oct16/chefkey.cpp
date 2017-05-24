//Problem URL : https://www.codechef.com/OCT16/problems/CHEFKEY

****************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main() {
	int i,n,m,c,t,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d%d",&n,&m,&c);
		for(i=max(c/m,1);i<=n;i++)
		{
			if((c/i)<=m&&c%i==0)
			 ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
