//Problem Link : http://www.spoj.com/problems/HANGOVER/

************************************************************************************************************************************

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int c,i;
    float n,s;
    while(1)
    {
        scanf("%f",&n);
        if(n==0.00)
        break;
        s=0.00;
        c=0;
        for(i=2;i<280;i++)
        {
            s=s+((float)1/i);
            c++;
            //cout<<(float)1/i<<" ";
            //cout<<s<<" s\n";
            if(s>n)
            break;
        }
        printf("%d card(s)\n",c);
    }
    return 0;
}
