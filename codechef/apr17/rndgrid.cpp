//Problem URL : https://www.codechef.com/APRIL17/problems/RNDGRID

//This will pass two subtasks.
**********************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
string s;
string mat[1010];
 
bool chk(int x,int y,int n)
{
    if(x<0||y>=n||x>=n||y<0||mat[x][y]=='#')
     return false;
    return true;
}
 
int sol(int i,int j,int l,int n)
{
    int x,y,cnt=0,ind=0;
    x=i;
    y=j;
    for(ind=0;ind<l;ind++)
    {
        if(s[ind]=='R')
        {
            if(chk(x,y+1,n)==false)
             break;
            else
            {
                y++;
                cnt++;
            }
        }
        else if(s[ind]=='L')
        {
            if(chk(x,y-1,n)==false)
             break;
            else
            {
                y--;
                cnt++;
            }
        }
        else if(s[ind]=='U')
        {
            if(chk(x-1,y,n)==false)
             break;
            else
            {
                x--;
                cnt++;
            }
        }
        else if(s[ind]=='D')
        {
            if(chk(x+1,y,n)==false)
             break;
            else
            {
                x++;
                cnt++;
            }
        }
    }
    return cnt;
}
 
int solve(int l,int n)
{
    int i,j,ans=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]=='.')
             ans=ans^sol(i,j,l,n);
        }
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,i,n,l;
    cin>>t;
    while(t--)
    {
        cin>>l>>n;
        cin>>s;
        for(i=0;i<n;i++)
        {
            cin>>mat[i];
        }
        cout<<solve(l,n)<<"\n";
    }
    return 0;
}
