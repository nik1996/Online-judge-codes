Problem statement: http://www.spoj.com/problems/FASHION/

*************************************************************************************************************************************

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int t,n,x,sum,m[1010],w[1010],i;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(i=0;i<n;i++)
          cin>>m[i];
        for(i=0;i<n;i++)
          cin>>w[i];
        sort(m,m+n);
        sort(w,w+n);
        for(i=0;i<n;i++)
        {
            x=m[i]*w[i];
            sum=sum+x;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
