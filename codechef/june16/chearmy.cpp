//Problem URL : https://www.codechef.com/JUNE16/problems/CHEARMY

**********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
 
using namespace std;
 
int main()
{
    long int t,r[20],a,x,p;
    unsigned long long int tmp,k,i;
    scanf("%ld",&t);
    while(t--)
    {
        memset(r,0,sizeof(r));
        scanf("%lld",&k);
        if(k==1)
        printf("0\n");
        else
        {
            tmp=k-1;
            p=a=0;
            while(tmp>0)
            {
              x=tmp%5;
              x*=2;
              r[p]+=a;
              if(x>10)
              {
              	a=x/10;
                x%=10;
              }
              else
              a=0;
              tmp/=5;
              r[p]+=x;
              p++;
            }
            if(a!=0)
            {
            	r[p]+=a;
            	p++;
            }
            for(i=p-1;i>=0;i--)
        	 {
        	     printf("%ld",r[i]);
        	    if(i==0)
        	    break;
        	 }
        	 printf("\n");
        }
    }
    return 0;
}
