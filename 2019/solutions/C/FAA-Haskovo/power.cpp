#include<iostream>

using namespace std;

int n,k;
int a[10025];

int maxNum[50];

int split(int x)
{
    int d=2;
    while (x!=1)
    {
        if(x%d==0)
        {
            int current=0;
            while(x%d==0)
            {
                x/=d;
                current++;
            }
            maxNum[d] = max(maxNum[d], current);
        }
        else
        {
            d++;
        }
    }
}

int main()
{
    long long ans = 1;

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        split(a[i]);
    }

    for(long long i=2;i<50;i++)
    {
        long long br=maxNum[i]/k;
        if(br*k<maxNum[i]) br++;

        for(int j=0;j<br;j++)
        {
            ans *= i;
        }
    }

    cout<<ans<<"\n";
}
