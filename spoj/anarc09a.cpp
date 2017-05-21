//Problem URL :http://www.spoj.com/problems/ANARC09A/

*********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string s;
    long long int c=0,l,i,t=1,x=0,a;
    while(1)
    {
        cin>>s;
        if(s[0]=='-')
        break;
        c=x=0;
        l=s.length();
        for(i=0;i<l;i++)
        {
            if(s[i]=='{')
            {
            	c++;
            }
            else if(s[i]=='}')
            {
                if(c==0)
                {
                    x++;
                }
                else
                 c--;
            }
        }
        a=ceil((float)c/2)+ceil((float)x/2);
        printf("%lld. %lld\n",t,a);
        t++;
    }
    return 0;
}
