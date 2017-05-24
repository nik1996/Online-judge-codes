//Problem URL : https://www.codechef.com/OCT16/problems/FENWITER

************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
string s1,s2,s3,tmp;
int n,l1,l2,l3;
 
int conv()
{
	int i;
	for(i=l3-1;i>=0;i--)
	{
		if(s3[i]=='1')
		 s3[i]='0';
		else if(s3[i]=='0')
		{
			s3[i]='1';
			return 0;
		}
	}
	for(i=l2-1;i>=0;i--)
	{
		if(tmp[i]=='1')
		 tmp[i]='0';
		else if(tmp[i]=='0')
		{
			tmp[i]='1';
			return 0;
		}
	}
	for(i=l1-1;i>=0;i--)
	{
		if(s1[i]=='1')
		 s1[i]='0';
		else if(s1[i]=='0')
		{
			s1[i]='1';
			return 2;
		}
	}
    return 1;
}
 
int cal(int x)
{
	int c,v,y,i;
	c=v=y=0;
	for(i=l1-1;i>=0;i--)
	{
		if(s1[i]=='1')
		 c++;
	}
	for(i=l2-1;i>=0;i--)
	{
		if(tmp[i]=='1')
		 y++;
	}
	for(i=l2-1;i>=0;i--)
	{
		if(s2[i]=='1')
		 v++;
	}
	if(x==0)
	c+=((n-1)*v+y);
	else if(x==2)
	c+=(n*y);
	for(i=l3-1;i>=0;i--)
	{
		if(s3[i]=='1')
		 c++;
	}
	return c;
}
 
int main() {
	int t,f;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2>>s3>>n;
		l1=s1.size();
	    l2=s2.size();
	    l3=s3.size();
		tmp=s2;
		f=conv();
		if(f==1)
		cout<<"1\n";
		else
		{
			cout<<cal(f)<<"\n";
		}
	}
	return 0;
}
