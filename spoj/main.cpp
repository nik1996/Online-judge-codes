#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int main()
{
    long long int t,e,f,n,p[510],w[510],x,i,j,k[10010];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&e,&f);
        x=f-e;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&p[i],&w[i]);
        }
        fill(k,k+10010,INT_MAX);
        for(i=1;i<=x;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==w[j])
                  k[i]=min(k[i],p[j]);
                else if(i>w[j]&&k[i-w[j]]!=INT_MAX)
                  k[i]=min(k[i],p[j]+k[i-w[j]]);
            }
        }
        if(k[x]!=INT_MAX)
         printf("The minimum amount of money in the piggy-bank is %lld.\n",k[x]);
        else
         printf("This is impossible.\n");
    }
    return 0;
}
