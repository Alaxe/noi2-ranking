#include <iostream>
using namespace std;
int main()
{
    int n,x;
    bool cup0=false,cup1=false,cup2=false,z;
    cin>>n;
    cin>>x;
    switch(x)
    {
        case 0:cup0=true; break;
        case 1:cup1=true; break;
        case 2:cup2=true; break;
        default:cout<<"Error!"; goto end; break;
    }
    for (int i=1;i<=n;i++)
    {
        if ((i%2)==0)
        {
            z=cup1;
            cup1=cup2;
            cup2=z;
        }
        else
        {
            z=cup1;
            cup1=cup0;
            cup0=z;
        }
    }
    cout<<cup0<<" "<<cup1<<" "<<cup2<<endl;
    if(cup0=true) cout<<"0";
    if(cup1=true) cout<<"1";
    if(cup2=true) cout<<"2";

    end:
    return 0;
}
