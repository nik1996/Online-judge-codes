//Problem Link : http://www.spoj.com/problems/AMR10G/

**************************************************************************************************************************************

#include <iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
    long int t,n,k,i,d,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long int a[n];
        for(i=0;i<n;i++)
         cin>>a[i];
        sort(a,a+n);
        m=a[n-1];
        for(i=0;i<n-k+1;i++)
        {
            d=a[i+k-1]-a[i];
            if(d<m)
            m=d;
        }
        cout<<m<<"\n";
    }
    return 0;
}
