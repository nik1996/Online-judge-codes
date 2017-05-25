//Problem URL : https://www.codechef.com/APRIL16/problems/CHBLLNS

***************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main()
{
    long long int t,a[3],k,i,r;
    scanf("%lld",&t);
    while(t--)
    {
        for(i=0;i<3;i++)
        scanf("%lld",&a[i]);
        scanf("%lld",&k);
        sort(a,a+3);
        if(k<=a[0])
          r=(3*k)-2;
        else if(k>a[0]&&k<=a[1])
        {
            r=a[0]+(2*k)-1;
        }
        else if(k>a[1])
        {
            r=a[0]+a[1]+k;
        }
        printf("%lld\n",r);
    }
    return 0;
}
