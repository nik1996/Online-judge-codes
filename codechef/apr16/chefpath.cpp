//Problem URL : https://www.codechef.com/APRIL16/problems/CHEFPATH

**************************************************************************************************************************************

#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    long long int t,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        if(n==1||m==1)
         {
             if(n==1&&m!=2)
             printf("No\n");
             else if(m==1&&n!=2)
             printf("No\n");
             else if((n==1&&m==2)||(n==2&&m==1))
             printf("Yes\n");
         }
        else if(n%2==1&&m%2==1)
         printf("No\n");
        else if(n%2==0||m%2==0)
         printf("Yes\n");
    }
    return 0;
}
