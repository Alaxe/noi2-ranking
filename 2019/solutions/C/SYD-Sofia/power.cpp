#include<iostream>

using namespace std;

int main()
{
    int n,k,a[10000];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int del[43];
    for(int i=0;i<n;i++)
    {
        while(a[i]>1)
        {
            for(int j=2;;j++)
            {
                if(a[i]%j==0)
                {
                    a[i]/=j;
                    del[j]++;
                    break;
                }
            }
        }
    }
    int ans=1;
    for(int i=2;i<43;i++)
    {
        if(del[i]>0)
        {
            if(del[i]%k==0)
            {
                ans*=i*del[i]/k;
            }else
            {
                ans*=i*(del[i]/k+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
