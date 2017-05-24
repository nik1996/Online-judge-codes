//Problem URL : https://www.codechef.com/OCT16/problems/CHDOGS

****************************************************************************************************************************************

#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
	int s,v,t;
	double ans=0.0,c=(double)2/3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&s,&v);
		ans=(double)s/v;
		printf("%.7lf\n",ans*c);
	}
	return 0;
} 
