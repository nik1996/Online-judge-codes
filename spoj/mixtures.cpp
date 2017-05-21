//Problem URL : http://www.spoj.com/problems/MIXTURES/

**********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

long int a[110],s[110][110],dp[110][110];
long int ma(long int i,long int j)
{
    if(j<=i)
    return 0;
    if(j==i+1)
    return a[i]*a[j];
    long int m=INT_MAX,k,c;
    if(dp[i][j]==0)
    {
        for(k=i;k<j;k++)
        {
            if(dp[i][k]==0)
            dp[i][k]=ma(i,k);
            if(!dp[k+1][j])
            dp[k+1][j]=ma(k+1,j);
            c=dp[i][k]+dp[k+1][j]+(s[i][k]*s[k+1][j]);
            if(c<m)
            m=c;
        }
        dp[i][j]=m;
    }
    return dp[i][j];
}
int main()
{
    long int n,i,x,j;
    //scanf("%ld",&t);
    while(scanf("%ld",&n)>0)
    {
        for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            s[i][i]=a[i]%100;
            for(j=i+1;j<n;j++)
            {
                s[i][j]=((s[i][j-1]%100)+(a[j]%100))%100;
                //cout<<s[i][j];
            }
        }
        x=ma(0,n-1);
        printf("%ld\n",x);
    }
    return 0;
}
