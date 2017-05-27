//Problem URL : https://www.codechef.com/FEB17/problems/MAKETRI

*******************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
 
using namespace std;
 
long long int a[1000010],l,r;
vector <pair <long long int,long long int> > v;
 
bool comp(pair <long long int,long long int> a,pair <long long int,long long int> b)
{
	if(a.first==b.first)
	{
		return a.second<b.second;
	}
	return a.first<b.first;
}
 
void solve(int n)
{
	sort(a,a+n);
	int i,len,x;
	long long int d1,d2,c=0,p;
	for(i=0;i<n-1;i++)
	{
		d1=a[i+1]-a[i]+1;
		d2=a[i+1]+a[i]-1;
		v.pb(mp(d1,d2));
	}
	sort(v.begin(),v.end(),comp);
	p=l;
	len=v.size();
	if(r<v[0].first)
	{
		printf("0\n");
		return;
	}
	i=0;
	while(v[i].second<l&&i<len)
	 i++;
	if(i==len)
	{
		printf("0\n");
		return;
	}
	while(i<len)
	{
		d1=v[i].first;
		d2=v[i].second;
		if(d1>r)
		 break;
		if(p>=d2)
		 {
		 	i++;
		 	continue;
		 }
		d1=max(p,d1);
		d2=min(r,d2);
		c+=(d2-d1);
		if(p<d1||p==l)
		 c++;
		p=d2;
		if(p>=r)
		 break;
		i++;
	}
	printf("%lld\n",c);
}
 
int main() {
	int n,i;
	scanf("%d%lld%lld",&n,&l,&r);
	for(i=0;i<n;i++)
	 scanf("%lld",&a[i]);
	solve(n);
	return 0;
}  
