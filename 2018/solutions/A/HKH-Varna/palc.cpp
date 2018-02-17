#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string a;
    cin>>a;
    int d=a.size(),br=d;
    if(d==2)
    {
        if(a[0]==a[1])
            cout<<3;
        else
            cout<<2;
        return 0;
    }
    else
    {
        int i,f=0;
        for(i=0;i<d/2;i++)
        {
            if(a[i]==a[d-i-1])
                f++;
            else
                break;
        }
        if(f==d/2&&i==d/2)
        br++;
        cout<<br;

    }
    return 0;
}
