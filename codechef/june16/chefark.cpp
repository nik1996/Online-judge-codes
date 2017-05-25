//Problem URL : https://www.codechef.com/JUNE16/problems/CHEFARK

**********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
long long int p=1000000007;
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    long long int x1, y1; // To store results of recursive call
    long long int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
long long int modInverse(long long int a, long long int m)
{
    long long int x, y;
    long long int g = gcdExtended(a, m, &x, &y);
    //if (g != 1)
      //  cout << "Inverse doesn't exist";
    //else
    //{
        // m is added to handle negative x
        long long int res = (x%m + m) % m;
        //cout << "Modular multiplicative inverse is " << res;
    //}
    return res;
}
 
int main()
{
    int t,n,k,a[100010],i;
    long long int c,u,b[100010],x,y,z,s,l;
    scanf("%d",&t);
    while(t--)
    {
        c=s=0;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
          {
              scanf("%d",&a[i]);
              if(a[i]==0)
              c++;
          }
          u=n-c;
          b[0]=1;
          b[1]=u;
          for(i=2;i<=u;i++)
              {
                  x=(u-i+1);
                  y=modInverse(i,p);
                  z=(x*y)%p;
                  b[i]=(z*b[i-1])%p;
              }
              if(c==0)
              {
                  if(k>=n)
                  {
                     if(k&1)
                     {
                       if(n&1)
                       l=n;
                       else
                       l=n-1;
                       for(i=1;i<=l;i=i+2)
                       {
                           s=(s+b[i])%p;
                       }
                     }
                     else
                     {
                       if(n&1)
                       l=n-1;
                       else
                       l=n;
                       for(i=0;i<=l;i=i+2)
                       {
                           s=(s+b[i])%p;
                       }
                     }
                   }
                   else
                   {
                       if(k&1)
                       {
                           for(i=1;i<=k;i=i+2)
                           {
                               s=(s+b[i])%p;
                           }
                       }
                       else
                       {
                           for(i=0;i<=k;i=i+2)
                           {
                               s=(s+b[i]%p);
                           }
                       }
                   }
               }
               else
               {
                   //if(k>=u)
                   {
                       for(i=0;i<=u;i++)
                       {
                           s=(s+b[i])%p;
                       }
                   }
                   /*else
                   {
                       for(i=0;i<=k;i++)
                       {
                           s=(s+b[i])%p;
                       }
                   }*/
               }
               printf("%lld\n",s%p);
        //}
    }
    return 0;
}
