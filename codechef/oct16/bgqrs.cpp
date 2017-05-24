//Problem URL : https://www.codechef.com/OCT16/problems/BGQRS/

//This solution passes two subtasks.

****************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
long long int cnt(long long int p,int q)
{
	long long int c=0;
	while(p%q==0)
	{
		c++;
		p/=q;
	}
	return c;
}
 
int main() {
	int t,n,m,l,r,v,i;
	long long int a[100010],c2[100010],c5[100010],x,y,z,ans,x2,x5,c;
	scanf("%d",&t);
	while(t--)
	{
		memset(c2,0,sizeof(c2));
		memset(c5,0,sizeof(c5));
		scanf("%d%d",&n,&m);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			c2[i]=cnt(a[i],2);
			c5[i]=cnt(a[i],5);
		}
		while(m--)
		{
			scanf("%d",&v);
			if(v==1)
			{
				scanf("%d%d%lld",&l,&r,&x);
				x2=cnt(x,2);
				x5=cnt(x,5);
				for(i=l;i<=r;i++)
				{
					c2[i]+=x2;
					c5[i]+=x5;
				}
			}
			else if(v==2)
			{
				scanf("%d%d%lld",&l,&r,&x);
				x2=cnt(x,2);
				x5=cnt(x,5);
				c=1;
				for(i=l;i<=r;i++)
				{
					c2[i]=x2;
					c5[i]=x5;
					if(c%2==0)
					{
						c2[i]+=(cnt(c,2));
					}
					if(c%5==0)
					{
						c5[i]+=(cnt(c,5));
					}
					c++;
				}
			}
			else if(v==3)
			{
				y=z=0;
				scanf("%d%d",&l,&r);
				for(i=l;i<=r;i++)
				{
					y+=c2[i];
					z+=c5[i];
				}
				ans+=min(y,z);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}   
