//Problem Link : http://www.spoj.com/problems/AGGRCOW/

***********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
int x[100010];
 
int solve(int n,int cows)
{
	int l,h,mid,c,i,j;
	l=x[0];
	h=x[n-1]-x[0]+1;
	while(l<h)
	{
		c=1;
		mid=l+(h-l)/2;
		if(l==mid)
		 break;
		i=0;
		j=1;
		while(j<n)
		{
			if(x[j]-x[i]>=mid)
			{
				c++;
				i=j;
				j++;
			}
			else
			 j++;
		}
		if(c>=cows)
		 {
		 	l=mid;
		 }
		else
		 h=mid;
	}
	return l;
}
 
int main() {
	int t,n,c,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		for(i=0;i<n;i++)
		 scanf("%d",&x[i]);
		sort(x,x+n);
		printf("%d\n",solve(n,c));
	}
	return 0;
} 
