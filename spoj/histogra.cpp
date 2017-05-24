//Problem URL : http://www.spoj.com/problems/HISTOGRA/

************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <stack>
 
using namespace std;
 
long long int a[100010];
int main()
{
    stack < long long int > s;
    long long int n,i,ans,m,e;
    while(1)
    {
        ans=-1;
        scanf("%lld",&n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
           scanf("%lld",&a[i]);
        i=0;
        while(i<n)
        {
            if(s.empty()||(a[i]>=a[s.top()]))
            {
                s.push(i);
                i++;
            }
            else
            {
                e=s.top();
                s.pop();
                m=a[e]*(s.empty()? i : (i-1-s.top()));
                if(m>ans)
                 ans=m;
            }
        }
        while(s.empty()==false)
        {
            e=s.top();
            s.pop();
            m=a[e]*(s.empty()? i : (i-1-s.top()));
            if(m>ans)
             ans=m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
