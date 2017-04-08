//Problem Link : http://www.spoj.com/problems/FARIDA/

**************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    long long int n,a[10010],dp[10010],t,i,j;
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld",&n);
        if(n==0)
        printf("Case %lld: 0\n",j);
        else
        {
            for(i=0;i<n;i++)
            {
                scanf("%lld",&a[i]);
            }
            memset(dp,0,sizeof(dp));
            for(i=n-1;i>=0;i--)
            {
                dp[i]=max(dp[i+1],a[i]+dp[i+2]);
            }
           printf("Case %lld: %lld\n",j,dp[0]);
        }
        //t--;
    }
    return 0;
}
