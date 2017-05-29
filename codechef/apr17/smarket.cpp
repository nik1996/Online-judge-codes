//Problem URL : https://www.codechef.com/APRIL17/problems/SMARKET

************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int a[100010],len[1000010],d[1000010];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,q,i,l,r,k,fl,ma;
    int ans=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++)
         cin>>a[i];
        len[n]=1;
        d[n]=1;
        ma=1;
        fl=0;
        for(i=n-1;i>=1;i--)
        {
            if(a[i]==a[i+1])
             {
                 len[i]=len[i+1]+1;
                 d[i]=d[i+1];
                 ma=max(ma,len[i]);
                 fl=1;
             }
            else
             {
                 len[i]=1;
                 d[i]=d[i+1]+1;
             }
        }
        while(q--)
        {
            ans=0;
            cin>>l>>r>>k;
            if((fl==0&&k>1)||(fl==1&&k>ma))
            {
                cout<<"0\n";
                continue;
            }
            else if(fl==0&&k==1){
                cout<<r-l+1<<"\n";
                continue;
            }
            else if(k==1)
            {
                cout<<d[l]-d[r]+1<<"\n";
                continue;
            }
            else
            {
                for(i=l;i<=r;)
                {
                   if(len[i]>=k)
                   {
                       if(i+len[i]-1<=r)
                       {
                     	  ans++;
                       }
                       else
                       {
                          if(len[i]-len[r]+1>=k)
                            ans++;
                       }
                   }
                   i=i+len[i];
                }
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
