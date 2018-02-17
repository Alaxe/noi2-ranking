#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m[n];
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    int d;
    long long s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            d=m[j]-m[i];
            if(d>0)
            {
                s=(s+1)%123456789012345;
                for(int p=j+1;p<n;p++)
                {
                    if(m[p]-m[j]==d) s=(s+1)%123456789012345;
                }
            }
        }
    }
    cout<<s;
    return 0;
}
