#include <iostream>
using namespace std;

int main()
{

    int n,a=0,b=0,y=0,c=9999999,d=9999999,z=0,k=0;

    cin>>n;

    for(int x=1; x<n; x++)
    {

        c=a;
        d=b;

        cin>>a>>b;

        if((a<=c&&b<=d)||(a<=d&&b<=c))
        {
            y++;
        }
        else
        {
            y=0;
        }
        if((c<=a&&d<=b)||(d<=a&&c<=b))
        {
            k++;
        }
        else
        {
            k=0;
        }

        if(y>=z)
        {
            z=y;
        }
        if(k>=z)
        {
            z=k;
        }
        cout<<y<<" "<<k<<endl;
    }

    cout<<z<<endl;

    return 0;
}


