//Problem URL : https://www.codechef.com/OCT16/problems/CHEFTWOS/

//This solution passes only one subtask.

**********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
long long int m=1000000007;
int chk(string x,int l)
{
	int i=0;
	while(i!=l)
	{
		if(x[i]=='1')
		 i++;
		else if(x[i]=='2')
		{
			if(i==l-1)
			{
				i++;
				break;
			}
			else if(l<=3)
			 return 0;
			else if(i+1<l-1&&i+2<l-1)
			{
				if(x[i+1]=='2'&&x[i+2]=='1')
				 i=i+3;
				else break;
			}
			else
			 break;
		}
	}
	if(i!=l)
	 return 0;
	return 1;
}
 
int main() {
	int t,l,i,j,n,x,y;
	long long int c;
	string a,b,tmp1,tmp2;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		l=a.size();
		n=1<<l;
		if(l==1)
		{
			cout<<"2\n";
			continue;
		}
		c=0;
		x=chk(a,l);
		y=chk(b,l);
		if(x==1&&y==1)
		{
			if(l<=3)
			{
				cout<<pow(2,l)<<"\n";
			    continue;
			}
			else c=1;
		}
		for(j=1;j<n;j++)
		{
			tmp1=a;
			tmp2=b;
			for(i=0;i<l;i++)
			{
				if(j&(1<<i))
				swap(tmp1[i],tmp2[i]);
			}
			x=chk(tmp1,l);
		    y=chk(tmp2,l);
			if(x==1&&y==1)
			 {
			 	c=(c+1)%m;
			 }
		}
		cout<<c<<"\n";
	}
	return 0;
} 
