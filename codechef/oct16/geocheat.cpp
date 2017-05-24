//Problem URL : https://www.codechef.com/OCT16/problems/GEOCHEAT/

//This solution passes only one subtask.

*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
vector <int> v1,v2;
 
long long int dist()
{
	int i,j;
	long long int d1,d2,a,m=0;
	for(i=0;i<v1.size();i++)
	{
		for(j=i+1;j<v1.size();j++)
		{
			d1=labs(v1[i]-v1[j]);
			d2=labs(v2[i]-v2[j]);
			a=d1*d1+d2*d2;
			m=max(a,m);
		}
	}
	//cout<<m<<"\n";
	return m;
}
 
int main() {
	int n,x,y;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		v1.push_back(x);
		v2.push_back(y);
		if(v1.size()==1)
		printf("0\n");
		else
		printf("%lld\n",dist());
	}
	return 0;
} 
