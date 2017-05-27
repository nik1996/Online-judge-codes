//Problem URL : https://www.codechef.com/JAN17/problems/RESERVOI

********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
using namespace std;
 
string s[1001];
int n,m;
 
int chk1(int i,int j)
{
	if(j-1>=0)
	{
		if(s[i][j-1]=='A')
		 return 1;
	}
	if(j+1<m)
	{
		if(s[i][j+1]=='A')
		 return 1;
	}
	if(i+1<n)
	{
		if(s[i+1][j]=='A')
		 return 1;
	}
	if(j-1<0||j>=m||i+1>=n)
	 return 1;
	return 0;
}
 
int chk2(int i,int j)
{
	if(i+1<n)
	{
		if(s[i+1][j]=='A')
		 return 1;
	}
	return 0;
}
 
int main() {
	int t,i,j,fl,x;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		fl=0;
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='W')
				{
					x=chk1(i,j);
					if(x)
					{
						fl=1;
						cout<<"no\n";
						break;
					}
				}
				else if(s[i][j]=='B')
				{
					x=chk2(i,j);
					if(x)
					{
						fl=1;
						cout<<"no\n";
						break;
					}
				}
			}
			if(fl==1)
			 break;
		}
		if(fl==0)
		 cout<<"yes\n";
	}
	return 0;
} 
