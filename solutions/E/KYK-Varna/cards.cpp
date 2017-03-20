#include<iostream>
using namespace std;
int main()
{
    int N,a[100001],b[100001],br=0,otg=0;
    cin>>N>>a[0]>>b[0];
    for(int i=1;i<N;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]<=a[i-1] && b[i]<=b[i-1])
        {
            br+=2;
        }
        else
        {
            if(otg<br)otg=br;
            br=0;
        }
    }
    if(otg<br)otg=br;
    cout<<otg<<"\n";
    return 0;
}
