//Problem URL : https://www.codechef.com/APRIL17/problems/SIMDISH

***********************************************************************************************************************************

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
map <string,int> m;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,i,c;
    string s;
    cin>>t;
    while(t--){
        m.clear();
        c=0;
        for(i=0;i<4;i++)
        {
            cin>>s;
            m[s]=1;
        }
        for(i=0;i<4;i++)
        {
            cin>>s;
            if(m.find(s)!=m.end())
             c++;
        }
        if(c>=2)
         cout<<"similar\n";
        else
         cout<<"dissimilar\n";
    }
    return 0;
}
