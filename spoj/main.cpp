#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t,n,r,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        r=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                r-=(r/i);
                while(n%i==0)
                n/=i;
            }
        }
        if(n>1)
        r-=(r/n);
        printf("%d\n",r);
    }
    return 0;
}
