#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

long long int a[2005],dp[2005][2005];
long long int ans(long long int b,long long int e,long long int n)
{
    long long int y;
    if(b>e)
     return 0;
    if(dp[b][e]!=-1)
     return dp[b][e];
    y=n-(e-b);
    dp[b][e]=max(ans(b+1,e,n)+y*a[b],ans(b,e-1,n)+y*a[e]);
    return dp[b][e];
}
int main()
{
    long long int n,i,x;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
     scanf("%lld",&a[i]);
     memset(dp,-1,sizeof(long long int)*2005*2005);
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
          v[i][j]=a[i]*j;
    }*/
    x=ans(1,n,n);
    printf("%lld\n",x);
    return 0;
}
