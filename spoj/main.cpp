#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string a,b,c,d,e;
    int t,x,y;
    scanf("%d",&t);
    while(1)
    {
        if(t==0)
        break;
        cin>>a>>b>>c>>d>>e;
        if(a.empty())
        continue;
        else
        {
            t--;
            if((a.find("machula")==string::npos)&&(c.find("machula")==string::npos))
            {
                istringstream s(a,istringstream::in);
                istringstream q(c,istringstream::in);
                //s<<a;
                s>>x;
                //q<<c;
                q>>y;
                cout<<a<<" + "<<c<<" = "<<x+y<<"\n";
            }
            else
            {
                if(a.find("machula")!=string::npos)
                {
                    istringstream s(c,istringstream::in);
                    istringstream q(e,istringstream::in);
                    //s<<c;
                    s>>x;
                    //q<<e;
                    q>>y;
                    cout<<y-x<<" + "<<c<<" = "<<e<<"\n";
                }
                else if(c.find("machula")!=string::npos)
                {
                    istringstream s(a,istringstream::in);
                    istringstream q(e,istringstream::in);
                    //s<<a;
                    s>>x;
                    //q<<e;
                    q>>y;
                    cout<<a<<" + "<<y-x<<" = "<<e<<"\n";
                }
            }
        }
    }
    return 0;
}
