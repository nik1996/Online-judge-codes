//Problem Link : http://www.spoj.com/problems/BYTESM2/

*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

long int a[105][105];
long long int dp[105][105],m;
long long int ma(long long int x,long long int y,long long int z)
{
    return max(x,max(y,z));
}
int main()
{
    long int t,h,w,i,j;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&h,&w);
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
             scanf("%ld",&a[i][j]);
        }
        memset(dp,0,sizeof(long long int)*(h+1)*(w+1));
        m=a[1][1];
        for(i=1;i<=h;i++)
         dp[i][w+1]=0;
        //cout<<m<<"M\n";
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                //if(i==1&&j==1)
                 //dp[1][1]=a[1][1];
                if(i==1)
                 dp[i][j]=a[i][j];
                else if(j==1)
                 dp[i][j]=max(a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j+1]);
                else if(j==w)
                 dp[i][j]=max(a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j-1]);
                else
                 dp[i][j]=ma(a[i][j]+dp[i-1][j-1],a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j+1]);
                if(dp[i][j]>m)
                 m=dp[i][j];
                 //cout<<m<<"M\n";
            }
        }
        printf("%lld\n",m);
    }
    return 0;
}
