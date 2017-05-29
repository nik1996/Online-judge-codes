//Problem URL : https://www.codechef.com/APRIL17/problems/CHEFDIV

//This will pass two subtasks.
**************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define mp make_pair
 
using namespace std;
 
vector <long long int> v1,v2;
map <long long int ,long long int> m;
 
long long int rec()
{
    //sort(v.begin(),v.end());
    m[1]=1;
    long long int cnt,ans,ma;
    cnt=ans=0;
    ma=1;
    int i,j;
    for(i=1;i<v1.size();i++)
    {
        ans=cnt=0;
        if(m.find(v1[i])!=m.end())
        {
            ma=max(ma,m[v1[i]]);
            continue;
        }
        for(j=0;j<i;j++)
        {
            if(v1[i]%v1[j]==0)
            {
                cnt++;
               // cout<<v[j]<<"H\n";
                ans=max(ans,m[v1[j]]);
            }
        }
        m[v1[i]]=cnt+1+ans;
        //cout<<v[i]<<"I"<<m[v[i]]<<"c"<<ans<<"\n";
        ma=max(ma,m[v1[i]]);
    }
    for(i=v2.size()-1;i>=0;i--)
    {
    	ans=cnt=0;
        if(m.find(v2[i])!=m.end())
        {
            ma=max(ma,m[v2[i]]);
            continue;
        }
    	for(j=0;j<v1.size();j++)
    	{
    		if(v2[i]%v1[j]==0)
            {
                cnt++;
               // cout<<v[j]<<"H\n";
                ans=max(ans,m[v1[j]]);
            }
    	}
    	for(j=v2.size()-1;j>i;j--)
        {
            if(v2[i]%v2[j]==0)
            {
                cnt++;
               // cout<<v[j]<<"H\n";
                ans=max(ans,m[v2[j]]);
            }
        }
        m[v2[i]]=cnt+1+ans;
        //cout<<v[i]<<"I"<<m[v[i]]<<"c"<<ans<<"\n";
        ma=max(ma,m[v2[i]]);
    }
    return ma;
}
 
long long int solve(long long int n)
{
    v1.clear();
    v2.clear();
    int cnt=0;
    if(m.find(n)!=m.end())
     return m[n]-1;
    int i;
    for(i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cnt++;
            v1.pb(i);
            if(n/i!=i&&i!=1)
            {
                cnt++;
                v2.pb(n/i);
            }
        }
    }
    m[n]=cnt+1+rec();
    return m[n]-1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int ans,a,b,i;
    cin>>a>>b;
    ans=0;
    for(i=b;i>=a;i--)
    {
        ans+=solve(i);
        //cout<<ans<<"H\n";
    }
    cout<<ans<<"\n";
    return 0;
} 
