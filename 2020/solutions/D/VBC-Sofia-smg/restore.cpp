#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[n], b[n], nai_g=0;
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(long long i=n-1;i>=0;i--)
    {
        if(b[i]==0)
        {
            a[i]=nai_g;
        }
        else
        {
            a[i]=nai_g-b[i];
            for(long long j=i+1;j<n;j++)
            {
                if(a[i]<=a[j])
                {
                    a[j]++;
                }
            }
        }
        nai_g++;
    }
    for(int i=0;i<n;i++)
    {
        a[i]+=1;
        if(i!=0)
        {
            cout<<" ";
        }
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
