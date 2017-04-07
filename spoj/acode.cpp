//Problem Link:http://www.spoj.com/problems/ACODE/

********************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    string s;
    int v[5010],l,i;
    while(1)
    {
        cin>>s;
        if(s=="0")
        break;
        l=s.size();
        //cout<<l<<"L\n";
        memset(v,0,sizeof(int)*(l+5));
        v[l]=v[l+1]=v[l-1]=1;
        for(i=l-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                //i--;
                continue;
            }
            else if(s[i+1]=='0')
            {
                 v[i]=v[i+2];
                 //cout<<v[i]<<" "<<i<<"I\n";
            }
            else
            {
                if(((s[i]-48)*10+(s[i+1]-48))<=26&&s[i+2]!='0')
                 v[i]=v[i+1]+v[i+2];
                else
                 v[i]=v[i+1];
                //cout<<v[i]<<"I\n";
            }
        }
        printf("%d\n",v[0]);
    }
    return 0;
}
