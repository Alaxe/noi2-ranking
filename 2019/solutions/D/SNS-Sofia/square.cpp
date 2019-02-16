#include<iostream>
using namespace std;
long long n;
bool b;
long long a[10010];
int main ()
{
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;1;i++)
    {
        b=true;
        for(long long j=0;j<n;j++)
        {
            if((i*i)%a[j]!=0)
            {
                b=false;
            }
        }
        if(b)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
