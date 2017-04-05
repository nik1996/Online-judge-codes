#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    long int n,x,l,a[210],i;
    char s[210];
    while(1)
    {
        cin>>n;
        x=1;
        if(n==0)
         break;
        scanf("%s",s);
        l=strlen(s);
        for(i=0;i<l;)
        {
            a[i]=x;
            x++;
            i++;
            if(x==n)
            {
                a[i]=n;
                i++;
                while(x>0)
                {
                    a[i]=x;
                    x--;
                    i++;
                }
                x=1;
            }

        }
        /*for(i=0;i<l;i++)
         cout<<a[i]<<" ";*/
        x=1;
        i=0;
        while(x<=n)
        {
            if(a[i]==x)
            cout<<s[i];
            //else
            i++;
            if(i==l)
            {
                x++;
                i=0;
            }
        }
        cout<<"\n";
    }
    return 0;
}
