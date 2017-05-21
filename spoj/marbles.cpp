//Problem URL: http://www.spoj.com/problems/MARBLES/

*********************************************************************************************************************************

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int t,n,k,r,i;
    scanf("%lld",&t);
    while(t--)
    {
        r=1;
        scanf("%lld%lld",&n,&k);
        if(k>(n-k+1))
         k=n-k+1;
        for(i=1;i<k;i++)
        {
            r*=(n-i);
            r/=i;
        }
        printf("%lld\n",r);
    }
    return 0;
}
