//Problem URL : https://www.codechef.com/FEB17/problems/CHEFYODA

//This will pass three subtasks.
**************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
 
using namespace std;
 
long double comb[1000010];
 
long double cal(int p,int k)
{
	long double ans=0.0L,mul=1.0L,f=2.0L;
	int i;
	for(i=1;i<=k;i++)
	{
		mul=(long double)mul/f;
	}
	comb[0]=comb[k]=mul;
	for(i=1;i<=k/2;i++)
	 {
	 	f=(long double)(k-i+1)/(long double)i;
	 	comb[i]=comb[i-1]*f;
	 	//cout<<comb[i]<<"C"<<i<<"I\n";
	 	comb[k-i]=comb[i];
	 }
	for(i=p;i<=k;i++)
	 ans=(long double)(ans+comb[i]);
	return ans;
}
 
int main() {
	int t,n,m,p,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&p,&k);
		if(n%2==0&&m%2==0||p==0)
		{
			printf("1.000000\n");
		}
		else if(n%2==1&&m%2==1)
		 printf("0.000000\n");
		else
		{
			printf("%.6llf\n",cal(p,k));
		}
	}
	return 0;
}  
