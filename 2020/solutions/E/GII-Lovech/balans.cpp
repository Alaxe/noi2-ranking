#include <iostream>
using namespace std;
int main()
{
    int n,x=0,y=0,z=0;
    cin>>n;
    char k[n];
    for(int i=0; i<n; i++)
    {
        cin>>k[i];
        if(k[i]=='a'||k[i]=='b')
        {
            x++;
        }
        else y++;
        if(x==y)
        {
            z=i+1;
        }
    }
    cout<<z<<endl;

    return 0;
}
