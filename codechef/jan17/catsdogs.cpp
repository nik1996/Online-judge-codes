//Problem URL : https://www.codechef.com/JAN17/problems/CATSDOGS

************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int main() {
	long long int t,c,d,l;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&c,&d,&l);
		if(l%4!=0||l<4*d)
		 printf("no\n");
		else if(l%4==0)
		{
			l/=4;
			l-=d;
			c-=l;
			if(c>=0&&c<=2*d)
			 printf("yes\n");
			else
			 printf("no\n");
		}
	}
	return 0;
} 
