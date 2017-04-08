#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long int n,m,c[110],f[110],k[110][510],i,j,x;
    while(1)
    {
        scanf("%ld%ld",&m,&n);
        if(m==0&&n==0)
         break;
        for(i=0;i<n;i++)
        scanf("%ld%ld",&c[i],&f[i]);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0||j==0)
                  k[i][j]=0;
                else if(c[i-1]<=j)
                  k[i][j]=max(k[i-1][j],f[i-1]+k[i-1][j-c[i-1]]);
                else
                  k[i][j]=k[i-1][j];
            }
        }
        for(i=1;i<=m;i++)
        {
            if(k[n][m]==k[n][i])
            {
                x=i;
                break;
            }
        }
        printf("%ld %ld\n",x,k[n][m]);
    }
    return 0;
}
