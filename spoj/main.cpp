#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

long long int dp[6110][6110];
int main()
{
    long long int t,n,i,j;
    string s;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>s;
        n=s.length();
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            dp[i][j]=INT_MAX;
        }
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<n;j++)
            {
                if(i>=j)
                dp[i][j]=0;
                else if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
                else if(s[i]!=s[j])
                dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
            }
        }
        printf("%lld\n",dp[0][n-1]);
    }
    return 0;
}
