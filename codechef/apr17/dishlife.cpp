//Problem URL : https://www.codechef.com/APRIL17/problems/DISHLIFE

***********************************************************************************************************************************

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int cnt[100010];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,k,i,j,p,c,x,skip,fl;
    cin>>t;
    while(t--){
        cin>>n>>k;
        skip=fl=0;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++){
            cin>>p;
            c=0;
            for(j=0;j<p;j++){
                cin>>x;
                if(cnt[x]==0)
                 cnt[x]=1;
                else
                 c++;
            }
            if(c==p)
             skip=1;
        }
        for(i=1;i<=k;i++)
        {
            if(cnt[i]==0)
            {
                fl=1;
                break;
            }
        }
        if(fl==1)
         cout<<"sad\n";
        else
        {
            if(skip)
             cout<<"some\n";
            else
             cout<<"all\n";
        }
    }
    return 0;
}
