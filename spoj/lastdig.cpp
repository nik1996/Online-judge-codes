Problem statement : http://www.spoj.com/problems/LASTDIG/

*************************************************************************************************************************************

#include <iostream>

using namespace std;

void ans(int a,long long int b)
{
    int res=1;
    a=a%10;
    while(b>0)
    {
        if(b%2==1)
          res=(res*a)%10;
        b/=2;
        a=(a*a)%10;
    }
    cout<<res;
}
int main()
{
    int t,a;
    long long int b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ans(a,b);
        cout<<"\n";
    }
    return 0;
}
