//Problem URL : https://www.codechef.com/APRIL16/problems/COLOR

*********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    int t,n,r,b,g,i,a;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s;
        r=b=g=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='R')
             r++;
            else if(s[i]=='B')
             b++;
            else if(s[i]=='G')
             g++;
        }
        if(r>=g&&r>=b)
         a=n-r;
        else if(g>=r&&g>=b)
         a=n-g;
        else if(b>=r&&b>=g)
         a=n-b;
        printf("%d\n",a);
    }
    return 0;
}
