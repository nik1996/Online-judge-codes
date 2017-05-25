//Problem URL : https://www.codechef.com/APRIL16/problems/BIPIN3

*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
long long int po(long long int a,long long int b,long long int c)
{
    long long int r=1;
    a=a%c;
    while(b>0)
    {
        if(b&1)
         r=((r%c)*(a%c))%c;
        b>>=1;
        a=((a%c)*(a%c))%c;
    }
    return r;
}
int main()
{
    long long int t,n,k,a,b,c=1000000007,x,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        a=k-1;
        b=n-1;
        x=po(a,b,c);
        ans=((k%c)*(x%c))%c;
        printf("%lld\n",ans);
    }
    return 0;
}
