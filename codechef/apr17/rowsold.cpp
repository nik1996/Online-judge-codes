//Problem URL : https://www.codechef.com/APRIL17/problems/ROWSOLD

*****************************************************************************************************************************************

#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,ones,lp,i,n;
    long long int ti;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        n=s.length();
        ones=0;
        lp=n-1;
        ti=0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='1'){
                if(i+1<n&&s[i+1]=='0')
                 ones++;
                ti+=ones;
                ti+=(lp-i);
                lp--;
            }
        }
        cout<<ti<<"\n";
    }
    return 0;
}
