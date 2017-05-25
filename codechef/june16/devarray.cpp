//Problem URL : https://www.codechef.com/JUNE16/problems/DEVARRAY

*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <climits>
 
using namespace std;
 
int main()
{
    long n,q,x,y,a[100010],t,i;
    scanf("%ld%ld",&n,&q);
    x=0;
    y=INT_MAX;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(x<a[i])
         x=a[i];
        if(y>a[i])
         y=a[i];
    }
    while(q--)
    {
        scanf("%ld",&t);
        if((t>=y)&&(t<=x))
         printf("Yes\n");
        else
         printf("No\n");
    }
    return 0;
}
