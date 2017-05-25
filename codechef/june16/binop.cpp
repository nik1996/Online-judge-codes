//Problem URL : https://www.codechef.com/JUNE16/problems/BINOP

*********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
int main()
{
    long long int t,c,c0,c1,l,i,f0,f1;
    string a,b;
    scanf("%lld",&t);
    while(t--)
    {
        c=c0=c1=0;
        f0=f1=0;
        cin>>a>>b;
        l=a.length();
        for(i=0;i<l;i++)
        {
            if((a[i]!=b[i])&&a[i]=='0')
            c0++;
            else if((a[i]!=b[i])&&a[i]=='1')
            c1++;
            if(a[i]=='0')
            f0=1;
            if(a[i]=='1')
            f1=1;
        }
        //cout<<c0<<" c0"<<c1<<" c1\n";
        //if(c0==0||c1==0)
        //printf("Unlucky Chef\n");
        //else
        //{
            //if(c0==c1)
            //c=c0;
            //else
            c=min(c0,c1);
            if(c0>c1&&f1>0)
            c+=(c0-c1);
            else if(c1>c0&&f0>0)
            c+=(c1-c0);
            if(c==0)
            printf("Unlucky Chef\n");
            else
            printf("Lucky Chef\n%lld\n",c);
        //}
    }
    return 0;
}
