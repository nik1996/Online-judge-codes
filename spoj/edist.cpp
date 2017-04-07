//Problem Code : http://www.spoj.com/problems/EDIST/

*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int dp[2005][2005];
int mi(int x,int y,int z)
{
    return min(x,min(y,z));
}
int main()
{
    int t,i,j,m,n;
    string a,b;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b;
        m=a.size();
        n=b.size();
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0)
                 dp[i][j]=j;
                else if (j==0)
                 dp[i][j]=i;
                else if(a[i-1]==b[j-1])
                 dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+mi(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
