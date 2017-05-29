//Problem URL : https://www.codechef.com/APRIL17/problems/DGTCNT

//This will pass one subtask.
************************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
int a[11],cnt[20];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,fl=0,x,j;
    long long int l,r,i,tmp,ans;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        for(j=0;j<=9;j++)
        {
            cin>>a[j];
        }
        ans=0;
        for(i=l;i<=r;i++)
        {
            memset(cnt,0,sizeof(cnt));
            fl=1;
            tmp=i;
            while(tmp>0)
            {
                x=tmp%10;
                tmp/=10;
                cnt[x]++;
            }
            for(j=0;j<=9;j++)
            {
                if(cnt[j]==a[j])
                 fl=0;
            }
            if(fl)
             ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
